#include "User.hpp"

User::User() {
	std::cout << GREEN << "Constructor called for " << RESET << std::endl;

}

User::~User() {
	std::cout << RED << "Destructor called for " << RESET << std::endl;

}

User::User(const User& src) {
	*this = src
	std::cout << GREEN << "Copy constructor called for " << RESET << std::endl;

}

User& User::operator=(const User& src) {
	std::cout << GREEN << "Assignation operator called" << RESET << std::endl;
	if (this != &src) {
		// this->_value = src._value;
        // this->_str = src_str;
	}

	return *this;
}
	