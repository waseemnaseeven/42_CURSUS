#include "../includes/Server.hpp"

int	find_user_fd(int fd, t_serv *data)
{
	t_users::const_iterator	it;
	t_users::const_iterator	ite;

	it = data->users_map.begin();
	ite = data->users_map.end();
	for (; it != ite; it++)
		if (it->first == fd)
			return (it->first);
	return -1;
}
