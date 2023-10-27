#include "../includes/Server.hpp"
#include "../includes/User.hpp"
#include "../includes/messages.hpp"

string get_topic(const string& args)
{
    string topic = "";
    for (size_t i = 0; i < args.size(); i++) {
        if (args[i] == ' ')
        {
            topic = args.substr(i + 1);
            break;
        }
    }
    return topic;
}

bool	TOPIC_command(t_serv *server, const string& args, int sender_fd)
{
	if (args.size() < 2 || args.empty()) {
		send_message(server, ERR_NEEDMOREPARAMS(int_to_string(sender_fd), "TOPIC"), sender_fd);
        return false;
	}

	User* target_user = server->users_map[sender_fd];
	Channel *myChannel = NULL;
	string channel_name = get_channel_name(args);
	string topic = get_topic(args);

	map<string, Channel*>::iterator it = server->channels.find(channel_name);
	if (it != server->channels.end())
	{
		myChannel = it->second;
		if (!myChannel->is_user(sender_fd)) {
			send_message(server, ERR_NOTONCHANNEL(channel_name, server->users_map[sender_fd]->get_nickname()), sender_fd);
			return false;
		}
		if (topic.empty()){
			if (myChannel->get_is_topic_set())
				send_message(server, RPL_TOPIC(target_user->get_nickname(), target_user->get_username(), "localhost", channel_name, myChannel->get_topic()), sender_fd);
			else
				send_message(server, RPL_NOTOPIC(target_user->get_nickname(), target_user->get_username(), "localhost", channel_name), sender_fd);
			return true;
		}
		else
		{
			if (myChannel->get_is_topic_protected() == true && myChannel->is_op(sender_fd) == false) {
				send_message(server, ERR_CHANOPRIVSNEEDED(server->users_map[sender_fd]->get_nickname(), channel_name), sender_fd);
				return false;
			}
			if (topic.size() <= 1) {
				myChannel->unset_topic();
				myChannel->broadcast(RPL_TOPIC2(target_user->get_nickname(), target_user->get_username(), "localhost", channel_name, topic), -1);
			}
			else {
				myChannel->set_topic(topic);
				myChannel->broadcast(RPL_TOPIC2(target_user->get_nickname(), target_user->get_username(), "localhost", channel_name, topic), -1);
			}
			return true;
		}
	}
	else {
		send_message(server, ERR_NOSUCHCHANNEL(target_user->get_nickname(), channel_name), sender_fd);
		return false;
	}
	return true;
}
