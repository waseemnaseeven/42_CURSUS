#include "../includes/User.hpp"

User::User() {
	std::cout << GREEN << "User Constructor called for " << RESET << std::endl;

}

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
	std::cout << BOLDGREEN << "User Constructor with fd " << _fd << RESET << std::endl;
}

User::~User() {
	if (_fd != -1)
		close(_fd);
	std::cout << BOLDRED << "User Destructor called for " << RESET << std::endl;

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


/* ********** USER METHODS ********** */


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

vector<pair<string, string> > User::splitBuffer(const string& buffer) {
	vector<pair<string, string> > result;
	size_t start = 0;
	size_t end = buffer.find("\r\n");

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
