#include "../includes/Server.hpp"

using namespace std;

int main (int ac, char **av)
{
	if (ac != 3) {
		cout << PURPLE << "Usage: ./ircserv [port] [password]" << RESET << endl;
		return (1);
	}
	string port = av[1];
	string pwd = av[2];
	if (!parsing(port, pwd))
	{
		cerr << RED << "Error: port must be a valid number and password must be a valid string" << RESET << endl;
		return (1);
	}
	Server *server = new Server(port, pwd);
	try {
		server->runIRC();
	}
	catch (std::exception &e) {
		cout << RED << e.what() << RESET << endl;
		delete server;
		return (1);
	}
	return (0);
}
