#include "../includes/Server.hpp"
#include "../includes/User.hpp"

void Server::initClients(t_serv *server, Server *Server_class)
{
    int	nb_events = 0;

	server->epoll.fd = epoll_create1(0);
	if (server->epoll.fd < 0)
        clear_data(server);
	server->epoll.event.events = EPOLLIN;
    server->epoll.event.data.fd = server->serv_fd;
    if (epoll_ctl(server->epoll.fd, EPOLL_CTL_ADD, server->serv_fd, &server->epoll.event) < 0) {
        clear_data(server);
	}

	while (Open)
	{
		nb_events = epoll_wait(server->epoll.fd, server->epoll.events, MAX_EVENTS, -1);
		if (nb_events < 0)
			clear_data(server);
		for (int i = 0; i < nb_events; i++)
			clients_actions(server, i, Server_class);
	}
}

void    clients_actions(t_serv *server, int i, Server *Server_class)
{
    (void) Server_class;
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
		server->users_map.insert(pair<int, User*>(server->new_fd, new_user));
		server->open_fds.push_back(server->new_fd);
		event_new_con.events = EPOLLIN | EPOLLRDHUP;
		event_new_con.data.fd = server->new_fd;
		// fcntl(server->new_fd, F_SETFL, O_NONBLOCK); // MacOnly
		if (epoll_ctl(server->epoll.fd, EPOLL_CTL_ADD, server->new_fd, &event_new_con) < 0)
			clear_data(server);
		++user_id;
        Hello_IRC(server);
    }
    int sender_fd = server->epoll.events[i].data.fd;
    else
	{
		cout << "user_requests" << endl;
        user_requests(server, i, Server_class);
	}
}

void    user_disconnection(t_serv *server, int disc_fd)
{
	cout << "user_disconnection" << endl;
	epoll_ctl(server->epoll.fd, EPOLL_CTL_DEL, disc_fd, &server->epoll.event);
	if (disc_fd > -1)
        close(disc_fd);
	vector<int>::iterator it = server->open_fds.begin();
	vector<int>::iterator ite = server->open_fds.end();
	for (; it != ite; ++it)
	{
		if (*it == disc_fd)
		{
			cout << "user disconnected = " << disc_fd << endl;
			server->open_fds.erase(it);
			break;
		}
	}
}



