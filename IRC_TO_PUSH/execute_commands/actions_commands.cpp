#include "../includes/Server.hpp"
#include "../includes/messages.hpp"

bool send_message(t_serv *server, const string& message, int sender_fd) 
{
	(void) server;
	string tmp = message;
	if (tmp.size() > 510)
		tmp = tmp.substr(0, 510) + "\r\n";
	send(sender_fd, tmp.c_str(), tmp.size(), 0);
	cout << BOLDBLUE << "message sent: " << tmp << RESET << endl;
	return true;
}

void	receive_byts(t_serv *server, int i)
{
		int sender_fd = server->epoll.events[i].data.fd;
		char buffer[BUFFERSIZE];
		int bytes_read = recv(sender_fd, buffer, BUFFERSIZE, 0);

		if (bytes_read <= 0)
			user_disconnection(server, sender_fd);
		else {
            string message(buffer, bytes_read);
            vector<pair<string, string> > commands = server->users_map[sender_fd]->splitBuffer(message);
            execute_commands(server, commands, sender_fd);
		}
}

void    execute_commands(t_serv *server, vector<pair<string, string> > commands, int sender_fd)
{
	/*
		- CTRL-N sur IRSSI
		- /rawlog open file pour voir ce que j'ai envoye
		- /connect DALNET 
	*/
	print_commandsargs(commands);
    for (size_t i = 0; i < commands.size(); i++) {
        if (commands[i].first == "PASS"){ // finish
			if (PASS_command(server, commands[i].second, sender_fd) == false) {
				user_disconnection(server, sender_fd);
				break ;
			}
		}
        else if (commands[i].first == "NICK") // finish 
		{
			if (check_passwd(server, sender_fd) == false) {
				user_disconnection(server, sender_fd);
				break ;
			}
			NICK_command(server, commands[i].second, sender_fd);
		}
		else if (commands[i].first == "USER") // finish
			USER_command(server, commands[i].second, sender_fd);
		else if (commands[i].first == "PING") // finish
			PING_command(server, commands[i].second, sender_fd);
		else if (commands[i].first == "OPER") // finish
			OPER_command(server, commands[i].second, sender_fd);
		else if (commands[i].first == "QUIT") // finish
			QUIT_command(server, commands[i].second, sender_fd);
		else if (commands[i].first == "JOIN") // finish
			JOIN_command(server, commands[i].second, sender_fd);
		else if (commands[i].first == "PRIVMSG")
			PRIVMSG_command(server, commands[i].second, sender_fd);
		else if (commands[i].first == "KICK") // finish
			KICK_command(server, commands[i].second, sender_fd);
		else if (commands[i].first == "PART") // finish
			PART_command(server, commands[i].second, sender_fd);
		else if (commands[i].first == "TOPIC") // finish
			TOPIC_command(server, commands[i].second, sender_fd);
		else if (commands[i].first == "INVITE")
			INVITE_command(server, commands[i].second, sender_fd);
		else if (commands[i].first == "MODE")
			MODE_command(server, commands[i].second, sender_fd);
		else
			UNKNOWN_command(server, commands[i].first, sender_fd);
    }
}
