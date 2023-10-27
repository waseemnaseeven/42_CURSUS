#include "../includes/Server.hpp"
#include "../includes/User.hpp"
#include "../includes/messages.hpp"

string	get_name(string args)
{
	string name;
	size_t i = 0;
	while (args[i] != ' ' && i < args.size())
	{
		name += args[i];
		i++;
	}
	return name;
}

string 	get_password(string args)
{
	string passwd;
	size_t i = 0;
	while (args[i] != ' ' && i < args.size())
		i++;
	i++;
	while (i < args.size())
	{
		passwd += args[i];
		i++;
	}
	return passwd;
}

bool	OPER_command(t_serv *server, const string& args, int sender_fd)
{
	string name = get_name(args);
	string passwd = get_password(args);

	if (args.empty() || args.size() < 2) {
		send_message(server, ERR_NEEDMOREPARAMS(int_to_string(sender_fd), "OPER"), sender_fd);
		return false;
	}
	if (server->users_map[sender_fd]->get_isAuthentified() == true)
	{
		if (name != server->users_map[sender_fd]->get_nickname() || passwd != server->_passwd)
		{
			send_message(server, ERR_PASSWDMISMATCH(int_to_string(sender_fd)), sender_fd);
			return false;
		}
		else
		{
			server->users_map[sender_fd]->set_isOperator(true);
			send_message(server, RPL_YOUREOPER(server->users_map[sender_fd]->get_nickname()), sender_fd);
			server->operator_fds.push_back(sender_fd);
			return true;
		}
	}
	return false;
}
