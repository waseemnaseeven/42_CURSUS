#include "../includes/Server.hpp"
#include "../includes/User.hpp"
#include "../includes/messages.hpp"

Channel* getChannel(const string& channel_name, t_serv *server) {
    map<string, Channel*>::iterator it = server->channels.find(channel_name);
    if (it != server->channels.end())
        return it->second;
    else
        return NULL;
}

User* getUserFromIrssi(const string& nick, t_serv* server) {
    User* myUser = NULL;

    for (map<int, User*>::iterator it = server->users_map.begin(); it != server->users_map.end(); ++it) {
        myUser = it->second;
        if (nick == myUser->get_nickname()) {
            return myUser;
        }
    }
    return NULL;
}

bool    INVITE_command(t_serv *server, const string& args, int sender_fd)
{
    cout << "INVITE_command" << endl;
    string nickname = get_channel_name(args);
    cout << "invite nickname: " << nickname << endl;
    string channel_name = get_key(args);
    cout << "invite channel_name: " << channel_name << endl;

    if (args.empty() || nickname.empty() || channel_name.empty()) {
        send_message(server, ERR_NEEDMOREPARAMS(server->users_map[sender_fd]->get_nickname(), "INVITE"), sender_fd);
    return false;
    }

    Channel* myChannel = getChannel(channel_name, server);
    if (myChannel == NULL) {
        send_message(server, ERR_NOSUCHCHANNEL(server->users_map[sender_fd]->get_nickname(), channel_name), sender_fd);
        return false;
    }
    if (myChannel->is_user(sender_fd) == false) {
		send_message(server, ERR_NOTONCHANNEL(channel_name, nickname), sender_fd);
		return false;
	}
    User* target_user = getUserFromIrssi(nickname, server);
    if (target_user == NULL) {
        send_message(server, ERR_NOSUCHNICKCHANNEL(nickname), sender_fd);
        return false;
    }
    if (myChannel->get_is_invite_only() == true && (myChannel->is_op(sender_fd) == false || server->users_map[sender_fd]->get_isOperator() == false)) {
        send_message(server, ERR_CHANOPRIVSNEEDED(server->users_map[sender_fd]->get_nickname(), channel_name), sender_fd);
        return false;
    }
    if (myChannel->is_invited(target_user->get_fd())) {
        send_message(server, ERR_USERONCHANNEL(server->users_map[sender_fd]->get_nickname(), nickname, channel_name), sender_fd);
        return false;
    }
    // myChannel->broadcast(RPL_INVITING(user_id(server->users_map[sender_fd]->get_nickname(), server->users_map[sender_fd]->get_username(), "localhost"), server->users_map[sender_fd]->get_nickname(), target_user->get_nickname(), channel_name), target_user->get_fd());
    send_message(server, RPL_INVITING(user_id(server->users_map[sender_fd]->get_nickname(), server->users_map[sender_fd]->get_username(), "localhost"), server->users_map[sender_fd]->get_nickname(), target_user->get_nickname(), channel_name), sender_fd);
	myChannel->invite_user(target_user->get_fd());
	send_message(server, INVITE(user_id(server->users_map[sender_fd]->get_nickname(), server->users_map[sender_fd]->get_username(), "localhost"), target_user->get_nickname(), channel_name), sender_fd);
    // myChannel->broadcast(INVITE(user_id(server->users_map[sender_fd]->get_nickname(), server->users_map[sender_fd]->get_username(), "localhost"), nickname, channel_name), sender_fd);
    return true;
}