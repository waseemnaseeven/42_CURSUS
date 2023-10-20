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
    Channel *myChannel = NULL;
    if (args[0] != '#')
    {
        send_message(server, ERR_BADCHANMASK(channel_name), sender_fd);
        return false;
    }
    else
    {
        channel_name =  get_channel_name(args);
        key = get_key(args);
        cout << "channel_name: " << channel_name << endl;
        cout << "key: " << key << endl;
        std::map<std::string, Channel*>::iterator it = server->channels.find(channel_name);
        if (it != server->channels.end())
        {
            // // Le canal existe déjà, interagissez avec lui.
            myChannel = it->second;
            // // Effectuez les opérations nécessaires sur le canal
            myChannel->add_user(sender_fd);
        }
        else
        {
            Channel *new_channel = new Channel(channel_name, sender_fd);
            send_message(server, CREATEDCHANNEL(channel_name), sender_fd);
		    server->channels.insert(pair<string, Channel *>(channel_name, new_channel));
            myChannel = new_channel;
            myChannel->add_user(sender_fd);

        }
    }
    myChannel->broadcast(JOIN(server->users_map[sender_fd]->get_nickname(), server->users_map[sender_fd]->get_username(), "127.0.0.1", channel_name), -1);
    return true;
}
