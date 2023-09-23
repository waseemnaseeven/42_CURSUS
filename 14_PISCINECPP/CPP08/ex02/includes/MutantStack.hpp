#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include "includes/Colors.hpp"

template<typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack<T>() {
			std::cout << GREEN << "Constructor called " << RESET << std::endl;
		}
		MutantStack<T>(typename std::stack<T> type) : steak(type) {
			std::cout << GREEN << "Constructor called with container" << RESET << std::endl;
		}
		~MutantStack<T>() {
			std::cout << RED << "Destructor called " << RESET << std::endl;
		}
		MutantStack<T>(const MutantStack& src);
		MutantStack<T>& operator=(const MutantStack& src);

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin() {return (this->c.begin());}
		iterator end() {return (this->c.end());}

	private:
		std::stack<T> steak;

};

#endif // MUTANTSTACK_HPP
