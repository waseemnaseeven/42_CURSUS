#include "../includes/Server.hpp"

bool send_message(t_serv *server, const string& message, int sender_fd) 
{
	// string tmp = message;
	(void) server;
	// if (tmp.size() > 510)
	// 	tmp = tmp.substr(0, 510) + "\r\n";
	send(sender_fd, message.c_str(), message.size(), 0);
	cout << "message sent: " << message << endl;
	return true;
}