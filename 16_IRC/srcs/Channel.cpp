#include "../includes/Server.hpp"
#include "../includes/User.hpp"
#include "../includes/Channel.hpp"

Channel::Channel() {}

Channel::Channel (string name, int fd) : 
	_channel_name(name),
	_fd_creator(fd),
	_topic(""),
	_key_channel(""),
	_max_channels(1) {
	
	cout << GREEN << "[CONSTRUCTOR] Channel " << _channel_name << " created by " << _fd_creator << RESET << endl;
}
Channel::~Channel() {
	cout << RED << "[DESTRUCTOR] Channel " << _channel_name << " has been destroyed!" << RESET << endl;

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

/* ********** SETTERS ********** */

void Channel::set_channel_name(string name) { _channel_name = name; }

void Channel::set_topic(const string& topic) { _topic = topic; }

void Channel::set_key_channel(const string& key_channel) { _key_channel = key_channel; }

void Channel::set_max_channels(int max_channels) { _max_channels = max_channels; }

/* ********** CHANNEL METHODS ********** */