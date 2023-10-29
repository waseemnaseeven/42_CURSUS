#include "../includes/Server.hpp"
#include "../includes/User.hpp"
#include "../includes/Channel.hpp"

Channel::Channel() {}

Channel::Channel (string name, int fd) :
	_channel_name(name),
	_fd_creator(fd),
	_topic(""),
	_key_channel(""),
	_is_invite_only(false),
	_is_topic_set(false),
	_is_topic_protected(false),
	_is_channel_locked(false),
	_limits(0),
	_max_users(1),
	_has_user_limit(false) {

	cout << BOLDGREEN << "[CONSTRUCTOR] Channel " << _channel_name << " created by " << _fd_creator << RESET << endl;
}
Channel::~Channel() {
	cout << BOLDRED << "[DESTRUCTOR] Channel " << _channel_name << " has been destroyed!" << RESET << endl;
}

Channel::Channel(const Channel& src) {
	*this = src;
	cout << GREEN << "[COPY CONSTRUCTOR] Channel " << _channel_name << " has been copied! " << RESET << endl;
}

Channel& Channel::operator=(const Channel& src) {
	std::cout << GREEN << "[ASSIGNATION] Assignation operator called" << RESET << endl;
	if (this != &src) {
		this->_channel_name = src._channel_name;
		this->_fd_creator = src._fd_creator;
		this->_topic = src._topic;
		this->_key_channel = src._key_channel;
		this->_is_invite_only = src._is_invite_only;
		this->_is_topic_set = src._is_topic_set;
		this->_is_topic_protected = src._is_topic_protected;
		this->_is_channel_locked = src._is_channel_locked;
		this->_max_users = src._max_users;
		this->_has_user_limit = src._has_user_limit;
		this->_limits = src._limits;
		this->_fds_users = src._fds_users;
		this->_fds_operators = src._fds_operators;
		this->_fds_invited = src._fds_invited;
	}
	return *this;
}

/* ********** GETTERS ********** */

string Channel::get_channel_name() const { return _channel_name; }

string Channel::get_topic() const { return _topic; }

string Channel::get_key_channel() const { return _key_channel; }

vector<int> Channel::get_users() const { return _fds_users; }

vector<int> Channel::get_operators() const { return _fds_operators; }

bool Channel::get_is_invite_only() const { return _is_invite_only; }

bool Channel::get_is_topic_set() const { return _is_topic_set; }

bool Channel::get_is_topic_protected() const { return _is_topic_protected; }

bool Channel::get_channel_locked() const { return _is_channel_locked; }

int Channel::get_max_users() const { return _max_users; }

bool Channel::get_has_user_limit() const { return _has_user_limit; }

int Channel::get_nb_users() const { return _limits; }

/* ********** SETTERS ********** */

void Channel::set_channel_name(string name) { _channel_name = name; }

void Channel::set_topic(string topic) { _is_topic_set = true; _topic = topic; }

void Channel::set_protected_topic(bool mode) { _is_topic_protected = mode; }

void Channel::unset_topic() { _is_topic_set = false; _topic = "";}

void Channel::set_key_channel(const string& key_channel) { _key_channel = key_channel; }

void Channel::set_invite_only(bool mode) { _is_invite_only = mode; if (mode == false) _fds_invited.clear(); }

void Channel::set_max_users(int max_users) { _max_users = max_users; }

void Channel::set_has_user_limit(bool mode) { _has_user_limit = mode; }

void Channel::set_channel_has_key(bool mode) { _is_channel_locked = mode; }

/* ********** CHANNEL METHODS ********** */

bool	Channel::is_user(int fd_user)
{
	vector<int>::iterator it = this->_fds_users.begin();
	vector<int>::iterator ite = this->_fds_users.end();

	for (; it != ite; it++)
	{
		if (*it == fd_user)
			return true;
	}
	return false;
}

bool	Channel::is_op(int fd_user)
{
	if (fd_user == -1)
		return false;
	vector<int>::iterator it = this->_fds_operators.begin();
	vector<int>::iterator ite = this->_fds_operators.end();

	for (; it != ite; it++) {
		if (*it == fd_user)
			return true;
	}
	return false;
}

bool	Channel::is_invited(int fd_user)
{
	vector<int>::iterator it = this->_fds_invited.begin();
	vector<int>::iterator ite = this->_fds_invited.end();

	for (; it != ite; it++) {
		if (*it == fd_user)
			return true;
	}
	return false;
}

void	Channel::broadcast(string message, int fd_emitter)
{
	vector<int>::iterator it = this->_fds_users.begin();
	vector<int>::iterator ite = this->_fds_users.end();

	if (message.size() > 510)
		message = message.substr(0, 510);
	message += "\r\n";
	while (it != ite) {
		if (fd_emitter == -1 || *it != fd_emitter)
			send(*it, message.c_str(), message.size(), 0);
		it++;
	}


		// vector<int>::iterator op = this->_fds_operators.begin();
		// vector<int>::iterator ope = this->_fds_operators.end();

		// if (message.size() > 510)
		// 	message = message.substr(0, 510);
		// message += "\r\n";
		// while (op != ope) {
		// 	if (fd_emitter == -1 || *op != fd_emitter)
		// 		send(*op, message.c_str(), message.size(), 0);
		// 	op++;
		// }
		// message.clear();

	message.clear();
}

void	Channel::add_user(int fd_user)
{
	if (this->_fds_users.empty())
		this->_fds_operators.push_back(fd_user);
	this->_fds_users.push_back(fd_user);
}

void	Channel::kick_user(int fd_user)
{
	vector<int>::iterator it = this->_fds_users.begin();
	vector<int>::iterator ite = this->_fds_users.end();

	for (; it != ite; it++) {
		if (*it == fd_user) {
			this->_fds_users.erase(it);
			break;
		}
	}
	if (is_op(fd_user) == true)
	{
		vector<int>::iterator it = this->_fds_operators.begin();
		vector<int>::iterator ite = this->_fds_operators.end();

		for (; it != ite; it++) {
			if (*it == fd_user) {
				this->_fds_operators.erase(it);
				break;
			}
		}
	}
}

void	Channel::invite_user(int fd_user)
{
	if (is_invited(fd_user) == false)
		this->_fds_invited.push_back(fd_user);
}

void	Channel::part(int fd_user)
{
	this->_fds_users.erase(find(this->_fds_users.begin(), this->_fds_users.end(), fd_user));
	if (is_op(fd_user) == true)
		this->_fds_operators.erase(find(this->_fds_operators.begin(), this->_fds_operators.end(), fd_user));
	if (is_invited(fd_user) == true)
		this->_fds_invited.erase(find(this->_fds_invited.begin(), this->_fds_invited.end(), fd_user));

}

void	Channel::op_user(int fd_to_op)
{
	if (is_op(fd_to_op) == false)
		this->_fds_operators.push_back(fd_to_op);
}

void	Channel::deop_user(int fd_to_deop)
{
	this->_fds_operators.erase(find(this->_fds_operators.begin(), this->_fds_operators.end(), fd_to_deop));
}

void	Channel::increment_limits() { this->_limits++; }
