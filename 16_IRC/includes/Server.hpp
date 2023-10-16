#ifndef SERVER_HPP
#define SERVER_HPP

// C++ functions
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <exception>
#include <memory>
#include <map>
#include <list>
#include <vector>
#include <algorithm>
#include <csignal>
#include <sstream> 

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
#include <syslog.h>

// My library
#include "../includes/Colors.hpp"
#include "../includes/User.hpp"

using namespace std;

#define LOCAL_HOST "127.0.0.1"
#define BUFFERSIZE 1024
#define MAX_EVENTS 10 // ou backlog, ou max_clients, le nbr de pending connections queue

extern bool Open;

class User;

typedef map<int, User*> 		t_users; 	//Users will be mapped key: fd; User*: User corresponding to the fd
// typedef map<string, Channel *>	t_channels; //Key: channel name; Channel*: corresponding Channel

// I/O multiplexing with epoll
typedef struct s_epoll
{
	int					fd;
	int					nb_events; // nb de clients
	struct epoll_event event;
	struct epoll_event events[MAX_EVENTS];
}						t_epoll;

// Communication client-server
typedef struct s_serv
{
	int 				_port;
	string 				_passwd;

	int 				serv_fd;
	struct sockaddr_in 	serv_addr;
	socklen_t 			size;
	int 				opt;

	int					new_fd; // for accept
	
	vector<int>			open_fds; // to get a name
	t_epoll 			epoll;
	t_users				users_map;
	// t_channels			channels;
}					t_serv;



	bool initServer(t_serv *server);
	void initClients(t_serv *server);



	void runIRC(t_serv *server);


/* ********** PARSING ARGS FUNCTIONS ********** */
bool parsing(string& port, string& pwd);
bool valid_port(const string& port);
bool valid_pwd(const string& pwd);

/* ********** SERVER FUNCTIONS ********** */
void 	clients_actions(t_serv *server, int i);
void 	user_connection(t_serv *server);
void 	user_disconnection(t_serv *server, int fd);
void    execute_commands(t_serv *server, vector<pair<string, string> > commands, int sender_fd);

/* ********** CLEAR_DATA FUNCTIONS ********** */
void clear_data(t_serv *server);

/* ********** SIGNAL FUNCTIONS ********** */
void signal_handler(int signum);

/* ********** PRINT FUNCTIONS ********** */
void	print_commandsargs(vector<pair<string, string> > commands);
void 	print_map(map<int, User*> map);
void 	print_vector(vector<int> fd);
void	print_epoll_status(t_serv *server, int i);
void    Hello_IRC(t_serv *server);
string 	welcome_msg();
string	int_to_string(int n);

/* ********** COMMANDS ********** */
bool 	PASS_command(t_serv *server, const string& password, int sender_fd);
bool    NICK_command(t_serv *server, const string& nickname, int sender_fd);

/* ********** MESSAGES ********** */
bool send_message(t_serv *server, const string& message, int sender_fd);


#endif // SERVER_HPP
