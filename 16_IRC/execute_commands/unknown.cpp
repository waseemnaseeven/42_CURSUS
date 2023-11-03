#include "../includes/Server.hpp"
#include "../includes/User.hpp"
#include "../includes/messages.hpp"

bool	UNKNOWN_command(t_serv *server, const string& command, int sender_fd)
{
	if (command == "CAP" || command.empty())
		return true;
	send_message(server, ERR_UNKNOWNCOMMAND(int_to_string(sender_fd), command), sender_fd);
	return false;
}
