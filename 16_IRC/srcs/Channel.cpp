#include "../includes/Server.hpp"
#include "../includes/User.hpp"
#include "../includes/Channel.hpp"

Channel::Channel() {}

Channel::Channel (string name, int fd) :
	_channel_name(name),
	_fd_creator(fd),
	_topic(""),
	_key_channel(""),
	_max_channels(1),
	_is_invite_only(false),
	_is_topic_set(false) {

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
		// this->_channel_name = src._channel_name;
		// this->_topic = src._topic;
		// this->_password = src._password;
	}
	return *this;
}

/* ********** GETTERS ********** */
string Channel::get_channel_name() const { return _channel_name; }

string Channel::get_topic() const { return _topic; }

string Channel::get_key_channel() const { return _key_channel; }

int Channel::get_max_channels() const { return _max_channels; }

vector<int> Channel::get_users() const { return _fds_users; }

/* ********** SETTERS ********** */

void Channel::set_channel_name(string name) { _channel_name = name; }

void Channel::set_topic(const string& topic) { _topic = topic; }

void Channel::set_key_channel(const string& key_channel) { _key_channel = key_channel; }

void Channel::set_max_channels(int max_channels) { _max_channels = max_channels; }

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
	vector<int>::iterator it = this->_fds_operators.begin();
	vector<int>::iterator ite = this->_fds_operators.end();

	for (; it != ite; it++)
	{
		if (*it == fd_user)
			return true;
	}
	return false;
}

bool	Channel::is_invited(int fd_user)
{
	vector<int>::iterator it = this->_fds_invited.begin();
	vector<int>::iterator ite = this->_fds_invited.end();

	for (; it != ite; it++)
	{
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
	message.clear();
}

void	Channel::add_user(int fd_user)
{
	if (this->_fds_users.empty())
		this->_fds_operators.push_back(fd_user);
	this->_fds_users.push_back(fd_user);
}

void	Channel::part(int fd_user)
{
	vector<int>::iterator it = this->_fds_users.begin();
	vector<int>::iterator ite = this->_fds_users.end();

	for (; it != ite; it++)
	{
		if (*it == fd_user)
		{
			this->_fds_users.erase(it);
			break;
		}
	}
	if (is_op(fd_user) == true)
	{
		vector<int>::iterator it = this->_fds_operators.begin();
		vector<int>::iterator ite = this->_fds_operators.end();

		for (; it != ite; it++)
		{
			if (*it == fd_user)
			{
				this->_fds_operators.erase(it);
				break;
			}
		}
	}
	if (is_invited(fd_user) == true)
	{
		vector<int>::iterator it = this->_fds_invited.begin();
		vector<int>::iterator ite = this->_fds_invited.end();

		for (; it != ite; it++)
		{
			if (*it == fd_user)
			{
				this->_fds_invited.erase(it);
				break;
			}
		}
	}
}
