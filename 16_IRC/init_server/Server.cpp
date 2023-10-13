#include "../includes/Server.hpp"
#include "../includes/User.hpp"

bool Open = true;

typedef map<int, User*> t_users;
t_users users_map;

Server::Server() {
	cout << BOLDGREEN << "Server Connection by default called... " << RESET << endl;
}

Server::Server(const string& port, const string& passwd) : _port(atoi(port.c_str())), _passwd(passwd) {
	cout << BOLDGREEN << "Server Connection with port " << _port << " and the passwd is '" << _passwd << "'" << RESET << endl;
}

Server::~Server() {
	cout << BOLDRED << "Server Disconnection from " << LOCAL_HOST << " with port " << _port << RESET << endl;
}

Server::Server(const Server& src) {
	cout << GREEN << "Server Copy constructor called for " << RESET << endl;
	*this = src;
}

Server& Server::operator=(const Server& src) {
	cout << GREEN << "Server Assignation operator called" << RESET << endl;
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

void Server::runIRC()
{
	t_serv 	server = {};
	struct sigaction sa = {};

	// memset(&server, 0, sizeof(server));
	// memset(&sa, 0, sizeof(sa));

	cout << BOLDMAGENTA <<"Initializing server..." << RESET << endl;

	if (!initServer(&server))
		clear_data(&server);

	sa.sa_handler = signal_handler;
	sa.sa_flags = SA_RESTART; // restart system calls
	sigemptyset(&sa.sa_mask); // while signal handler is executing, block other signals
	if (sigaction(SIGINT, &sa, NULL) < 0)
		clear_data(&server);

	cout << BOLDMAGENTA <<"Initializing client..." << RESET << endl;

	initClients(&server);

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
	server->serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server->serv_addr.sin_port = htons(_port);

	if (bind(server->serv_fd, (struct sockaddr *)&server->serv_addr,
				sizeof(server->serv_addr)) < 0)
		return false;

	server->size = sizeof(server->serv_addr);

	if (listen(server->serv_fd, MAX_EVENTS) < 0)
		return false;

	return true;
}

void Server::initClients(t_serv *server)
{
	server->epoll.fd = epoll_create1(0);
	if (server->epoll.fd < 0)
        clear_data(server);
	server->epoll.event.events = EPOLLIN;
    server->epoll.event.data.fd = server->serv_fd;
    if (epoll_ctl(server->epoll.fd, EPOLL_CTL_ADD, server->serv_fd, &server->epoll.event) < 0) {
        clear_data(server);
	}

	int	nb_events = 0;

	while (Open)
	{
		nb_events = epoll_wait(server->epoll.fd, server->epoll.events, MAX_EVENTS, -1);
		if (nb_events < 0)
			clear_data(server);
		for (int i = 0; i < nb_events; i++)
			clients_actions(server, i);
	}
}

void clients_actions(t_serv *server, int i)
{
    // Si un client se connecte au serveur alors connexion d'un User
    if (server->epoll.events[i].data.fd == server->serv_fd)
	{
		server->new_fd = 0;
		struct sockaddr_in socket_new_con = sockaddr_in();
		struct epoll_event event_new_con = epoll_event();
		socklen_t socket_new_con_len = sizeof(socket_new_con);
		static int user_id = 1;

		server->new_fd = accept(server->serv_fd, (struct sockaddr *)&socket_new_con, &socket_new_con_len);
		if (server->new_fd < 0)
			clear_data(server);

		User *new_user = new User(server->new_fd, user_id);
		users_map.insert(pair<int, User*>(server->new_fd, new_user));
		// print_map(users_map);
		server->open_fds.push_back(server->new_fd);
		// print_vector(server->open_fds);
		event_new_con.events = EPOLLIN | EPOLLRDHUP;
		event_new_con.data.fd = server->new_fd;
		// fcntl(server->new_fd, F_SETFL, O_NONBLOCK); // MacOnly
		if (epoll_ctl(server->epoll.fd, EPOLL_CTL_ADD, server->new_fd, &event_new_con) < 0)
			clear_data(server);
		++user_id;

		std::string welcome = "Welcome to the IRC server!\n";
		send(server->new_fd, welcome.c_str(), welcome.size(), 0);
	}
	else
	{
		cout << "Client request here" << endl;
		char buffer[1024];
		int sender_fd = server->epoll.events[i].data.fd;
		int bytes_read = recv(sender_fd, buffer, 1024, 0);

		if (bytes_read <= 0)
		{
			user_disconnection(server, sender_fd);
		}
		else
		{
			cout << "message" << endl;
		}
	}
}

void user_disconnection(t_serv *server, int disc_fd)
{
	cout << "user_disconnection" << endl;
	epoll_ctl(server->epoll.fd, EPOLL_CTL_DEL, disc_fd, &server->epoll.event);
	close(disc_fd);
	vector<int>::iterator it = server->open_fds.begin();
	vector<int>::iterator ite = server->open_fds.end();
	for (; it != ite; ++it)
	{
		if (*it == disc_fd)
		{
			cout << "user disconnected = " << disc_fd << " or it = " << *it << endl;
			server->open_fds.erase(it);
			break;
		}
	}
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
