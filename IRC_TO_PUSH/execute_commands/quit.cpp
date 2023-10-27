#include "../includes/Server.hpp"
#include "../includes/User.hpp"
#include "../includes/messages.hpp"

bool	QUIT_command(t_serv *server, const string& reason, int sender_fd)
{
	if (reason == ":leaving")
	{
		send_message(server, QUIT(server->users_map[sender_fd]->get_nickname(), reason), sender_fd);
		user_disconnection(server, sender_fd);
		// clear_data(server);
		return false;
	}
	return true;
}
