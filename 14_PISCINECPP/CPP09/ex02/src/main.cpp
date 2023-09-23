#include "includes/PmergeMe.hpp"

int main (int ac, char **av)
{
	if (ac < 2 || av[1][0] == '\0')
	{
		std::cout << BOLDCYAN << "Usage: ./PmergeMe <range of, at least, 3000 differents integers>" << RESET << std::endl;
		return 1;
	}
	try {

	} catch (std::exception &e) {
		std::cout << BOLDRED << e.what() << RESET << std::endl;
	}

}
