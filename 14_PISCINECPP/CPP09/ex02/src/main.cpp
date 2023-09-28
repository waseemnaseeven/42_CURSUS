#include "includes/PmergeMe.hpp"

void	print_vector(std::vector<int> vec, bool flag)
{
	int count = 0;
	if (flag == false)
		std::cout << "Before: ";
	else
		std::cout << "After: ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
		count++;
		if (count < 10)
        	std::cout << *it << " ";
    }
	if (count > 10)
		std::cout << " [...]";
	std::cout << std::endl;
}

void	print_list(std::list<int> list, bool flag)
{
	int count = 0;
	if (flag == false)
		std::cout << "Before: ";
	else
		std::cout << "After: ";
	for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it) {
		count++;
		if (count < 10)
        	std::cout << *it << " ";
    }
	if (count > 10)
		std::cout << " [...]";
	std::cout << std::endl;
}

int main(int ac, char** av) {
    if (ac < 2 || av[1][0] == '\0') {
        std::cout << "Usage: ./PmergeMe <range of, at least, 3000 different integers>" << std::endl;
        return 1;
    }
    try {
		PmergeMe sort;
		sort.parse_input(ac, av);
		if (sort.isSortedFunction())
			throw std::runtime_error("Already sorted");
		sort.time_vector();
		sort.time_list();

    } catch (std::exception& e) {
        std::cerr << BOLDRED << "Error: " << e.what() << std::endl;
    }

    return 0;
}





