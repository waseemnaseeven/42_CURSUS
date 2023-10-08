#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "includes/Server.hpp"
#include "includes/Colors.hpp"

class Client {
	private:
		struct sockaddr_in cli_addr;
		socklen_t clilen;

	public:
		Client();
		~Client();
		Client(const Client& src);
		Client& operator=(const Client& src);



};

#endif // CLIENT_HPP
