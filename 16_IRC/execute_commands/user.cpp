#include "../includes/Server.hpp"
#include "../includes/User.hpp"
#include "../includes/messages.hpp"

string	get_username(string args)
{
	string username;
	size_t i = 0;
	while (args[i] != ' ' && i < args.size())
	{
		username += args[i];
		i++;
	}
	return username;
}

string	get_realname(string args)
{
	string realname;
	size_t i = 0;
	while (args[i] != ':' && i < args.size())
		i++;
	i++;
	while (i < args.size())
	{
		realname += args[i];
		i++;
	}
	return realname;
}

bool	USER_command(t_serv *server, const string& args, int sender_fd)
{
	string username = get_username(args);
	string realname = get_realname(args);

	/* Check si mot de pass incorrect */
	if (server->users_map[sender_fd]->get_hasPassword() == false) {
		if (server->users_map[sender_fd]->get_hasNickname() == true)
			send_message(server, ERR_NOPRIVILEGES(int_to_string(sender_fd)), sender_fd);
		return false;
	}
	if (args.empty()) {
		if (server->users_map[sender_fd]->get_hasUsername() == true)
			send_message(server, ERR_NEEDMOREPARAMS(int_to_string(sender_fd), "USER"), sender_fd);
		return false;
	}
	if (server->users_map[sender_fd]->get_hasUsername() == true)
	{
		send_message(server, ERR_ALREADYREGISTERED(int_to_string(sender_fd)), sender_fd);
		return false;
	}

	/* Set the username */
	server->users_map[sender_fd]->set_username(username);
	server->users_map[sender_fd]->set_realname(realname);
	server->users_map[sender_fd]->set_hasUsername(true);
	if (server->users_map[sender_fd]->get_hasNickname() == true && server->users_map[sender_fd]->get_hasPassword() == true && server->users_map[sender_fd]->get_isAuthentified() == false)
	{
		server->users_map[sender_fd]->set_isAuthentified(true);
		send_message(server, RPL_WELCOME(server->users_map[sender_fd]->get_nickname(), username, int_to_string(server->_port), LOCAL_HOST), sender_fd);
	}
	return true;
}
