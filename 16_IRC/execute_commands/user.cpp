#include "../includes/Server.hpp"
#include "../includes/User.hpp"
#include "../includes/messages.hpp"

bool    USER_command(t_serv *server, const string& username, int sender_fd)
{
	send_message(server, RPL_WELCOME(server->users_map[sender_fd]->get_nickname(), username, int_to_string(server->_port), LOCAL_HOST), sender_fd);

	return true;
}
