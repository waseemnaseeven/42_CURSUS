/* eslint-disable */

import React, { FormEvent, useEffect, useRef, useState } from 'react';
import Messages from './Messages.tsx';
import './chat.css';
import useAuth from '../../contexts/Auth/useAuth.tsx';
import toast, { Toaster } from 'react-hot-toast';
import userServices from '../../services/user';
import { User } from '../../utils/types';
import { useNavigate, useParams } from 'react-router-dom';
import Popup from './Popup.tsx';
import { io } from 'socket.io-client';
import axios from 'axios';
import Search from '../Search/Search.tsx';
import { ChannelType } from '../../utils/types';
interface InputBarProps {
  socketRef: any;
  user: any;
  channelName: string;
}

interface MemberInfo {
  login: string;
  avatar: string;
}

interface MessageInfo {
  id: number;
  createdAt: any;
  userId: number;
  channelId: number;
  content: string;
  member: MemberInfo;
}

const InputBar = ({ socketRef, user, channelName }: InputBarProps) => {
  const [message, setMessage] = useState<string>('');

  const handleSubmit: React.FormEventHandler<HTMLFormElement> = (
    e: FormEvent,
  ) => {
    e.preventDefault();
    if (/\S/.test(message)) {
      socketRef.current.emit('chatSend', {
        user: user,
        channelName: channelName,
        message: message,
      });
      setMessage('');
    }
  };

  return (
    <form className="input-bar" onSubmit={handleSubmit}>
      <input
        className="input-text"
        type="text"
        autoComplete="off"
        autoFocus
        value={message}
        onChange={(e) => {
          setMessage(e.target.value);
        }}
      />
      <button className="input-button">Send</button>
    </form>
  );
};

