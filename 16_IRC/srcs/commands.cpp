#include "../includes/Server.hpp"
#include "../includes/Channel.hpp"
#include "../includes/User.hpp"

string  parse_msg(t_serv *server, string message, int sender_fd)
{
    (void) server;
    (void) sender_fd;
    if (message == "PASS\r\n")
        return ("PASS\r\n");
    // else if (message == "USER")
    //     return ();
    // else if (message == "NICK")
    //     return ();
    // else if (message == "JOIN")
    //     return ();
    // else if (message == "QUIT")
    //     return ();
    // // Operators channel check
    // else if (message == "KICK")
    //     return ();
    // else if (message == "INVITE")
    //     return ();
    // else if (message == 'MODE')
    //     return ();
    else
        return message;

}

string readMessage(t_serv *server, int sender_fd)
{

	(void) server;
	string 	res;
	char	buffer[BUFFERSIZE + 1];
	int		len_read;

	bzero(buffer, BUFFERSIZE + 1);
	len_read = read(sender_fd, buffer, BUFFERSIZE);
	if (len_read == -1)
		return "";
	buffer[len_read] = '\0';
	res.append(buffer);
	while (res.find("\r\n") == string::npos)
	{
		bzero(buffer, BUFFERSIZE + 1);
		len_read = read(sender_fd, buffer, BUFFERSIZE);
		if (len_read == -1)
			continue;
		if (len_read > 0)
		{
			buffer[len_read] = '\0';
			res.append(buffer);
		}
	}
	return res;
}

string readMessage2(t_serv *server, int sender_fd)
{
	char buffer[BUFFERSIZE] = {0};
	int len_read = read(sender_fd, buffer, BUFFERSIZE);
	if (len_read < 0)
		cout << "Error reading message" << endl;
	else if (len_read == 0)
	{
		cout << "User " << sender_fd << " disconnected" << endl;
		user_disconnection(server, sender_fd);
	}
	else
		cout << "Message received: " << buffer << endl;
	return string(buffer, len_read);
}


void	user_requests(t_serv *server, int i, Server *Server_class)
{
	(void) Server_class;
	// string message = readMessage(server, server->epoll.events[i].data.fd);
	// cout << "message1: " << message << endl;
	string message2 = readMessage2(server, server->epoll.events[i].data.fd);
	cout << "message2: " << message2 << endl;
	cout << "message read" << endl;
}
