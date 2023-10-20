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
    cout << "target is: " << target << endl;
    string message = get_message(args);
    cout << "message is: " << message << endl;
    if (target.empty())
    {
        cout << "PRIVMSG: target is empty" << endl;
        send_message(server, ERR_NOSUCHNICKCHANNEL(target), sender_fd);
        return false;
    }
    if (target[0] == '#')
    {
        cout << "PRIVMSG to channel" << endl;
        std::map<std::string, Channel*>::iterator it = server->channels.find(target);
        if (it != server->channels.end())
        {
            print_channel(server->channels);
            Channel *myChannel = it->second;
            if (!myChannel->is_user(sender_fd))
            {
                send_message(server, ERR_NOTONCHANNEL(target, server->users_map[sender_fd]->get_nickname()), sender_fd);
                return false;
            }
            myChannel->broadcast(PRIVMSG2(server->users_map[sender_fd]->get_nickname(), server->users_map[sender_fd]->get_username(), "127.0.0.1", target, message), sender_fd);
        }
        else
        {
            send_message(server, ERR_NOSUCHCHANNEL(server->users_map[sender_fd]->get_nickname(), target), sender_fd);
            return false;
        }
    }
    else
    {
        cout << "PRIVMSG to user" << endl;
    }
    return true;
}
