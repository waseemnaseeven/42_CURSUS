#include "../includes/Server.hpp"

void	print_commandsargs(vector<pair<string, string> > commands)
{
	for (size_t i = 0; i < commands.size(); i++)
	{
		cout << "command: '" << commands[i].first << "'" << endl;
		cout << "args: '" << commands[i].second << "'" << endl;
	}
}

void	print_vector(vector<int> fd)
{
	vector<int>::iterator it = fd.begin();
	vector<int>::iterator ite = fd.end();
	for (; it != ite; ++it){
			cout << "fd is: " << *it << endl;
	}
}

void	print_map(map<int, User*> users_map)
{
	map<int, User*>::iterator it = users_map.begin();
	map<int, User*>::iterator ite = users_map.end();
	for (; it != ite; ++it){
			cout << "fd is: " << it->first << " and the user is : " << it->second << endl;
	}
}

void	print_channel(map<string, Channel*> channels_map)
{
	map<string, Channel*>::iterator it = channels_map.begin();
	map<string, Channel*>::iterator ite = channels_map.end();
	for (; it != ite; ++it) {
			cout << "channel_name is: " << it->first << " and the Channel is : " << it->second << endl;
	}
}

void	print_epoll_status(t_serv *server, int i)
{
		cout << "fd: " << server->epoll.events[i].data.fd << endl;
		cout << "events: " << server->epoll.events[i].events << endl;
		cout << "EPOLLIN: " << EPOLLIN << endl;
		cout << "EPOLLRDHUP: " << EPOLLRDHUP << endl;
		cout << "EPOLLERR: " << EPOLLERR << endl;
		cout << "EPOLLHUP: " << EPOLLHUP << endl;
		cout << "EPOLLET: " << EPOLLET << endl;
		cout << "EPOLLONESHOT: " << EPOLLONESHOT << endl;
		cout << "EPOLLPRI: " << EPOLLPRI << endl;
		cout << "EPOLLOUT: " << EPOLLOUT << endl;
		cout << "EPOLLWAKEUP: " << EPOLLWAKEUP << endl;
		cout << "EPOLLEXCLUSIVE: " << EPOLLEXCLUSIVE << endl;
		cout << "EPOLL_CLOEXEC: " << EPOLL_CLOEXEC << endl;
		cout << "EPOLL_CTL_ADD: " << EPOLL_CTL_ADD << endl;
		cout << "EPOLL_CTL_MOD: " << EPOLL_CTL_MOD << endl;
		cout << "EPOLL_CTL_DEL: " << EPOLL_CTL_DEL << endl;
		cout << "EPOLL_CLOEXEC: " << EPOLL_CLOEXEC << endl;
		cout << "EPOLL_CLOEXEC: " << EPOLL_CLOEXEC << endl;
		cout << "EPOLL_CLOEXEC: " << EPOLL_CLOEXEC << endl;
		cout << "EPOLL_CLOEXEC: " << EPOLL_CLOEXEC << endl;
		cout << "EPOLL_CLOEXEC: " << EPOLL_CLOEXEC << endl;
		cout << "EPOLL_CLOEXEC: " << EPOLL_CLOEXEC << endl;
		cout << "EPOLL_CLOEXEC: " << EPOLL_CLOEXEC << endl;
}
