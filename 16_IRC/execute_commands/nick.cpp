#include "../includes/Server.hpp"
#include "../includes/User.hpp"
#include "../includes/messages.hpp"

bool    NICK_command(t_serv *server, const string& nickname, int sender_fd)
{
    // /* Check if passwd is set */
    // if (!server->users_map[sender_fd]->get_hasPassword()) {
    //     send_message(server, ERR_NEEDMOREPARAMS(int_to_string(sender_fd), "PASS"), sender_fd);
    //     return false;
    // }
    /* Check if proper number of args is set */
    if (nickname.empty())
    {
        if (server->users_map[sender_fd]->get_hasNickname())
            send_message(server, ERR_NONICKNAMEGIVEN(server->users_map[sender_fd]->get_nickname()), sender_fd);
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

    /* Check if the nick already exists */
    for (size_t i = 0; i < server->open_fds.size(); i++) {
        if (server->users_map[server->open_fds[i]]->get_nickname() == nickname)
        {
            if (server->users_map[sender_fd]->get_hasNickname() == true)
            {
                send_message(server, ERR_NICKNAMEINUSE(int_to_string(sender_fd), nickname), sender_fd);
                return false;
            }
        }
    }

    /* Inform others about the change of name */
    if (server->users_map[sender_fd]->get_hasNickname() == true)
    {
        for (size_t i = 0; i <= server->open_fds.size(); i++) {
            if (server->users_map[server->open_fds[i]]->get_isAuthentified() == true)
            {
                send_message(server, NICK(server->users_map[sender_fd]->get_nickname(), "user", LOCAL_HOST, nickname), sender_fd);
                server->users_map[sender_fd]->set_nickname(nickname);
                return true;

            }
        }
    }
    /* Assign the nickname */
    server->users_map[sender_fd]->set_nickname(nickname);
    server->users_map[sender_fd]->set_hasNickname(true);
    if (server->users_map[sender_fd]->get_hasUsername() == true && server->users_map[sender_fd]->get_hasPassword() == true && server->users_map[sender_fd]->get_isAuthentified() == false)
    {
        server->users_map[sender_fd]->set_isAuthentified(true);
        send_message(server, RPL_WELCOME(nickname, server->users_map[sender_fd]->get_username(), int_to_string(server->_port), LOCAL_HOST), sender_fd);
    }
    return true;
}
