#include "../includes/Server.hpp"
#include "../includes/User.hpp"
#include "../includes/messages.hpp"

string get_comment(const string& args)
{
	string comment;
	for (size_t i = 0; i < args.size(); i++) {
		if (args[i] == ':') {
			comment = args.substr(i + 1);
			break;
		}
	}
	return comment;
}

string get_nickname(const string& args)
{
	string nickname;
	size_t i = 0;
	while (i < args.size() && args[i] != ' ')
		i++;
	i++;
	while (i < args.size() && args[i] != ' ') {
		nickname += args[i];
		i++;
	}
	return nickname;
}

User* getUser(string channel_name, string nick, t_serv *server)
{
    User *myUser;

	vector<int> user_fds = server->channels[channel_name]->get_users();
    for (vector<int>::iterator user_begin = user_fds.begin(); user_begin != user_fds.end(); ++user_begin)
    {
		int user_fd = *user_begin;
        myUser = server->users_map.at(user_fd);
        if (nick == myUser->get_nickname())
            return myUser;
    }
    return NULL;
}

bool    KICK_command(t_serv *server, const string& args, int sender_fd)
{
	string channel_name = get_channel_name(args);
	string nickname = get_nickname(args);
	string comment = get_comment(args);
	User *target_user = getUser(channel_name, nickname, server);

	if (target_user == NULL) {
		send_message(server, ERR_NOSUCHNICKCHANNEL(nickname), sender_fd);
		return false;
	}
	if (channel_name.empty() || nickname.empty()) {
		send_message(server, ERR_NEEDMOREPARAMS(int_to_string(sender_fd), "KICK"), sender_fd);
		return false;
	}
	if (server->channels[channel_name]->get_channel_name() != channel_name) {
		send_message(server, ERR_NOSUCHCHANNEL(target_user->get_nickname(), channel_name), sender_fd);
		return false;
	}
	if (server->channels[channel_name]->is_user(target_user->get_fd()) == false) {
		send_message(server, ERR_NOTONCHANNEL(channel_name, target_user->get_nickname()), sender_fd);
		return false;
	}
	if (server->channels[channel_name]->is_op(sender_fd) == false && server->users_map[sender_fd]->get_isOperator() == false) {
		send_message(server, ERR_CHANOPRIVSNEEDED(server->users_map[sender_fd]->get_nickname(), channel_name), sender_fd);
		return false;
	}
	if (server->channels[channel_name]->is_user(sender_fd) == false) {
		send_message(server, ERR_USERNOTINCHANNEL(nickname, channel_name), sender_fd);
		return false;
	}
	if (comment != "")
		server->channels[channel_name]->broadcast(":" + target_user->get_nickname() + "!" + server->users_map[sender_fd]->get_nickname() + "localhost" + " KICK " + channel_name + " " + nickname + "\r\n", sender_fd);
	else
		server->channels[channel_name]->broadcast(":" + target_user->get_nickname() + " KICK " + channel_name + " " + nickname + " :" + comment + "\r\n", sender_fd);
	server->channels[channel_name]->kick_user(target_user->get_fd());
	return true;
}
