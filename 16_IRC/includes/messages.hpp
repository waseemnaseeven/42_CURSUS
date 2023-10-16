#ifndef _MESSAGES_HPP
#define _MESSAGES_HPP

// GENERAL MESSAGE
# define    RPL_WELCOME(nick, user, port, host) (": 001 " + nick + " :Welcome to the " + port + " Network, " + nick + "!" + user + "@" + host + "\r\n")
# define    ERR_UNKNOWNCOMMAND(client, command) (": 421 " + client + " " + command + " :Unknown command(custom)\r\n")

/*  ****************************************************************************** */
/*  ******************************** USER messages ******************************* */
/*  ****************************************************************************** */

// USER MESSAGE ERRRORS
# define    ERR_NEEDMOREPARAMS(client, command) ("461 " + client + " " + command + " :Not enough parameters\r\n")
# define    ERR_ALREADYREGISTERED(client) ("462 " + client + " " ":You may not reregister\r\n")

// PASS MESSAGE ERRORS
# define    ERR_PASSWDMISMATCH(client) ("464 " + client + " :Password incorrect\r\n")

// NICK MESSAGE ERRORS
# define    ERR_NONICKNAMEGIVEN(client) ("431 " + client + " : No nickame given\r\n")
# define    ERR_ERRONEUSNICKNAME(client, nick) ("432 " + client " " + nick " :Erroneus nickname\r\n") 
# define    ERR_NICKNAMEINUSE(client, nick) ("433 " + client + " " + nick + " :Nickname is alreay in use\r\n")

#endif /* _MESSAGES_HPP */