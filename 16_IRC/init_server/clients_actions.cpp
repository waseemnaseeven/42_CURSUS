#include "../includes/Server.hpp"
#include "../includes/User.hpp"

void Server::initClients(t_serv *server)
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

string    printHelpInfo()
{
    string help;

    help.append("STEP 1: PASS\r\n");
    help.append("Use PASS command to set a password. e.g: PASS [server passwd]\r\n\n");
    help.append("STEP 2 : USER\r\n");
    help.append("Use USER command to set a username. e.g: USER [your login]\r\n\n");
    help.append("STEP 3 : NICK\r\n");
    help.append("Use NICK command to set a nickname. e.g: NICK [your nickname]\r\n\n");
    return help;
}

string  parse_msg(t_serv *server, string message, int sender_fd)
{
    (void) server;
    (void) sender_fd;
    if (message == "HELP")
        return (printHelpInfo());
    // else if (message == "PASS")
    //     return ();
    // else if (message == "USER")
    //     return ();
    // else if (message == "NICK")
    //     return ();
    // else if (message == "JOIN")
    //     return ();
    // else if (message == "QUIT")
    //     return ();
    // // Operators channel check
    // else if (message == "KICK")
    //     return ();
    // else if (message == "INVITE")
    //     return ();
    // else if (message == 'MODE')
    //     return ();
    else
        return message;

}

void    getAuthentication(char *buffer)
{
    string info(buffer);
    string username, nickname;
    size_t userPos = info.find("USER");
    size_t nickPos = info.find("NICK");
    User *tmp = new User();
    if (userPos != string::npos) {
        size_t userEnd = info.find('\n', userPos);
        if (userEnd != string::npos)
            username = info.substr(userPos + 4, userEnd - userPos - 4);
    }

    if (nickPos != string::npos) {
        size_t nickEnd = info.find('\n', nickPos);
        if (nickEnd != string::npos)
            nickname = info.substr(nickPos + 4, nickEnd - nickPos - 4);
        
    }
    cout << "username : " << username << endl;
    cout << "nickname : " << nickname << endl;
    tmp->set_username(username);
    tmp->set_nickname(nickname);
    cout << "nick:" << tmp->get_nickname() << endl;
    cout << "user:" << tmp->get_username() << endl;
}

void    clients_actions(t_serv *server, int i)
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
		server->users_map.insert(pair<int, User*>(server->new_fd, new_user));
		server->open_fds.push_back(server->new_fd);
		event_new_con.events = EPOLLIN | EPOLLRDHUP;
		event_new_con.data.fd = server->new_fd;
		fcntl(server->new_fd, F_SETFL, O_NONBLOCK); // MacOnly
		if (epoll_ctl(server->epoll.fd, EPOLL_CTL_ADD, server->new_fd, &event_new_con) < 0)
			clear_data(server);
		++user_id;
        string welcome = welcome_msg();
	    send(server->new_fd, welcome.c_str(), welcome.size(), 0);
	}
	else
	{
		cout << "Client request here" << endl;
		char buffer[BUFFERSIZE];
		int sender_fd = server->epoll.events[i].data.fd;
		int bytes_read = recv(sender_fd, buffer, BUFFERSIZE, 0);
       

		if (bytes_read <= 0)
			user_disconnection(server, sender_fd);
		else
		{
			cout << "message" << endl;
            string message(buffer -1);
            if (!message.empty() && message[message.length() - 1] == '\r')
                message.erase(message.length() - 1);
            string ret = parse_msg(server, message, sender_fd);
            send(sender_fd, ret.c_str(), ret.size(), 0);
            cout << message << endl;
            cout << ret << endl;
            send(sender_fd, ret.c_str(), ret.size(), 0);
		}
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

string  welcome_msg()
{
    std::string welcome = BOLDMAGENTA;
	welcome.append("██╗    ██╗███████╗██╗      ██████╗ ██████╗ ███╗   ███╗███████╗\r\n");
	welcome.append("██║    ██║██╔════╝██║     ██╔════╝██╔═══██╗████╗ ████║██╔════╝\r\n");
	welcome.append("██║ █╗ ██║█████╗  ██║     ██║     ██║   ██║██╔████╔██║█████╗\r\n");
	welcome.append("██║███╗██║██╔══╝  ██║     ██║     ██║   ██║██║╚██╔╝██║██╔══╝\r\n");
	welcome.append("╚███╔███╔╝███████╗███████╗╚██████╗╚██████╔╝██║ ╚═╝ ██║███████╗\r\n");
	welcome.append(" ╚══╝╚══╝ ╚══════╝╚══════╝ ╚═════╝ ╚═════╝ ╚═╝     ╚═╝╚══════╝\r\n");
	welcome.append("\r\n");
    welcome.append(BOLDBLUE);
	welcome.append("You need to login so you can start chatting, type HELP for more info\r\n");
	welcome.append(RESET);
    return (welcome);
}