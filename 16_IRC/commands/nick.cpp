#include "../includes/Server.hpp"
#include "../includes/User.hpp"
#include "../includes/messages.hpp"

bool    NICK_command(t_serv *server, const string& nickname, int sender_fd)
{
    cout << "coucou" << endl;

    if (server->users_map[sender_fd]->get_hasNickname() == true && server->users_map[sender_fd]->get_nickname() == nickname)
        return (send_message(server, ERR_ALREADYREGISTERED(int_to_string(sender_fd)), sender_fd));
    /* si le nick name est deja enregistre, mais qu'on souhaite le changer*/
    if (server->users_map[sender_fd]->get_hasNickname() == true && server->users_map[sender_fd]->get_nickname() != nickname)
    {
        server->users_map[sender_fd]->set_nickname(nickname);
        return true;
    }
    if (nickname.size() > 9)
        return (send_message(server, ERR_ERRONEUSNICKNAME(int_to_string(sender_fd), nickname), sender_fd));
    if (nickname.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789[]\\`_^{|}-") != string::npos)
        return (send_message(server, ERR_ERRONEUSNICKNAME(int_to_string(sender_fd), nickname), sender_fd));
    if (server->users_map[sender_fd]->get_hasNickname() == false)
    {
        server->users_map[sender_fd]->set_nickname(nickname);
        server->users_map[sender_fd]->set_hasNickname(true);
        cout << "nickname : " << server->users_map[sender_fd]->get_nickname() << endl;
        return true;
    }
    return false;
}