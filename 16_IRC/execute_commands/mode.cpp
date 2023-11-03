#include "../includes/Server.hpp"
#include "../includes/User.hpp"
#include "../includes/messages.hpp"

string get_mode(const string& args)
{
	string mode = "";
	size_t i = 0;
	while (i < args.size() && args[i] != ' ')
		i++;
	i++;
	while (i < args.size() && args[i] != ' ') {
		mode += args[i];
		i++;
	}
	return mode;
}

string get_str(const string& args)
{
    string str = "";
    size_t i = 0;
    while (i < args.size() && args[i] != ' ')
        i++;
    i++;
    while (i < args.size() && args[i] != ' ')
        i++;
    i++;
    while (i < args.size() && args[i] != ' ') {
        str += args[i];
        i++;
    }
    return str;
}


bool    MODE_command(t_serv *server, const string& args, int sender_fd)
{
    string channel_name = get_channel_name(args);
    string mode = get_mode(args);
    string str = get_str(args);

    if (args.empty()) {
        send_message(server, ERR_NEEDMOREPARAMS(server->users_map[sender_fd]->get_nickname(), "MODE"), sender_fd);
        return false;
    }
    if (mode == "" || args[0] != '#')
        return true;

    Channel* myChannel = getChannel(channel_name, server);

    if (myChannel == NULL) {
        send_message(server, ERR_NOSUCHCHANNEL(server->users_map[sender_fd]->get_nickname(), channel_name), sender_fd);
        return false;
    }
    if (myChannel->is_user(sender_fd) == false) {
        send_message(server, ERR_NOTONCHANNEL(channel_name, server->users_map[sender_fd]->get_nickname()), sender_fd);
        return false;
    }
    if (myChannel->is_op(sender_fd) == false) {
        send_message(server, ERR_NOPRIVILEGES(server->users_map[sender_fd]->get_nickname()), sender_fd);
        return false;
    }
    if (mode[0] == '+') {
        if (mode[1] == 'i') {
            myChannel->set_invite_only(true);
		    myChannel->broadcast(MODE2(user_id(server->users_map[sender_fd]->get_nickname(), server->users_map[sender_fd]->get_username(), "localhost"), channel_name, "+i", "is now invite-only."), -1);
        }
        else if (mode[1] == 't') {
            myChannel->set_protected_topic(true);
		    myChannel->broadcast(MODE2(user_id(server->users_map[sender_fd]->get_nickname(), server->users_map[sender_fd]->get_username(), "localhost"), channel_name, "+t", "topic is now protected."), -1);
        }
        else if (mode[1] == 'k') {
            if (str == "") {
                send_message(server, ERR_NEEDMOREPARAMS(server->users_map[sender_fd]->get_nickname(), "MODE"), sender_fd);
                return false;
            }
            else if (myChannel->get_channel_locked() == true) {
                send_message(server, ERR_KEYSET(channel_name), sender_fd);
                return false;
            }
            else {
                myChannel->set_channel_has_key(true);
                myChannel->set_key_channel(str);
                myChannel->broadcast(MODE2(user_id(server->users_map[sender_fd]->get_nickname(), server->users_map[sender_fd]->get_username(), "localhost"), channel_name, "+k", "is now locked."), -1);
            }
        }
        else if (mode[1] == 'o') {
            if (str == "") {
                    send_message(server, ERR_NEEDMOREPARAMS(server->users_map[sender_fd]->get_nickname(), "MODE"), sender_fd);
                return false;
            }
            User *user_op = getUser(myChannel->get_channel_name(), str, server);
            if (user_op == NULL) {
                send_message(server, ERR_NOSUCHNICKCHANNEL(str), sender_fd);
                return false;
            }
            else if (myChannel->is_user(user_op->get_fd()) == false) {
                send_message(server, ERR_NOTONCHANNEL(myChannel->get_channel_name(), str), sender_fd);
                return false;
            }

            myChannel->op_user(user_op->get_fd());
            myChannel->broadcast(MODE2(user_id(server->users_map[sender_fd]->get_nickname(), server->users_map[sender_fd]->get_username(), "localhost"), channel_name, "+o", "is now channel operator."), -1);
            return true;

        }
        else if (mode[1] == 'l') {
            if (str == "") {
                    send_message(server, ERR_NEEDMOREPARAMS(server->users_map[sender_fd]->get_nickname(), "MODE"), sender_fd);
                return false;
            }

            int value = 0;

            value = atoi(str.c_str());
            if (value < 1)
                return false;
            myChannel->set_max_users(value);
            myChannel->set_has_user_limit(true);
            myChannel->broadcast(MODE2(user_id(server->users_map[sender_fd]->get_nickname(), server->users_map[sender_fd]->get_username(), "localhost"), channel_name, "+l", "is now limited to " + str + " users."), -1);
        }
        else {
            send_message(server, ERR_UNKNOWNMODE(mode), sender_fd);
            return false;
        }
    }
    else if (mode[0] == '-') {
        if (mode[1] == 'i') {
            myChannel->set_invite_only(false);
		    myChannel->broadcast(MODE2(user_id(server->users_map[sender_fd]->get_nickname(), server->users_map[sender_fd]->get_username(), "localhost"), channel_name, "-i", "is no longer invite-only."), -1);
        }
        else if (mode[1] == 't') {
            myChannel->set_protected_topic(true);
		    myChannel->broadcast(MODE2(user_id(server->users_map[sender_fd]->get_nickname(), server->users_map[sender_fd]->get_username(), "localhost"), channel_name, "-t", "topic is no longer protected."), -1);
        }
        else if (mode[1] == 'k') {
            myChannel->set_key_channel("");
            myChannel->set_channel_has_key(false);
            myChannel->broadcast(MODE2(user_id(server->users_map[sender_fd]->get_nickname(), server->users_map[sender_fd]->get_username(), "localhost"), channel_name, "-k", "is no longer locked."), -1);
        }
        else if (mode[1] == 'o') {
            if (str == "") {
                    send_message(server, ERR_NEEDMOREPARAMS(server->users_map[sender_fd]->get_nickname(), "MODE"), sender_fd);
                return false;
            }
            User *user_op = getUser(myChannel->get_channel_name(), str, server);
            if (user_op == NULL) {
                send_message(server, ERR_NOSUCHNICKCHANNEL(str), sender_fd);
                return false;
            }
            else if (myChannel->is_user(user_op->get_fd()) == false) {
                send_message(server, ERR_NOTONCHANNEL(myChannel->get_channel_name(), str), sender_fd);
                return false;
            }
            myChannel->deop_user(user_op->get_fd());
            myChannel->broadcast(MODE2(user_id(server->users_map[sender_fd]->get_nickname(), server->users_map[sender_fd]->get_username(), "localhost"), channel_name, "-o", "is no longer operator."), -1);
            return true;
        }
        else if (mode[1] == 'l') {
            myChannel->set_has_user_limit(false);
            myChannel->broadcast(MODE2(user_id(server->users_map[sender_fd]->get_nickname(), server->users_map[sender_fd]->get_username(), "localhost"), channel_name, "-l", "is no longer limited in members."), -1);
        }
        else {
            send_message(server, ERR_UNKNOWNMODE(mode), sender_fd);
            return false;
        }
    }
    else {
        send_message(server, ERR_UNKNOWNMODE(mode), sender_fd);
        return false;
    }
   return true;
}