const ChatRoom = () => {
  const { channelName } = useParams();
  const { user } = useAuth();
  const navigate = useNavigate();

  const socketRef = useRef<any>(null);
  const isOwnerRef = useRef<boolean>(false);
  const [isDual, setDual] = useState<boolean>(false);
  const [blockedUsers, setBlockedUsers] = useState<any[]>([]);
  const [channel, setChannel] = useState<any>(null);
  const [messages, setMessages] = useState<any[]>([]);
  const [invitedUser, setInvitedUser] = useState<string>('');
  const [buttonPopup, setButtonPopup] = useState<boolean>(false);
  const [newChannelPassword, setNewChannelPassword] = useState<string>('');
  const [userList, setUserList] = useState<User[]>([]);
  const [newChannelPrivate, setNewChannelPrivate] = useState<boolean>(false);

  useEffect(() => {
    const fetchData = async () => {
      const channel = await axios.get<ChannelType | null>(
        `http://localhost:5001/api/channels/${channelName}/${user.intraId}/check`,
      );
      if (channel?.data) {
        setChannel(channel?.data);
        setNewChannelPrivate(channel?.data?.private);
      } else navigate('/chat');

      setBlockedUsers(
        (await axios.get(`http://localhost:5001/api/users/${user.id}/blocked`))
          .data,
      );
      setMessages(
        (
          await axios.get(
            `http://localhost:5001/api/channels/${channelName}/messages`,
          )
        ).data,
      );
      isOwnerRef.current = (
        await axios.get(
          `http://localhost:5001/api/channelMembers/${channelName}/${user.intraId}`,
        )
      ).data.isOwner;
      console.log(
        (
          await axios.get(
            `http://localhost:5001/api/channels/${channelName}/isDual`,
          )
        ).data,
      );
      setDual(
        (
          await axios.get(
            `http://localhost:5001/api/channels/${channelName}/isDual`,
          )
        ).data,
      );
    };
    if (user.id) fetchData();

    socketRef.current = io('http://localhost:5001/chat');
    socketRef.current.emit('chatJoin', {
      intraId: user.intraId,
      channelName: channelName,
    });
    socketRef.current.on(
      'chatReceive',
      (payload: { newMessage: MessageInfo }) => {
        setMessages((prevMessages) => [...prevMessages, payload.newMessage]);
      },
    );
    socketRef.current.on('chatKick', (payload: { intraIdToKick: number }) => {
      if (payload.intraIdToKick === user.intraId) {
        navigate('/chat');
      }
    });

    return () => {
      socketRef.current.disconnect();
    };
  }, [user]);

  const hookUserList = () => {
    userServices
      .getAll()
      .then((usersListResponse) => {
        setUserList(usersListResponse);
      })
      .catch((error) => {
        console.error(error);
      });
  };
  useEffect(hookUserList, []);

  useEffect(() => {
    console.log('invitedUser : ', invitedUser);
  }, [invitedUser]);

  const handleAdd = async (e: any) => {
    e.preventDefault();
    console.log(' handleAdd invitedUser : ', invitedUser);
    if (invitedUser !== '') {
      try {
        await axios.post(`http://localhost:5001/api/channels/addMember`, {
          user: invitedUser,
          channelName: channelName,
        });
        setInvitedUser('');
        toast.success('Member successfully added');
        setButtonPopup(false);
      } catch (error) {
        toast.error('Member addition failed');
        console.error(error);
      }
    }
  };
  const handleSubmit: any = (e: any) => {
    e.preventDefault();
    axios.patch(`http://localhost:5001/api/channels/${channelName}/update`, {
      intraId: user.intraId,
      newPassword: newChannelPassword,
      newPrivate: newChannelPrivate,
    });
    setButtonPopup(false);
    toast.success('Channel updated');
  };

  return (
    <div className="page">
      <div className="banner">
        <input type="button" value="←" onClick={() => navigate('/chat')} />
        <h3>{channelName}</h3>
        {isDual && (
          <input
            type="button"
            value="⚔️"
            onClick={() =>
              navigate('/game', {
                state: { isPrivate: true, isHost: true, key: channelName },
              })
            }
          />
        )}
        {/* <input type="button" value="→" onClick={() => navigate("/game", {state: {isPrivate: true, isHost: false, key: "cest un test"}})}/> */}

        {/* // 	  <input type="button" value="←" onClick={() => navigate("/game", {state: {isPrivate: true, isHost: true, key: "CEST LA CLE"}})}/> */}

        {isOwnerRef.current && (
          <input
            type="button"
            value="⚙️"
            onClick={() => setButtonPopup(!buttonPopup)}
          />
        )}
      </div>
      <Messages
        userSocketRef={socketRef}
        messages={messages}
        blockedUsers={blockedUsers}
      />
      <InputBar
        socketRef={socketRef}
        user={user}
        channelName={channelName !== undefined ? channelName : ''}
      />
      {channel?.isDual === false && (
        <Popup
          className="option"
          trigger={buttonPopup}
          setTrigger={setButtonPopup}
          x="30px"
          y="75px"
        >
          <h4 className="option-title">Channel option</h4>
          <form className="option-form" onSubmit={handleSubmit}>
            <input
              type="text"
              placeholder="New password"
              value={newChannelPassword}
              onChange={(e) => {
                setNewChannelPassword(e.target.value);
              }}
            />
            <div className="option-form-end">
              Private:{' '}
              <input
                type="checkbox"
                checked={newChannelPrivate}
                onChange={() => setNewChannelPrivate(!newChannelPrivate)}
              />
              <br />
              <input type="button" value="Update" onClick={handleSubmit} />
            </div>
            <h4>Add Members</h4>
            <Search
              placeholder="Search"
              searchValue={invitedUser}
              setSearchValue={setInvitedUser}
              userList={userList}
              redirect={false}
            />
            <button onClick={handleAdd}>Add</button>
          </form>
        </Popup>
      )}
      <Toaster position="top-center" reverseOrder={false} />
    </div>
  );
};

export default ChatRoom;
