#include "includes/Server.hpp"
#include "includes/Client.hpp"

using namespace std;

int main (int ac, char **av)
{
	if (ac != 3) {
		cout << PURPLE << "Usage: ./ircserv [port] [password]" << RESET << endl;
		return (1);
	}
	int port = atoi(av[1]);
	string pwd = av[2];
	// parsing av[1] and av[2] to int and string
	// if (!parsing(port, pwd))
	// {
	// 	cout << RED << "Error: port must be a number and password must be a string" << RESET << endl;
	// 	return (1);
	// }
	Server *server = new Server(port, pwd);
	// Client *client = new Client();
	// Channel *channel = new Channel();
	// Users *users = new Users();

	server->runIRC();

	delete server;
	// delete client;
	// delete channel;
	// delete users;
	return (0);
}
