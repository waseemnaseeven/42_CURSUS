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

bool    KICK_command(t_serv *server, const string& args, int sender_fd)
{
	User *target_user = server->users_map[sender_fd];
	string channel_name = get_channel_name(args);
	cout << "channel_name: " << channel_name << endl;
	string nickname = get_nickname(args);
	cout << "nickname:'" << nickname << "'" << endl;
	string comment = get_comment(args);
	cout << "'" << comment << "'" << endl;

	if (channel_name.empty() || nickname.empty()) {
		send_message(server, ERR_NEEDMOREPARAMS(int_to_string(sender_fd), "KICK"), sender_fd);
		return false;
	}
	if (server->channels[channel_name]->get_channel_name() != channel_name) {
		send_message(server, ERR_NOSUCHCHANNEL(target_user->get_nickname(), channel_name), sender_fd);
		return false;
	}
	if (server->channels[channel_name]->is_user(sender_fd) == false) {
		send_message(server, ERR_NOTONCHANNEL(channel_name, target_user->get_nickname()), sender_fd);
		return false;
	}
	if (server->channels[channel_name]->is_op(sender_fd) == false) {
		send_message(server, ERR_CHANOPRIVSNEEDED(target_user->get_nickname(), channel_name), sender_fd);
		return false;
	}
	// if (server->users_map[sender_fd]->get_nickname() != nickname) {
	// 	send_message(server, ERR_NOSUCHNICKCHANNEL(nickname), sender_fd);
	// 	return false;
	// }
	if (server->channels[channel_name]->is_user(server->users_map[sender_fd]->get_fd()) == false) {
		send_message(server, ERR_USERNOTINCHANNEL(nickname, channel_name), sender_fd);
		return false;
	}
	if (comment != "")
		server->channels[channel_name]->broadcast(":" + target_user->get_nickname() + " KICK " + channel_name + " " + nickname + "\r\n", sender_fd);
	else
		server->channels[channel_name]->broadcast(":" + target_user->get_nickname() + " KICK " + channel_name + " " + nickname + " :" + comment + "\r\n", sender_fd);

	server->channels[channel_name]->kick_user(target_user->get_fd());
	return true;
}
