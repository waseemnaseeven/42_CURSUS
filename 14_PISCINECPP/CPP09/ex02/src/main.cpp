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
                        	throw std::runtime_error("Only positive integers are allowed.");
                    }
                }

                if (isDigit) {
                    int num = std::atoi(line.c_str());
					//std::cout << "num is: " << num << std::endl;
					if (num < 0 || num > 2147483647)
						throw std::runtime_error("Only positive integers are allowed");
                    tab.push_back(num);
                }
            }
        }

		// print vector tab
        //for (std::vector<int>::iterator it = tab.begin(); it != tab.end(); ++it) {
        //    std::cout << "tab is: " << *it << std::endl;
        //}
		// check size si > 3000 throw error
		if (tab.size() > 3000)
			throw std::runtime_error("Too much integers");
		// check double throw error
		for (size_t i = 0; i < tab.size(); i++) {
			for (size_t j = i + 1; j < tab.size(); j++) {
				if (tab[i] == tab[j] && j != i)
					throw std::runtime_error("Double found");
			}
			std::cout << tab[i] << std::endl;
		}


    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}





