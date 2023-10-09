#include "../includes/Server.hpp"

Server::Server() {
	cout << GREEN << "Constructor by default called... " << RESET << endl;
}

Server::Server(const string& port, const string& passwd) : _port(atoi(port.c_str())), _passwd(passwd) {

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
	cout << CYAN <<"Initializing server..." << RESET << endl;
	initServer(epoll);
	// Here, maybe handle signals
	
	// Epoll && Clients handling
	cout << CYAN <<"Initializing client..." << RESET << endl;
	initClients(epoll);
}

void Server::initServer(t_epoll epoll)
{
	_opt = 1;
	(void) epoll;
	cout << CYAN <<"Creating socket..." << RESET << endl;

	// Creating socket file descriptor, AF_INET = IPv4, SOCK_STREAM = TCP, 0 = IP
	_serv_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (_serv_fd < 0)
		throw runtime_error("Socket creation error");

	cout << CYAN <<"Server Socket connection created..." << RESET << endl;

	// Forcefully attaching socket to the port 8080
	if (setsockopt(_serv_fd, SOL_SOCKET,
				SO_REUSEADDR | SO_REUSEPORT, &_opt,
				sizeof(_opt)))
		throw runtime_error("Setsockopt error");

	_serv_addr.sin_family = AF_INET;
	_serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	_serv_addr.sin_port = htons(_port);

	cout << CYAN <<"Binding..." << RESET << endl;

	// Prends le nom (le fd) et le colle à une adresse IP
	if (bind(_serv_fd, (struct sockaddr *)&_serv_addr,
				sizeof(_serv_addr)) < 0)
		throw runtime_error("Bind failed");

	size = sizeof(_serv_addr);

	cout << CYAN << "Looking for client now..." << RESET << endl;
	cout << CYAN <<"Listening..." << RESET << endl;

	// 1 = max number of pending connections for the socket
	if (listen(_serv_fd, 1) < 0)
		throw runtime_error("Listen failed");


}

void Server::initClients(t_epoll epoll)
{
	_isOpen = true;
	int	nb_events = 0;

	/* 
		epoll pour manipuler plusieurs clients 
		epoll_create1(EPOLL_CLOEXEC) crer un descrpteur de fichier
		CLO_EXEC indique aue le descripteur sera ferme automatiquement
		lorsqu'un exec est effectue dans le processus (utile pour eviter
		les fuites de descripteur)

		Vous ajoutez le descripteur de fichier du socket serveur à 
		l'instance epoll en utilisant epoll_ctl() avec EPOLL_CTL_ADD. 
		Vous spécifiez que vous souhaitez surveiller les événements 
		EPOLLIN, ce qui signifie que l'événement sera déclenché 
		lorsqu'il y a des données à lire sur le socket serveur.
	*/

	epoll.fd = epoll_create1(EPOLL_CLOEXEC);
	if (epoll.fd < 0) 
        throw std::runtime_error("Epoll creation failed");
	epoll.event.events = EPOLLIN;
    epoll.event.data.fd = _serv_fd;
    if (epoll_ctl(epoll.fd, EPOLL_CTL_ADD, _serv_fd, &epoll.event) < 0)
	{
		close(epoll.fd);	
        throw std::runtime_error("Epoll control (add) failed");
	}

	/*
		pour attendre des événements sur les descripteurs de fichiers
		surveillés par epoll. Cela bloquera jusqu'à ce qu'au moins 
		un événement se produise.
	*/

	while (_isOpen)
	{
		nb_events = epoll_wait(epoll.fd, epoll.events, MAX_EVENTS, -1);
		if (epoll.nb_events < 0)
			throw runtime_error("epoll_wait() failed");
		for (int i = 0; i < epoll.nb_events; ++i)
			server_actions(epoll, i);		
	}
}

void server_actions(t_epoll epoll, int i)
{
	(void) epoll;
	(void) i;
	return ;
}

// void followingfunction()
// {
// 		_newsockfd = accept(_serv_fd, (struct sockaddr *)&_serv_addr,
// 			(socklen_t*)&size);
// 	if (_newsockfd < 0)
// 		throw runtime_error("Accept failed");

// 	cout << CYAN << "Client connected" << RESET << endl;
// 		cout << CYAN << "Waiting for client message..." << RESET << endl;
// 		_valread = read(_newsockfd, _buffer, BUFFERSIZE);
// 		if (_valread < 0)
// 			throw runtime_error("Read failed");
// 		cout << CYAN << "Client: " << _buffer << RESET << endl;
// 		if (strcmp(_buffer, "exit") == 0)
// 			break;
// 		cout << CYAN << "Enter message to client: " << RESET << endl;
// 		cin >> _buffer;
// 		send(_newsockfd, _buffer, strlen(_buffer), 0);
// 		if (strcmp(_buffer, "exit") == 0)
// 			break;
// 	}
// 	cout << CYAN << "Closing connection..." << RESET << endl;
// 	close(_newsockfd);
// 	if (shutdown(_serv_fd, SHUT_RDWR) < 0) 
// 		throw runtime_error("Shutdown failed");
// }