#include "../includes/Server.hpp"

void	clear_data(t_serv *server)
{
	if (server->serv_fd > -1)
		close(server->serv_fd);
	if (server->new_fd > -1)
		close(server->new_fd);
	if (server->epoll.fd > -1)
		close(server->epoll.fd);
	for (int i = 0; server->epoll.events[i].data.fd; ++i) {
		close(server->epoll.events[i].data.fd);
	}
	shutdown(server->serv_fd, SHUT_RDWR);
	throw runtime_error("Data Cleaned");
}