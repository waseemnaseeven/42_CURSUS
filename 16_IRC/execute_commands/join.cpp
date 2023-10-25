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
    string key = "";
    for (size_t i = 0; i < args.size(); i++)
    {
        if (args[i] == ' ') {
            key = args.substr(i + 1);
            break;
        }
    }
    return key;
}

void print_names(t_serv *server, const string& channel_name, int sender_fd)
{
    User* target_user = server->users_map[sender_fd];
    Channel* myChannel = getChannel(channel_name, server);

    if (myChannel == NULL)
        return;

    string users_info = "";

    const vector<int>& user_fds = myChannel->get_users();

    for (size_t i = 0; i < user_fds.size(); ++i) {
        int user_fd = user_fds[i];

        if (user_fd <= 0 || user_fd > MAX_EVENTS)
            break;

        User* user = server->users_map[user_fd];

        if (myChannel->is_op(user_fd) || user->get_isOperator())
            users_info += "@";

        users_info += user->get_nickname();

        if (i < user_fds.size() - 1)
            users_info += " ";
    }

    send_message(server, RPL_NAMREPLY(channel_name, target_user->get_nickname(), target_user->get_username(), "127.0.0.1", users_info), sender_fd);
    send_message(server, RPL_ENDOFNAMES(channel_name, target_user->get_nickname(), target_user->get_username(), "127.0.0.1"), sender_fd);
}

bool    JOIN_command(t_serv *server, const string& args, int sender_fd)
{
    cout << "JOIN command: " << args << endl;
    if (args.empty()) {
        send_message(server, ERR_NEEDMOREPARAMS(int_to_string(sender_fd), "JOIN"), sender_fd);
        return false;
    }
    string channel_name = get_channel_name(args);
    channel_name.erase(std::remove(channel_name.begin(), channel_name.end(), ' '), channel_name.end()); // Supprimer les espaces
    string key = get_key(args);
    Channel *myChannel = NULL;
    cout << "channel_name: " << channel_name << endl;
    cout << "key: " << key << endl;
    if (args[0] != '#') {
        send_message(server, ERR_BADCHANMASK(channel_name), sender_fd);
        return false;
    }
    else {
        map<string, Channel*>::iterator it = server->channels.find(channel_name);
        if (it != server->channels.end()) {
            myChannel = it->second;
            if (myChannel->get_is_invite_only() && myChannel->is_invited(sender_fd) == false) {
                send_message(server, ERR_INVITEONLYCHAN(channel_name, server->users_map[sender_fd]->get_nickname()), sender_fd);
                return false;
            }
            if (myChannel->get_has_user_limit() == true) {
                send_message(server, ERR_CHANNELISFULL(server->users_map[sender_fd]->get_nickname(), channel_name), sender_fd);
                return false;
            }
            if (myChannel->get_key_channel() != key) {
                send_message(server, ERR_BADCHANNELKEY(server->users_map[sender_fd]->get_nickname(), channel_name), sender_fd);
                return false;
            }
            if (myChannel->is_user(sender_fd))
                return true;
            myChannel->add_user(sender_fd);
        }
        else {
            Channel *new_channel = new Channel(channel_name, sender_fd);
            send_message(server, CREATEDCHANNEL(channel_name), sender_fd);
            server->channels[channel_name] = new_channel;
            myChannel = new_channel;
            myChannel->add_user(sender_fd);
        }
    }
    myChannel->broadcast(JOIN(server->users_map[sender_fd]->get_nickname(), server->users_map[sender_fd]->get_username(), "127.0.0.1", channel_name), -1);
    if (myChannel->get_is_topic_set() == true)
        send_message(server, RPL_TOPIC(server->users_map[sender_fd]->get_nickname(), server->users_map[sender_fd]->get_username(), "127.0.0.1", channel_name, myChannel->get_topic()), sender_fd);
    print_names(server, channel_name, sender_fd);
    return true;
}
