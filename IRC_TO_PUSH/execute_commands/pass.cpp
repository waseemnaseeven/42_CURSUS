#include "../includes/Server.hpp"
#include "../includes/User.hpp"
#include "../includes/messages.hpp"

bool    PASS_command(t_serv *server, const string& password, int sender_fd)
{
    if (server->users_map[sender_fd]->get_hasPassword() == true)
    {
        send_message(server, ERR_ALREADYREGISTERED(int_to_string(sender_fd)), sender_fd);
        return false;
    }
    else if (password.size() == 0)
    {
        send_message(server, ERR_NEEDMOREPARAMS(int_to_string(sender_fd), "PASS"), sender_fd);
        return false;
    }
    else if (password == server->_passwd)
        server->users_map[sender_fd]->set_hasPassword(true);
    else  if (password != server->_passwd)
    {
        send_message(server, ERR_PASSWDMISMATCH(int_to_string(sender_fd)), sender_fd);
        return false;
    }
    return true;
}
