import { useEffect } from 'react';
import { useNavigate } from 'react-router-dom';
import { Socket } from 'socket.io-client';
import { UserStatus, ServerToClientEvents, ClientToServerEvents } from '../utils/types';
import useAuth from '../contexts/Auth/useAuth';
import authServices from '../services/auth';

interface LogoutProps {
  socket: Socket<ServerToClientEvents, ClientToServerEvents> | undefined,
}

function Logout({ socket }: LogoutProps) {
  const navigate = useNavigate();
  const { user, setLoggedIn } = useAuth();

  useEffect(() => {
    const performLogout = async () => {
      try {
        await authServices.logoutUser(user);
        if (socket !== undefined) {
          socket.emit('message', { id: user.id, status: UserStatus.LOGOUT });
          socket.disconnect();
        }

        setLoggedIn(false);
        localStorage.removeItem('userLogin');
        localStorage.removeItem('token');

        navigate('/login');
      } catch (error: unknown) {
        if (error instanceof Error) {
          console.error(error.message);
        } else {
          console.error('Error during disconnection:', error);
        }

        navigate('/login');
      }
    };

    performLogout();
  }, [navigate, setLoggedIn, socket, user]);

  return <> </>;
}

export default Logout;
