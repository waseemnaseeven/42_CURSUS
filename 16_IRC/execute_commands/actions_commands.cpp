#include "../includes/Server.hpp"

void	receive_byts(t_serv *server, int i)
{
		int sender_fd = server->epoll.events[i].data.fd;
		cout << "Client request here" << endl;
		char buffer[BUFFERSIZE];
        cout << "sender_fd: " << sender_fd << endl;
		int bytes_read = recv(sender_fd, buffer, BUFFERSIZE, 0);

		if (bytes_read <= 0)
			user_disconnection(server, sender_fd);
		else
		{
            string message(buffer, bytes_read);
            vector<pair<string, string> > commands = server->users_map[sender_fd]->splitBuffer(message);
            execute_commands(server, commands, sender_fd);
		}
}

void    execute_commands(t_serv *server, vector<pair<string, string> > commands, int sender_fd)
{
	print_commandsargs(commands);
    for (size_t i = 0; i < commands.size(); i++) {
        if (commands[i].first == "PASS"){
			if (PASS_command(server, commands[i].second, sender_fd) == false)
				user_disconnection(server, sender_fd);
		}
        else if (commands[i].first == "NICK") {
			NICK_command(server, commands[i].second, sender_fd);
        }
		else if (commands[i].first == "USER") {
			USER_command(server, commands[i].second, sender_fd);
		}
		else if (commands[i].first == "PING")
			PING_command(server, commands[i].second, sender_fd);
		else if (commands[i].first == "OPER")
			OPER_command(server, commands[i].second, sender_fd);
		else if (commands[i].first == "QUIT")
			QUIT_command(server, commands[i].second, sender_fd);
		// else
		// 	UNKNOWN_command(server, commands[i].first, sender_fd);
    }
}
