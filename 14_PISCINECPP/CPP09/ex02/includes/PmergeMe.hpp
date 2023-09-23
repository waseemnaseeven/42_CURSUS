#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <exception>
#include <fstream>
#include <sstream>
#include <cstring>
#include <limits>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "includes/Colors.hpp"

class PmergeMe {
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& src);
		PmergeMe& operator=(const PmergeMe& src);

		//void parseInput(std::string const &input);



};

#endif // PMERGEME_HPP
