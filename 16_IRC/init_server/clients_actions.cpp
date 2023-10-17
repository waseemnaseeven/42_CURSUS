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

int find_user_fd(int fd, t_serv *server)
{
	map<int, User*>::iterator it = server->users_map.begin();
	map<int, User*>::iterator ite = server->users_map.end();
	for (; it != ite; ++it)
	{
		if (it->first == fd)
			return (it->first);
	}
	return -1;
}

void    clients_actions(t_serv *server, int i)
{
	// const int user_fd = find_user_fd(server->epoll.events[i].data.fd, server);

    if (server->epoll.events[i].data.fd == server->serv_fd)
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
		// cout << "\033[1;" << 30 + 1 % 7 << "m" << "User " << 5 << " connected :)" << endl;
        // Hello_IRC(server);
	}
	// if ((server->epoll.events[i].events & EPOLLERR)
	// 	|| (server->epoll.events[i].events & EPOLLHUP)
	// 	|| (server->epoll.events[i].events & EPOLLRDHUP)
	// 	|| !(server->epoll.events[i].events & EPOLLIN))
	// 	user_disconnection(server, server->epoll.events[i].data.fd);
	// else if (user_fd != -1)
	else
	{
		int sender_fd = server->epoll.events[i].data.fd;
		cout << "Client request here" << endl;
		char buffer[BUFFERSIZE];
        cout << "sender_fd: " << sender_fd << endl;
		int bytes_read = recv(sender_fd, buffer, BUFFERSIZE, 0);

		if (bytes_read <= 0)
			user_disconnection(server, sender_fd);
		else
		{
            string message(buffer, bytes_read);
            vector<pair<string, string> > commands = server->users_map[sender_fd]->splitBuffer(message);
            execute_commands(server, commands, sender_fd);
		}
	}
}

void    execute_commands(t_serv *server, vector<pair<string, string> > commands, int sender_fd)
{
	print_commandsargs(commands);
    for (size_t i = 0; i < commands.size(); i++) {
        if (commands[i].first == "PASS")
			PASS_command(server, commands[i].second, sender_fd);
        else if (commands[i].first == "NICK") {
			cout << BOLDBLUE << commands[i].second << RESET << endl;
			NICK_command(server, commands[i].second, sender_fd);
        }
		else if (commands[i].first == "USER")
		{
			USER_command(server, commands[i].second, sender_fd);
		}
		// else
		// 	Unknown_command(server, commands[i].first, sender_fd);
    }
}

void    user_disconnection(t_serv *server, int disc_fd)
{
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
