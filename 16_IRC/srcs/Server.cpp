#include "../includes/Server.hpp"
#include "../includes/User.hpp"

bool Open = true;

void runIRC(t_serv *server)
{
	cout << BOLDYELLOW << "Port is: " << server->_port << endl;
	cout << "Passwd is: " << server->_passwd << RESET << endl;
	struct sigaction sa = {};

	cout << BOLDMAGENTA <<"Initializing server..." << RESET << endl;
	if (!initServer(server))
		clear_data(server);

	sa.sa_handler = signal_handler;
	sa.sa_flags = SA_RESTART; // restart system calls
	sigemptyset(&sa.sa_mask); // while signal handler is executing, block other signals
	if (sigaction(SIGINT, &sa, NULL) < 0)
		clear_data(server);

	cout << BOLDMAGENTA <<"Initializing client..." << RESET << endl;

	initClients(server);
}

bool initServer(t_serv *server)
{
	server->opt = 1;

	server->serv_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server->serv_fd < 0)
		return false;

	if (setsockopt(server->serv_fd, SOL_SOCKET,
				SO_REUSEADDR | SO_REUSEPORT, &server->opt,
				sizeof(server->opt)) < 0)
		return false;

	server->serv_addr = sockaddr_in();
	server->serv_addr.sin_family = AF_INET;
	server->serv_addr.sin_port = htons(server->_port);
	server->serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(server->serv_fd, (struct sockaddr *)&server->serv_addr,
				sizeof(server->serv_addr)) < 0)
		return false;

	server->size = sizeof(server->serv_addr);

	if (listen(server->serv_fd, MAX_EVENTS) < 0)
		return false;

	return true;
}

void signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		Open = false;
	}
	else
	{
		cout << BOLDRED << "Signal not handled or ctrl + D" << RESET << endl;
	}
}

