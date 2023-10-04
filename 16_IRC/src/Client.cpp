#include "includes/Client.hpp"

Client::Client() {
	std::cout << GREEN << "Constructor called for " << RESET << std::endl;

}

Client::~Client() {
	std::cout << RED << "Destructor called for " << RESET << std::endl;

}

Client::Client(const Client& src) {
	*this = src;
	std::cout << GREEN << "Copy constructor called for " << RESET << std::endl;

}

Client& Client::operator=(const Client& src) {
	std::cout << GREEN << "Assignation operator called" << RESET << std::endl;
	if (this != &src) {
		// this->_value = src._value;
        // this->_str = src_str;
	}

	return *this;
}
