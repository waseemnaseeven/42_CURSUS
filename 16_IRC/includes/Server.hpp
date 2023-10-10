#ifndef SERVER_HPP
#define SERVER_HPP

// C++ functions
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <exception>
#include <map>
#include <list>
#include <vector>
#include <algorithm>
#include <csignal>

// C functions
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

// My library
#include "../includes/Colors.hpp"

using namespace std;

#define LOCAL_HOST "127.0.0.1"
#define BUFFERSIZE 1024
#define MAX_EVENTS 10 // ou backlog, ou max_clients, le nbr de pending connections queue 

typedef struct s_epoll
{
	int					fd;
	int					nb_events; // nb de clients
	struct epoll_event event;
	struct epoll_event events[MAX_EVENTS];

}						t_epoll;

class Channel;
class User;

class Server {
	private:
		int _port;
		string _passwd;
		int _serv_fd;
		struct sockaddr_in _serv_addr;
		socklen_t size;
		int _opt;
		bool _isOpen;
		int _valread;
		char _buffer[BUFFERSIZE];
		int _newsockfd;

	/* ********** EXCEPTIONS ********** */
	class ServerException : public std::exception {
		public:
			virtual const char* what() const throw() 
			{
				// if (this->_serv_fd)
				// 	close(this->_serv_fd);
				// if (this->_newsockfd)
				// 	close(this->_newsockfd);
				return ("Server error");
			}
	};

	/* ********** INIT ********** */
	void initServer(t_epoll epoll);
	void initClients(t_epoll epoll);

	public:
		Server();
		Server(const string& port, const string& passwd);
		~Server();
		Server(const Server& src);
		Server& operator=(const Server& src);

	/* ********** SERVER METHODS ********** */
	void runIRC();
	void clients_actions(t_epoll epoll, int i);
	void exit_server();
};


#endif // SERVER_HPP
