#include "Channel.hpp"

Channel::Channel() {
	std::cout << GREEN << "Constructor called for " << RESET << std::endl;

}

Channel::~Channel() {
	std::cout << RED << "Destructor called for " << RESET << std::endl;

}

Channel::Channel(const Channel& src) {
	*this = src
	std::cout << GREEN << "Copy constructor called for " << RESET << std::endl;

}

Channel& Channel::operator=(const Channel& src) {
	std::cout << GREEN << "Assignation operator called" << RESET << std::endl;
	if (this != &src) {
		// this->_value = src._value;
        // this->_str = src_str;
	}

	return *this;
}
	