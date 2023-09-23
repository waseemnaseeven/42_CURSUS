#include "includes/PmergeMe.hpp"

PmergeMe::PmergeMe() {
	std::cout << GREEN << "Constructor called for " << RESET << std::endl;

}

PmergeMe::~PmergeMe() {
	std::cout << RED << "Destructor called for " << RESET << std::endl;

}

PmergeMe::PmergeMe(const PmergeMe& src) {
	(void) src;
	std::cout << GREEN << "Copy constructor called for " << RESET << std::endl;

}

PmergeMe& PmergeMe::operator=(const PmergeMe& src) {
	std::cout << GREEN << "Assignation operator called" << RESET << std::endl;
	if (this != &src) {
		// this->_value = src._value;
	}

	return *this;
}

//void PmergeMe::parseInput(std::string& const input)
//{

//}
