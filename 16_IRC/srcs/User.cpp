#include "../includes/User.hpp"

User::User() {
	std::cout << GREEN << "User Constructor called for " << RESET << std::endl;

}

User::User(int fd, int id) : 
	_username(""),
	_nickname(""),
	_messages(""),
	_fd(fd), 
	_id(id),
	_isOperator(false),
	_isAuthentified(false),
	_hasNickname(false),
	_hasUsername(false) 
{
	std::cout << GREEN << "User Constructor with fd " << _fd << " and id " << _id << RESET << std::endl;
}

User::~User() {
	if (_fd != -1)
		close(_fd);
	std::cout << RED << "User Destructor called for " << RESET << std::endl;

}

User::User(const User& src) {
	*this = src;
	std::cout << GREEN << "User Copy constructor called for " << RESET << std::endl;

}

User& User::operator=(const User& src) {
	std::cout << GREEN << "User Assignation operator called" << RESET << std::endl;
	if (this != &src) {
		// this->_value = src._value;
        // this->_str = src_str;
	}
	return *this;
}

/* ********** GETTERS ********** */

string User::get_username() const {
	return _username;
}

string User::get_nickname() const {
	return _nickname;
}

int User::get_fd() const {
	return _fd;
}

int User::get_id() const {
	return _id;
}

string User::get_messages() const {
	return _messages;
}

bool User::get_isOperator() const {
	return _isOperator;
}

bool User::get_isAuthentified() const {
	return _isAuthentified;
}

bool User::get_hasNickname() const {
	return _hasNickname;
}

bool User::get_hasUsername() const {
	return _hasUsername;
}

/* ********** SETTERS ********** */

void User::set_username(const string& username) {
	_username = username;
}

void User::set_nickname(const string& nickname) {
	_nickname = nickname;
}

void User::set_fd(int fd) {
	_fd = fd;
}

void User::set_id(int id) {
	_id = id;
}

void User::set_messages(const string& messages) {
	_messages = messages;
}

void User::set_isOperator(bool isOperator) {
	_isOperator = isOperator;
}

void User::set_isAuthentified(bool isAuthentified) {
	_isAuthentified = isAuthentified;
}

void User::set_hasNickname(bool hasNickname) {
	_hasNickname = hasNickname;
}

void User::set_hasUsername(bool hasUsername) {
	_hasUsername = hasUsername;
}

/* ********** USER METHODS ********** */

void User::send_message(const string& message) {
	send(_fd, message.c_str(), message.size(), 0);
}

void User::receive_message(const string& message) {
	_messages += message;
}