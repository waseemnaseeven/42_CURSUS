#include "includes/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& src) {
	*this = src;

}

PmergeMe& PmergeMe::operator=(const PmergeMe& src) {
	if (this != &src) {
		this->_unsorted_vec = src._unsorted_vec;
		this->_unsorted_list = src._unsorted_list;
		this->_sorted_vec = src._sorted_vec;
		this->_sorted_list = src._sorted_list;
		this->elapsed_timeVec = src.elapsed_timeVec;
		this->elapsed_timeList = src.elapsed_timeList;
	}

	return *this;
}

void PmergeMe::parse_input(int ac, char **av)
{
	std::string line;

	for (int i = 1; i < ac; i++) {
		std::string input = av[i];
		std::istringstream iss(input);

		while (iss >> line) {
			bool isDigit = true;

			for (size_t j = 0; j < line.size(); j++) {
				if (!std::isdigit(line[j])) {
					isDigit = false;
						throw std::runtime_error("Only integers are allowed.");
				}
			}
			if (isDigit) {
				int num = std::atoi(line.c_str());
				if (num < 0 || num > 2147483647)
					throw std::runtime_error("Only positive integers are allowed");
				this->_unsorted_vec.push_back(num);
				this->_unsorted_list.push_back(num);
			}
		}
	}
	if (_unsorted_vec.size() > 3000)
		throw std::runtime_error("Too much integers");
	for (size_t i = 0; i < _unsorted_vec.size(); i++) {
		for (size_t j = i + 1; j < _unsorted_vec.size(); j++) {
			if (_unsorted_vec[i] == _unsorted_vec[j] && j != i)
				throw std::runtime_error("Double found");
		}
	}
}

void 	PmergeMe::print_time(int process)
{
	if (process == 1)
	{
		print_output(_unsorted_vec, false);
		// vector sort
		struct timeval start_vec, end_vec;
		gettimeofday(&start_vec, NULL);
		// FordJohnsonAlgorithm perform
		sort_vector(0, _unsorted_vec.size());
		gettimeofday(&end_vec, NULL);
		this->elapsed_timeVec = (end_vec.tv_sec - start_vec.tv_sec) * 1000.0; // Microseconds
		this->elapsed_timeVec += (end_vec.tv_usec - start_vec.tv_usec) / 1000.0;
		print_output(_sorted_vec, true);
		std::cout << "Time to process a range of " << _sorted_vec.size() << " elements with std::[...] : " << elapsed_timeVec << " us" << std::endl;
		return ;
	}
	else if (process == 2)
	{
		// list_sort
		struct timeval start_list, end_list;
		gettimeofday(&start_list, NULL);
		// FordJohnsonAlgorithm perform
		//sort_list(0, _unsorted_list.size());
		gettimeofday(&end_list, NULL);
		this->elapsed_timeList = (end_list.tv_sec - start_list.tv_sec) * 1000.0; // Microseconds
		this->elapsed_timeList += (end_list.tv_usec - start_list.tv_usec) / 1000.0;

		std::cout << "Time to process a range of " << _sorted_list.size() << " elements with std::[...] : " << elapsed_timeVec << " us" << std::endl;
		return ;
	}

}

void PmergeMe::mergeVector(int begin, int mid, int end)
{
	std::cout << begin << std::endl;
	std::cout << end << std::endl;
	std::cout << mid << std::endl;
	std::vector<int> temp(_unsorted_vec.begin() + begin, _unsorted_vec.begin() + end);
	int left = 0;
	int right = mid - begin;
	int result = begin;

	while (left < mid - begin && right < end - begin) {
		if (temp[left] <= temp[right]) {
			_unsorted_vec[result] = temp[left];
			++left;
		} else {
			_unsorted_vec[result] = temp[right];
			++right;
		}
		++result;
	}

	while (left < mid - begin) {
        _unsorted_vec[result] = temp[left];
        ++left;
        ++result;
    }

    while (right < end - begin) {
        _unsorted_vec[result] = temp[right];
        ++right;
        ++result;
    }

}

void PmergeMe::insertionVector(int begin, int end)
{
	for (int i = begin + 1; i < end; i++)
	{
		int key = _unsorted_vec[i];
		int j = i - 1;
		while (j >= begin && _unsorted_vec[j] > key)
		{
			_unsorted_vec[j + 1] = _unsorted_vec[j];
			--j;
		}
		_unsorted_vec[j + 1] = key;
	}
}

void PmergeMe::sort_vector(int begin, int end)
{
	if ((end - begin) > 10)
	{
		int mid = (begin + end) / 2;
		sort_vector(begin, mid);
		sort_vector(mid, end);
		mergeVector(begin, mid, end);
	}
	else
	{
		insertionVector(begin, end);
	}
	_sorted_vec = _unsorted_vec;
}

bool PmergeMe::isSortedFunction() {
    bool isSorted = true;
    for (std::vector<int>::iterator it = _unsorted_vec.begin(); it != _unsorted_vec.end() - 1; ++it) {
        if (*it > *(it + 1)) {
            isSorted = false;
            break;
        }
    }
    return isSorted;
}

