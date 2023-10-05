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

// C functions
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// My library
#include "includes/Colors.hpp"

using namespace std;

#define LOCAL_HOST "127.0.0.1"
#define BUFFERSIZE 1024

class Server {
	private:
		int _port;
		string _passwd;
		int _serv_fd;
		int _valread;
		struct sockaddr_in _serv_addr;
		socklen_t size;
		int _opt;
		char _buffer[BUFFERSIZE];
		int _newsockfd;
		bool _isExit;

	void initServer();

	public:
		Server();
		Server(int port, string passwd);
		~Server();
		Server(const Server& src);
		Server& operator=(const Server& src);

	void runIRC();

};

#endif // SERVER_HPP
