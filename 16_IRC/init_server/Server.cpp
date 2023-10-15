#include "../includes/Server.hpp"
#include "../includes/User.hpp"

bool Open = true;

Server::Server() {}

Server::Server(const string& port, const string& passwd) : _port(atoi(port.c_str())), _passwd(passwd) {
	cout << BOLDGREEN << "Server Connection with port " << _port << " and the passwd is '" << _passwd << "'" << RESET << endl;
}

Server::~Server() {
	cout << BOLDRED << "Server Disconnection from " << LOCAL_HOST << " with port " << _port << RESET << endl;
}

Server::Server(const Server& src) {	*this = src; }

Server& Server::operator=(const Server& src) {
	if (this != &src) {
		this->_port = src._port;
		this->_passwd = src._passwd;
	}
	return *this;
}

/* ********** GETTERS ********** */

int Server::get_port() const { return _port; }

string Server::get_passwd() const { return _passwd; }

/* ********** SETTERS ********** */

void Server::set_port(int port) { _port = port; }

void Server::set_passwd(const string& passwd) { _passwd = passwd; }

/* ********** SERVER METHODS ********** */

void Server::runIRC(Server *Server_class)
{
	t_serv server = {};
	struct sigaction sa = {};

	cout << BOLDMAGENTA <<"Initializing server..." << RESET << endl;

	if (!initServer(&server))
		clear_data(&server);

	sa.sa_handler = signal_handler;
	sa.sa_flags = SA_RESTART; // restart system calls
	sigemptyset(&sa.sa_mask); // while signal handler is executing, block other signals
	if (sigaction(SIGINT, &sa, NULL) < 0)
		clear_data(&server);

	cout << BOLDMAGENTA <<"Initializing client..." << RESET << endl;

	initClients(&server, Server_class);

	clear_data(&server);
}

bool Server::initServer(t_serv *server)
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
	server->serv_addr.sin_port = htons(_port);
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
}

std::ostream & operator<<(std::ostream & o, Server const & server) {
    o << "Port: " << server.get_port() << "\n";
    o << "Password: " << server.get_passwd() << "\n";
    return o;
}
