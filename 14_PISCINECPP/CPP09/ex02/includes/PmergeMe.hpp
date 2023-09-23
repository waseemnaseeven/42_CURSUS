#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <exception>
#include <vector>
#include <cstdlib>
// #include <chrono>
#include "includes/Colors.hpp"

class PmergeMe {
	private:
		std::string _str;
		int	_value;

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& src);
		PmergeMe& operator=(const PmergeMe& src);


};

#endif // PMERGEME_HPP
