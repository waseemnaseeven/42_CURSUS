#include "../includes/Server.hpp"

Server::Server() {
	cout << GREEN << "Constructor by default called... " << RESET << endl;
}

Server::Server(const string& port, const string& passwd) : _port(atoi(port.c_str())), _passwd(passwd) {
	_serv_fd = -1;
	cout << GREEN << "Constructor with port " << _port << " and the passwd is '" << _passwd << "'" << RESET << endl;
}

Server::~Server() {
	cout << RED << "Destructor called for " << RESET << endl;
	if (this->_serv_fd != -1)
		close(_serv_fd);
}

Server::Server(const Server& src) {
	cout << GREEN << "Copy constructor called for " << RESET << endl;
	*this = src;
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
	t_epoll epoll;
	struct sigaction sa;

	memset(&epoll, 0, sizeof(epoll));
	memset(&sa, 0, sizeof(sa));
	cout << BOLDMAGENTA <<"Initializing server..." << RESET << endl;
	initServer(epoll);
	sa.sa_flags = SA_RESTART; // restart system calls
	sigemptyset(&sa.sa_mask); // while signal handler is executing, block other signals
	if (sigaction(SIGINT, &sa, NULL) == -1)
		throw Server::ServerException();
	cout << BOLDMAGENTA <<"Initializing client..." << RESET << endl;
	initClients(epoll);
}

void Server::initServer(t_epoll epoll)
{
	_opt = 1;
	(void) epoll;
	cout << CYAN <<"Creating socket..." << RESET << endl;

	_serv_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (_serv_fd < 0)
		throw runtime_error("Socket creation error");

	cout << CYAN <<"Server Socket connection created..." << RESET << endl;
	
	if (setsockopt(_serv_fd, SOL_SOCKET,
				SO_REUSEADDR | SO_REUSEPORT, &_opt,
				sizeof(_opt)))
		throw runtime_error("Setsockopt error");

	_serv_addr.sin_family = AF_INET;
	_serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	_serv_addr.sin_port = htons(_port);

	cout << CYAN <<"Binding..." << RESET << endl;

	if (bind(_serv_fd, (struct sockaddr *)&_serv_addr,
				sizeof(_serv_addr)) < 0)
		throw runtime_error("Bind failed");

	size = sizeof(_serv_addr);

	cout << CYAN << "Looking for client now... Listening..." << RESET << endl;

	if (listen(_serv_fd, MAX_EVENTS) < 0)
		throw runtime_error("Listen failed");

}

void Server::initClients(t_epoll epoll)
{
	epoll.fd = epoll_create1(EPOLL_CLOEXEC);
	if (epoll.fd < 0) 
        throw std::runtime_error("Epoll creation failed");
	epoll.event.events = EPOLLIN;
    epoll.event.data.fd = _serv_fd;
    if (epoll_ctl(epoll.fd, EPOLL_CTL_ADD, _serv_fd, &epoll.event) < 0) {
		close(epoll.fd);	
        throw std::runtime_error("Epoll control (add) failed");
	}

	_isOpen = true;
	int	nb_events = 0;

	while (_isOpen) {
		nb_events = epoll_wait(epoll.fd, epoll.events, MAX_EVENTS, -1);
		if (epoll.nb_events < 0)
			throw runtime_error("epoll_wait() failed");
		for (int i = 0; i < epoll.nb_events; ++i)
			clients_actions(epoll, i);		
	}
}

void Server::clients_actions(t_epoll epoll, int i)
{
	(void) epoll;
	(void) i;
	// if (epoll.events[i].data.fd == _serv_fd)
	_newsockfd = accept(_serv_fd, (struct sockaddr *)&_serv_addr,
			(socklen_t*)&size);
	if (_newsockfd < 0)
		throw runtime_error("Accept failed");
	cout << CYAN << "Client connected" << RESET << endl;
		cout << CYAN << "Waiting for client message..." << RESET << endl;
		_valread = recv(_newsockfd, _buffer, BUFFERSIZE, 0);
		if (_valread < 0)
			throw runtime_error("Read failed");
		cout << CYAN << "Client: " << _buffer << RESET << endl;
		if (strcmp(_buffer, "exit") == 0)
			return;
		cout << CYAN << "Enter message to client: " << RESET << endl;
		cin >> _buffer;
		send(_newsockfd, _buffer, strlen(_buffer), 0);
		if (strcmp(_buffer, "exit") == 0)
			return;
		
	// cout << CYAN << "Closing connection..." << RESET << endl;
	// close(_newsockfd);
	// if (shutdown(_serv_fd, SHUT_RDWR) < 0) 
	// 	throw runtime_error("Shutdown failed");
}