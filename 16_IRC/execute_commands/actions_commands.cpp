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

void receive_byts(t_serv *server, int i)
{
    int sender_fd = server->epoll.events[i].data.fd;
    char buffer[BUFFERSIZE];

    int bytes_read = recv(sender_fd, buffer, BUFFERSIZE, 0);

    if (bytes_read <= 0)
        user_disconnection(server, sender_fd);
    else
    {
        string new_data(buffer, bytes_read);
        server->users_map[sender_fd]->append_partial_data(new_data);
        size_t pos;
        while ((pos = server->users_map[sender_fd]->get_partial_data().find("\r\n")) != string::npos)
        {

			string command = server->users_map[sender_fd]->get_partial_data().substr(0, pos + 2);
			vector<pair<string, string> > commands = server->users_map[sender_fd]->splitBuffer(command);
			execute_commands(server, commands, sender_fd);
			try {
				User *user = server->users_map.at(sender_fd);
				user->set_partial_data(user->get_partial_data().substr(pos + 2));
			}
			catch (const std::out_of_range& oor) {
				cerr << BOLDCYAN << "Inexistant user with fd: " << sender_fd << RESET << endl;
				break;
			}
        }
    }
}

void    execute_commands(t_serv *server, vector<pair<string, string> > commands, int sender_fd)
{
	print_commandsargs(commands);
    for (size_t i = 0; i < commands.size(); i++) {
        if (commands[i].first == "PASS"){
			if (PASS_command(server, commands[i].second, sender_fd) == false) {
				user_disconnection(server, sender_fd);
				break ;
			}
		}
        else if (commands[i].first == "NICK") {
			if (check_passwd(server, sender_fd) == false) {
				user_disconnection(server, sender_fd);
				break ;
			}
			NICK_command(server, commands[i].second, sender_fd);
		}
		else if (commands[i].first == "USER")
			USER_command(server, commands[i].second, sender_fd);
		else if (commands[i].first == "PING")
			PING_command(server, commands[i].second, sender_fd);
		else if (commands[i].first == "OPER")
			OPER_command(server, commands[i].second, sender_fd);
		else if (commands[i].first == "QUIT")
			QUIT_command(server, commands[i].second, sender_fd);
		else if (commands[i].first == "JOIN")
			JOIN_command(server, commands[i].second, sender_fd);
		else if (commands[i].first == "PRIVMSG")
			PRIVMSG_command(server, commands[i].second, sender_fd);
		else if (commands[i].first == "KICK")
			KICK_command(server, commands[i].second, sender_fd);
		else if (commands[i].first == "PART")
			PART_command(server, commands[i].second, sender_fd);
		else if (commands[i].first == "TOPIC")
			TOPIC_command(server, commands[i].second, sender_fd);
		else if (commands[i].first == "INVITE")
			INVITE_command(server, commands[i].second, sender_fd);
		else if (commands[i].first == "MODE")
			MODE_command(server, commands[i].second, sender_fd);
		else
			UNKNOWN_command(server, commands[i].first, sender_fd);
    }
}
