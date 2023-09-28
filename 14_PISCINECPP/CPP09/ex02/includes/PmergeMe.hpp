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
#include <list>
#include <sys/time.h>
#include "includes/Colors.hpp"

class PmergeMe {
	private:
		std::vector<int> _unsorted_vec;
		std::list<int> _unsorted_list;

		std::vector<int> _sorted_vec;
		std::list<int> _sorted_list;

		double elapsed_timeVec;
		double elapsed_timeList;

		void sort_vector(int begin, int end);
		void insertionVector(int begin, int end);
		void mergeVector(int begin, int mid, int end);

		void sort_list();
		void sort_list(std::list<int>::iterator begin, std::list<int>::iterator end);
		void mergeList(std::list<int>::iterator begin, std::list<int>::iterator mid, std::list<int>::iterator end);

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& src);
		PmergeMe& operator=(const PmergeMe& src);

		void parse_input(int ac, char **av);
		bool isSortedFunction();
		void time_vector();
		void time_list();
};

void 	print_vector(std::vector<int> tab, bool flag);
void	print_list(std::list<int> list, bool flag);

#endif // PMERGEME_HPP
