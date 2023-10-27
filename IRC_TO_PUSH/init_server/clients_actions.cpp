#include "../includes/Server.hpp"
#include "../includes/User.hpp"
#include "../includes/messages.hpp"

void initClients(t_serv *server)
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
			clients_actions(server, i);
	}
}

void    clients_actions(t_serv *server, int i)
{
	const int user_fd = find_user_fd(server->epoll.events[i].data.fd, server);

    if (server->epoll.events[i].data.fd == server->serv_fd)
		user_connection(server);
	if ((server->epoll.events[i].events & EPOLLERR)
		|| (server->epoll.events[i].events & EPOLLHUP)
		|| (server->epoll.events[i].events & EPOLLRDHUP)
		|| !(server->epoll.events[i].events & EPOLLIN))
		user_disconnection(server, server->epoll.events[i].data.fd);
	else if (user_fd != -1)
		receive_byts(server, i);
}

void 	user_connection(t_serv *server)
{
		struct sockaddr_in socket_new_con = sockaddr_in();
		struct epoll_event event_new_con = epoll_event();
		socklen_t socket_new_con_len = sizeof(socket_new_con);

		server->new_fd = accept(server->serv_fd, (struct sockaddr *)&socket_new_con, &socket_new_con_len);
		if (server->new_fd < 0)
			clear_data(server);

		User *new_user = new User(server->new_fd);
		server->users_map.insert(pair<int, User*>(server->new_fd, new_user));
		server->open_fds.push_back(server->new_fd);
		event_new_con.events = EPOLLIN | EPOLLRDHUP;
		event_new_con.data.fd = server->new_fd;
		// fcntl(server->new_fd, F_SETFL, O_NONBLOCK); // MacOnly
		if (epoll_ctl(server->epoll.fd, EPOLL_CTL_ADD, server->new_fd, &event_new_con) < 0)
			clear_data(server);
}

void user_disconnection(t_serv *server, int disc_fd)
{
    epoll_ctl(server->epoll.fd, EPOLL_CTL_DEL, disc_fd, &server->epoll.event);
    if (disc_fd > -1)
        close(disc_fd);

    t_users::iterator user_it = server->users_map.find(disc_fd);
    if (user_it != server->users_map.end())
    {
        close(disc_fd);

        if (user_it->second)
            delete user_it->second;

        server->users_map.erase(user_it);
    }

    vector<int>::iterator it = server->open_fds.begin();
    while (it != server->open_fds.end())
    {
        if (*it == disc_fd) {
            it = server->open_fds.erase(it);
            break;
        }
        else
            ++it;
    }
}

