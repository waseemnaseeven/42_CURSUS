#include "../includes/Server.hpp"
#include "../includes/User.hpp"
#include "../includes/messages.hpp"

bool	PING_command(t_serv *server, const string& args, int sender_fd)
{
	if (server->users_map[sender_fd]->get_isAuthentified() == false)
	{
		if (args.empty())
			send_message(server, PING(int_to_string(sender_fd), ""), sender_fd);
		else
			send_message(server, PING(int_to_string(sender_fd), args), sender_fd);
	}
	else
	{
		if (args.empty())
			send_message(server, PONG(int_to_string(sender_fd), ""), sender_fd);
		else
			send_message(server, PONG(int_to_string(sender_fd), args), sender_fd);
	}
	return true;
}
