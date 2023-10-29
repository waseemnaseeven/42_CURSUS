#include "../includes/Server.hpp"
#include "../includes/User.hpp"
#include "../includes/messages.hpp"

string  get_target(const string& args)
{
    size_t pos = args.find(":");
    if (pos == string::npos)
        return "";
    return args.substr(0, pos);
}

string  get_message(const string& args)
{
    size_t pos = args.find(":");
    if (pos == string::npos)
        return "";
    return args.substr(pos + 1);
}

bool    PRIVMSG_command(t_serv *server, const string& args, int sender_fd)
{
    // ecrire /msg <target> <message>
    string target = get_target(args);
    target.erase(std::remove(target.begin(), target.end(), ' '), target.end()); // Supprimer les espaces
    string message = get_message(args);

    if (target.empty()) {
        send_message(server, ERR_NOSUCHNICKCHANNEL(target), sender_fd);
        return false;
    }

    if (target[0] == '#') {
        map<string, Channel*>::iterator it = server->channels.find(target);
        if (it != server->channels.end()) {
            Channel *myChannel = it->second;
            if (!myChannel->is_user(sender_fd)) {
                send_message(server, ERR_NOTONCHANNEL(target, server->users_map[sender_fd]->get_nickname()), sender_fd);
                return false;
            }
            myChannel->broadcast(PRIVMSG2(server->users_map[sender_fd]->get_nickname(), server->users_map[sender_fd]->get_username(), "127.0.0.1", target, message), sender_fd);
        }
        else {
            send_message(server, ERR_NOSUCHCHANNEL(server->users_map[sender_fd]->get_nickname(), target), sender_fd);
            return false;
        }
    }
    else {
        for (map<int, User*>::iterator it = server->users_map.begin(); it != server->users_map.end(); ++it) {
            if (server->users_map[it->first]->get_nickname() == target) {
                send_message(server, PRIVMSG(server->users_map[sender_fd]->get_nickname(), target, message), server->users_map[it->first]->get_fd());
                return true;
            }
	    }
        send_message(server, ERR_NOSUCHNICKCHANNEL(target), sender_fd);
        return false;
    }
    return true;
}
