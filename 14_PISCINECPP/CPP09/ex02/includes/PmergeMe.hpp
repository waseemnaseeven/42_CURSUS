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
	private:
		std::vector<int> tab;
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& src);
		PmergeMe& operator=(const PmergeMe& src);

		void parseInput(int ac, char **av);
		void fill_vector(std::string line);
};

void print_vector(std::vector<int> tab);
void check_double(std::vector<int> tab);


#endif // PMERGEME_HPP
