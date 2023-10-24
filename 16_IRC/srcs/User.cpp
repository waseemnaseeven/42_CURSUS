#include "../includes/User.hpp"

User::User() {}

User::User(int fd) :
	_username(""),
	_nickname(""),
	_messages(""),
	_fd(fd),
	_isOperator(false),
	_isAuthentified(false),
	_hasNickname(false),
	_hasUsername(false),
	_hasPassword(false)
{
	std::cout << BOLDGREEN << "[CONSTRUCTOR] User " << _fd << " has been created!" << RESET << std::endl;
}

User::~User() {
	if (_fd != -1)
		close(_fd);
	std::cout << BOLDRED << "[DESTRUCTOR] User " << _fd << " has been destroyed!" << RESET << std::endl;

}

User::User(const User& src) {
	*this = src;
	std::cout << GREEN << "[COPY CONSTRUCTOR] User " << _fd << " has been copied!" << RESET << std::endl;

}

User& User::operator=(const User& src) {
	std::cout << GREEN << "[ASSIGNATION] User Assignation operator called" << RESET << std::endl;
	if (this != &src) {
		this->_username = src._username;
		this->_nickname = src._nickname;
		this->_realname = src._realname;
		this->_messages = src._messages;
		this->_fd = src._fd;
		this->_isOperator = src._isOperator;
		this->_isAuthentified = src._isAuthentified;
		this->_hasNickname = src._hasNickname;
		this->_hasUsername = src._hasUsername;
		this->_hasPassword = src._hasPassword;
	}
	return *this;
}


/* ********** USER METHODS ********** */

void User::add_channel(Channel *channel) {
	_channels.push_back(channel);
}

bool User::remove_channel(const string& channel_name) {
    for (vector<Channel*>::iterator it = _channels.begin(); it != _channels.end(); ++it) {
        if ((*it)->get_channel_name() == channel_name) {
            _channels.erase(it);
            return true;
        }
    }
    return false;
}

vector<pair<string, string> > User::splitBuffer(const string& buffer) {
	vector<pair<string, string> > result;
	size_t start = 0;
	size_t end = buffer.find("\r\n");

	// while we dont find the \r\n
	while (end != string::npos)
	{
		string line = buffer.substr(start, end - start);
		size_t pos = line.find(" ");
		if (pos != string::npos)
		{
			string command = line.substr(0, pos);
			string args = line.substr(pos + 1);
			result.push_back(make_pair(command, args));
		}
		else
			result.push_back(make_pair(line, ""));
		start = end + 2;
		end = buffer.find("\r\n", start);
	}
	return result;
}

/* ********** GETTERS ********** */

string User::get_username() const { return _username; }

string User::get_nickname() const { return _nickname; }

string User::get_realname() const { return _realname; }

int User::get_fd() const { return _fd; }

string User::get_messages() const { return _messages; }

bool User::get_isOperator() const { return _isOperator; }

bool User::get_isAuthentified() const { return _isAuthentified; }

bool User::get_hasNickname() const { return _hasNickname; }

bool User::get_hasUsername() const { return _hasUsername; }

bool User::get_hasPassword() const { return _hasPassword; }

Channel* User::get_channel(const string& channel_name) const {
    for (size_t i = 0; i < _channels.size(); ++i) {
        if (_channels[i]->get_channel_name() == channel_name) {
            return _channels[i];
        }
    }
    return NULL;
}

/* ********** SETTERS ********** */

void User::set_username(const string& username) { _username = username; }

void User::set_nickname(const string& nickname) { _nickname = nickname; }

void User::set_realname(const string& realname) { _realname = realname; }

void User::set_fd(int fd) { _fd = fd; }

void User::set_messages(const string& messages) { _messages = messages; }

void User::set_isOperator(bool isOperator) { _isOperator = isOperator; }

void User::set_isAuthentified(bool isAuthentified) { _isAuthentified = isAuthentified; }

void User::set_hasNickname(bool hasNickname) { _hasNickname = hasNickname; }

void User::set_hasUsername(bool hasUsername) { _hasUsername = hasUsername; }

void User::set_hasPassword(bool hasPassword) { _hasPassword = hasPassword; }

