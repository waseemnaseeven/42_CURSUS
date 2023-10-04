#include "includes/Server.hpp"

Server::Server() {
	cout << GREEN << "Constructor by default called... " << RESET << endl;
}

Server::Server(int port, string passwd) : _port(port), _passwd(passwd) {
	cout << GREEN << "Constructor with port " << _port << " and the passwd is '" << _passwd << "'" << RESET << endl;
}

Server::~Server() {
	cout << RED << "Destructor called for " << RESET << endl;

}

Server::Server(const Server& src) {
	*this = src;
	cout << GREEN << "Copy constructor called for " << RESET << endl;

}

Server& Server::operator=(const Server& src) {
	cout << GREEN << "Assignation operator called" << RESET << endl;
	if (this != &src) {
		// this->_value = src._value;
        // this->_str = src_str;
	}

	return *this;
}

void Server::runIRC()
{
	cout << CYAN <<"Initializing server..." << RESET << endl;
	initServer();
}

void Server::initServer()
{
	_opt = 1;
	_isExit = false;
	// _buffer[BUFFERSIZE] = {0};
	cout << CYAN <<"Creating socket..." << RESET << endl;
	// Creating socket file descriptor, AF_INET = IPv4, SOCK_STREAM = TCP, 0 = IP
	_serv_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (_serv_fd < 0) {
		cerr << RED << "Socket creation error" << RESET << endl;
		exit(EXIT_FAILURE);
	}

	cout << CYAN <<"Server Socket connection created..." << RESET << endl;

	// Forcefully attaching socket to the port 8080
	if (setsockopt(_serv_fd, SOL_SOCKET,
				SO_REUSEADDR | SO_REUSEPORT, &_opt,
				sizeof(_opt)))
	{
		cerr << RED << "setsockopt error" << RESET << endl;
		exit(EXIT_FAILURE);
	}

	_serv_addr.sin_family = AF_INET;
	_serv_addr.sin_addr.s_addr = htons(INADDR_ANY);
	_serv_addr.sin_port = htons(_port);

	cout << CYAN <<"Binding..." << RESET << endl;

	// Prends le nom (le fd) et le colle à une adresse IP
	if (bind(_serv_fd, (struct sockaddr *)&_serv_addr,
				sizeof(_serv_addr)) < 0)
	{
		cerr << RED << "bind failed" << RESET << endl;
		exit(EXIT_FAILURE);
	}

	size = sizeof(_serv_addr);

	cout << CYAN << "Looking for client now..." << RESET << endl;
	cout << CYAN <<"Listening..." << RESET << endl;

	// 1 = max number of pending connections for the socket
	if (listen(_serv_fd, 1) < 0)
	{
		cerr << RED << "listen failed" << RESET << endl;
		exit(EXIT_FAILURE);
	}

	_newsockfd = accept(_serv_fd, (struct sockaddr *)&_serv_addr,
			(socklen_t*)&size);
	if (_newsockfd < 0)
	{
		cerr << RED << "accept failed" << RESET << endl;
		exit(EXIT_FAILURE);
	}

	cout << CYAN << "Client connected" << RESET << endl;

	// while (1)
	// {
	// 	cout << CYAN << "Waiting for client message..." << RESET << endl;
	// 	_valread = read(_newsockfd, _buffer, BUFFERSIZE);
	// 	if (_valread < 0)
	// 	{
	// 		cerr << RED << "read failed" << RESET << endl;
	// 		exit(EXIT_FAILURE);
	// 	}
	// 	cout << CYAN << "Client: " << _buffer << RESET << endl;
	// 	if (strcmp(_buffer, "exit") == 0)
	// 		break;
	// 	cout << CYAN << "Enter message to client: " << RESET << endl;
	// 	cin >> _buffer;
	// 	send(_newsockfd, _buffer, strlen(_buffer), 0);
	// 	if (strcmp(_buffer, "exit") == 0)
	// 		break;
	// }
	// cout << CYAN << "Closing connection..." << RESET << endl;
	// close(_newsockfd);
	// shutdown(_serv_fd, SHUT_RDWR);

}
