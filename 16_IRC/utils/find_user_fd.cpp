#include "../includes/Server.hpp"

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
