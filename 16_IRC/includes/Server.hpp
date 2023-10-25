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
#include "../includes/Channel.hpp"

using namespace std;

#define LOCAL_HOST "127.0.0.1"
#define BUFFERSIZE 1024
#define MAX_EVENTS 10 // ou backlog, ou max_clients, le nbr de pending connections queue
#define MAX_CHANNELS 1

extern bool Open;

class User;
class Channel;

typedef map<int, User*> 		t_users; 	//Users will be mapped key: fd; User*: User corresponding to the fd
typedef map<string, Channel *>	t_channels; //Key: channel name; Channel*: corresponding Channel

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

	vector<int>			open_fds; // regular users
	vector<int>			operator_fds; // moderator users

	t_epoll 			epoll;
	t_users				users_map;
	t_channels			channels;

}					t_serv;

/* ********** PARSING ARGS FUNCTIONS ********** */
bool 	parsing(string& port, string& pwd);
bool 	valid_port(const string& port);
bool 	valid_pwd(const string& pwd);

/* ********** SERVER FUNCTIONS ********** */
void 	runIRC(t_serv *server);
bool 	initServer(t_serv *server);
void 	initClients(t_serv *server);
void 	clients_actions(t_serv *server, int i);
void 	user_connection(t_serv *server);
void 	user_disconnection(t_serv *server, int fd);
void 	receive_byts(t_serv *server, int i);
void    execute_commands(t_serv *server, vector<pair<string, string> > commands, int sender_fd);

/* ********** CLEAR_DATA FUNCTIONS ********** */
void 	clear_data(t_serv *server);

/* ********** SIGNAL FUNCTIONS ********** */
void 	signal_handler(int signum);

/* ********** PRINT FUNCTIONS ********** */
void	print_commandsargs(vector<pair<string, string> > commands);
void 	print_map(map<int, User*> map);
void	print_channel(map<string, Channel*> channels_map);
void 	print_vector(vector<int> fd);
void	print_epoll_status(t_serv *server, int i);
void    Hello_IRC(t_serv *server);
string 	welcome_msg();

/* ********** COMMANDS ********** */
bool 	PASS_command(t_serv *server, const string& password, int sender_fd);
bool    NICK_command(t_serv *server, const string& nickname, int sender_fd);
bool	check_passwd(t_serv *server, int sender_fd);
bool	USER_command(t_serv *server, const string& username, int sender_fd);
bool	UNKNOWN_command(t_serv *server, const string& command, int sender_fd);
bool	PING_command(t_serv *server, const string& args, int sender_fd);
bool	OPER_command(t_serv *server, const string& args, int sender_fd);
bool	QUIT_command(t_serv *server, const string& reason, int sender_fd);
bool    PRIVMSG_command(t_serv *server, const string& args, int sender_fd);
bool	JOIN_command(t_serv *server, const string& args, int sender_fd);
string	get_channel_name(const string& args);
string	get_key(const string& args);
bool	PART_command(t_serv *server, const string& args, int sender_fd);
bool    KICK_command(t_serv *server, const string& args, int sender_fd);
User*	getUser(string channel_name, string nick, t_serv *server);
bool	TOPIC_command(t_serv *server, const string& args, int sender_fd);
bool	INVITE_command(t_serv *server, const string& args, int sender_fd);
Channel*getChannel(const string& channel_name, t_serv *server);
/* ********** MESSAGES ********** */
bool 	send_message(t_serv *server, const string& message, int sender_fd);


/* ********** UTILS FUNCTIONS ********** */
int		find_user_fd(int fd, t_serv *server);
string	int_to_string(int n);


#endif // SERVER_HPP
