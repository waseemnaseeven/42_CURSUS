#ifndef IRC_HPP
#define IRC_HPP

#include "../includes/Server.hpp"


/* ********** PARSING ARGS FUNCTIONS ********** */
bool parsing(string& port, string& pwd);
bool valid_port(const string& port);
bool valid_pwd(const string& pwd);

/* ********** PARSING USERS COMMAND FUNCTIONS ********** */
// bool valid_user(const string& user);
// bool valid_user_name(const string& user);
// bool valid_user_mode(const string& mode);
// bool valid_user_realname(const string& realname);

/* ********** PARSING CHANNEL FUNCTIONS ********** */
// bool valid_channel(const string& channel);
// bool valid_channel_name(const string& channel);


#endif