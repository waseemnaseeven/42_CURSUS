#include <iostream>
#include <vector>
#include <stdexcept>

class PmergeMe {
private:
    std::vector<int> _unsorted_vec;
    std::vector<int> _sorted_vec;

    double elapsed_timeVec;

    void mergeVector(int begin, int mid, int end);
    void mergeSort(int begin, int end);

public:
    PmergeMe();
    ~PmergeMe();

    void parse_input(int ac, char **av);
    void print_time();
};

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

void PmergeMe::parse_input(int ac, char **av) {
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
            }
        }
    }
    if (_unsorted_vec.size() > 3000)
        throw std::runtime_error("Too many integers");
    for (size_t i = 0; i < _unsorted_vec.size(); i++) {
        for (size_t j = i + 1; j < _unsorted_vec.size(); j++) {
            if (_unsorted_vec[i] == _unsorted_vec[j] && j != i)
                throw std::runtime_error("Duplicate found");
        }
    }
}

void PmergeMe::mergeVector(int begin, int mid, int end) {
    std::vector<int> temp(end - begin);

    int left = begin;
    int right = mid;
    int result = 0;

    while (left < mid && right < end) {
        if (_unsorted_vec[left] <= _unsorted_vec[right]) {
            temp[result++] = _unsorted_vec[left++];
        } else {
            temp[result++] = _unsorted_vec[right++];
        }
    }

    while (left < mid) {
        temp[result++] = _unsorted_vec[left++];
    }

    while (right < end) {
        temp[result++] = _unsorted_vec[right++];
    }

    for (int i = 0; i < result; i++) {
        _unsorted_vec[begin + i] = temp[i];
    }
}

void PmergeMe::mergeSort(int begin, int end) {
    if (end - begin > 1) {
        int mid = (begin + end) / 2;
        mergeSort(begin, mid);
        mergeSort(mid, end);
        mergeVector(begin, mid, end);
    }
}

void PmergeMe::print_time() {
    std::cout << "Before: ";
    for (int i = 0; i < _unsorted_vec.size(); i++) {
        std::cout << _unsorted_vec[i] << " ";
    }
    std::cout << " [...]" << std::endl;

    struct timeval start_vec, end_vec;
    gettimeofday(&start_vec, NULL);

    mergeSort(0, _unsorted_vec.size());

    gettimeofday(&end_vec, NULL);
    elapsed_timeVec = (end_vec.tv_sec - start_vec.tv_sec) * 1000.0; // Microseconds
    elapsed_timeVec += (end_vec.tv_usec - start_vec.tv_usec) / 1000.0;

    std::cout << "After: ";
    for (int i = 0; i < _unsorted_vec.size(); i++) {
        std::cout << _unsorted_vec[i] << " ";
    }
    std::cout << " [...]" << std::endl;
    std::cout << "Time to process a range of " << _unsorted_vec.size() << " elements with std::[...] : " << elapsed_timeVec << " us" << std::endl;
}

int main(int ac, char **av) {
    if (ac < 2 || av[1][0] == '\0') {
        std::cout << "Usage: ./PmergeMe <range of, at least, 3000 different integers>" << std::endl;
        return 1;
    }
    try {
        PmergeMe sort;
        sort.parse_input(ac, av);
        sort.print_time();
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
