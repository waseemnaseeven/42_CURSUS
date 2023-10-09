#ifndef IRC_HPP
#define IRC_HPP

#include "../includes/Server.hpp"


/* ********** PARSING ARGS FUNCTIONS ********** */
bool parsing(string& port, string& pwd);
bool valid_port(const string& port);
bool valid_pwd(const string& pwd);

/* ********** PARSING COMMANDS FUNCTIONS ********** */

#endif