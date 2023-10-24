#include "../includes/Server.hpp"
#include "../includes/User.hpp"
#include "../includes/messages.hpp"

string get_reason(const string& args)
{
    string reason;
    for (size_t i = 0; i < args.size(); i++)
    {
        if (args[i] == ':')
        {
            reason = args.substr(i + 1);
            break;
        }
    }
    return reason;
}

bool	PART_command(t_serv *server, const string& args, int sender_fd)
{
	if (args.empty()) {
		send_message(server, ERR_NEEDMOREPARAMS(int_to_string(sender_fd), "PART"), sender_fd);
		return false;
	}
	string channel_name = get_channel_name(args);
	channel_name.erase(std::remove(channel_name.begin(), channel_name.end(), ' '), channel_name.end());
	string reason = get_reason(args);
	map<string, Channel*>::iterator it = server->channels.find(channel_name);
    if (it != server->channels.end())
    {
    	Channel *myChannel = it->second;
        if (!myChannel->is_user(sender_fd)) {
            send_message(server, ERR_NOTONCHANNEL(channel_name, server->users_map[sender_fd]->get_nickname()), sender_fd);
            return false;
        }
		if (reason.empty())
			myChannel->broadcast(PART_WOREASON(server->users_map[sender_fd]->get_nickname(), server->users_map[sender_fd]->get_username(), "127.0.0.1", channel_name), sender_fd);
		else
			myChannel->broadcast(PART_WREASON(server->users_map[sender_fd]->get_nickname(), server->users_map[sender_fd]->get_username(), "127.0.0.1", channel_name, reason), sender_fd);
		myChannel->part(sender_fd);
		// User* user = server->users_map[sender_fd];
		// user->remove_channel(channel_name);
		if (myChannel->get_users().empty()) {
			delete myChannel;
			server->channels.erase(it);
		}
		return true;
    }
    else
    {
        send_message(server, ERR_NOSUCHCHANNEL(server->users_map[sender_fd]->get_nickname(), channel_name), sender_fd);
        return false;
    }
	return true;
}
