#include "../includes/Server.hpp"
#include "../includes/User.hpp"
#include "../includes/messages.hpp"

bool	PING_command(t_serv *server, const string& args, int sender_fd)
{
	if (server->users_map[sender_fd]->get_isAuthentified() == false)
	{
		if (args.empty())
			send_message(server, PING(user_id(server->users_map[sender_fd]->get_nickname(), server->users_map[sender_fd]->get_username(), "localhost"), ""), sender_fd);
		else
			send_message(server, PING(user_id(server->users_map[sender_fd]->get_nickname(), server->users_map[sender_fd]->get_username(), "localhost"), args), sender_fd);
	}
	else
	{
		if (args.empty())
			send_message(server, PONG(user_id(server->users_map[sender_fd]->get_nickname(), server->users_map[sender_fd]->get_username(), "localhost"), ""), sender_fd);
		else
			send_message(server, PONG(user_id(server->users_map[sender_fd]->get_nickname(), server->users_map[sender_fd]->get_username(), "localhost"), args), sender_fd);
	}
	return true;
}
