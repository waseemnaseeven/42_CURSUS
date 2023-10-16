#include "../includes/Server.hpp"
#include "../includes/User.hpp"
#include "../includes/messages.hpp"

bool    PASS_command(t_serv *server, const string& password, int sender_fd)
{
    if (server->users_map[sender_fd]->get_hasPassword() == true)
        send_message(server, ERR_ALREADYREGISTERED(int_to_string(sender_fd)), sender_fd);
    else if (password.empty())
        send_message(server, ERR_NEEDMOREPARAMS(int_to_string(sender_fd), "PASS"), sender_fd);
    else  if (password != server->_passwd)
    {
        cout << "password : " << password << endl;
        cout << "server->_passwd : " << server->_passwd << endl;
        user_disconnection(server, sender_fd);
        return (send_message(server, ERR_PASSWDMISMATCH(int_to_string(sender_fd)), sender_fd));

    }
    else if (password == server->_passwd)
    {
        server->users_map[sender_fd]->set_hasPassword(true);
        server->users_map[sender_fd]->set_isAuthentified(true);
        cout << "same password : " << server->_passwd << " and " << password << endl;
        return true;
    }
    return true;
}