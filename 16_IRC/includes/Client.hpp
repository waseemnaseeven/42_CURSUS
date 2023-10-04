#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "includes/Server.hpp"
#include "includes/Colors.hpp"

class Client {
	private:
		string _str;
		int	_value;
		struct sockaddr_in cli_addr;
		socklen_t clilen;

	public:
		Client();
		~Client();
		Client(const Client& src);
		Client& operator=(const Client& src);



};

#endif // CLIENT_HPP
