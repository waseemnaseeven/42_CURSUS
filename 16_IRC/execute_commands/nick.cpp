#include "../includes/Server.hpp"
#include "../includes/User.hpp"
#include "../includes/messages.hpp"

bool    NICK_command(t_serv *server, const string& nickname, int sender_fd)
{
    cout << "coucou" << endl;
    /* Check if passwd is set */
    if (!server->users_map[sender_fd]->get_hasPassword()) {
        send_message(server, ERR_NOPRIVILEGES(nickname), sender_fd);
        return false;
    }
    /* Check if proper number of args is set */
    if (nickname.empty())
    {
        if (server->users_map[sender_fd]->get_hasNickname())
            send_message(server, ERR_NONICKNAMEGIVEN(int_to_string(sender_fd)), sender_fd);
        else
            send_message(server, ERR_NONICKNAMEGIVEN(int_to_string(sender_fd)), sender_fd);
        return false;
    }

    /* Check if nickname is properly formatted */
    char firstChar = nickname[0];
    if (!(isalpha(firstChar) || firstChar == '[' || firstChar == ']' || firstChar == '{' || firstChar == '}' ||  firstChar == '\\' || firstChar == '|'))
    {
        if (server->users_map[sender_fd]->get_hasNickname())
            send_message(server, ERR_ERRONEUSNICKNAME(int_to_string(sender_fd), nickname), sender_fd);
        else
            send_message(server, ERR_ERRONEUSNICKNAME(int_to_string(sender_fd), nickname), sender_fd);
        return false;
    }

    /* missed some verif */

    return true;
}
