#include "../includes/Server.hpp"
#include "../includes/User.hpp"
#include "../includes/messages.hpp"
#include "../srcs/Channel.cpp"

string    get_channel_name(const string& args)
{
    string channel_name;
    for (size_t i = 0; i < args.size(); i++)
    {
        if (args[i] == ' ')
            break;
        channel_name += args[i];
    }
    return channel_name;
}

string get_key(const string& args)
{
    string key;
    for (size_t i = 0; i < args.size(); i++)
    {
        if (args[i] == ' ')
        {
            key = args.substr(i + 1);
            break;
        }
    }
    return key;
}

bool    JOIN_command(t_serv *server, const string& args, int sender_fd)
{
    cout << "JOIN command: " << args << endl;
    if (args.empty())
    {
        send_message(server, ERR_NEEDMOREPARAMS(int_to_string(sender_fd), "JOIN"), sender_fd);
        return false;
    }
    string channel_name;
    string key;
    if (args[0] == '#')
    {
        channel_name =  get_channel_name(args);
        key = get_key(args);
        cout << "channel_name: " << channel_name << endl;
        cout << "key: " << key << endl;
        Channel *new_channel = new Channel(channel_name, sender_fd);
		server->channels.insert(pair<string, Channel *>(channel_name, new_channel));
		

    }
    else
        return false;
    send_message(server, JOIN(server->users_map[sender_fd]->get_nickname(), server->users_map[sender_fd]->get_username(), "127.0.0.1", channel_name), sender_fd);
    return true;
}