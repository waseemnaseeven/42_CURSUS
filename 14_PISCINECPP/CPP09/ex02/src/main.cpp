#include "includes/PmergeMe.hpp"

int main(int ac, char** av) {
    if (ac < 2 || av[1][0] == '\0') {
        std::cout << "Usage: ./PmergeMe <range of, at least, 3000 different integers>" << std::endl;
        return 1;
    }
    try {
        std::vector<int> tab;
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
                    tab.push_back(num);
                }
            }
        }
		if (tab.size() > 3000)
			throw std::runtime_error("Too much integers");
        std::cout << "Before: ";
		for (size_t i = 0; i < tab.size(); i++) {
			for (size_t j = i + 1; j < tab.size(); j++) {
				if (tab[i] == tab[j] && j != i)
					throw std::runtime_error("Double found");
			}
			// std::cout << "tab[" << i << "] = " << tab[i] << std::endl;
            std::cout << tab[i] << " ";
		}
        std::cout << std::endl;
        struct timeval start, end;
        gettimeofday(&start, NULL);
        std::cout << "After: ";
        FordJohnsonSort_vector(tab.begin(), tab.end());
        gettimeofday(&end, NULL);
        double elapsed = (end.tv_sec - start.tv_sec) * 1000.0; // Microseconds
        elapsed += (end.tv_usec - start.tv_usec) / 1000.0;

        for (size_t i = 0; i < tab.size(); i++) {
            std::cout << tab[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "Time to process a range of " << tab.size() << " elements with std::[...] : " << elapsed << " us" << std::endl;

    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}





