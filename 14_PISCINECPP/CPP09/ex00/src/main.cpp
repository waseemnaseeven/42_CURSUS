#include "includes/BitcoinExchange.hpp"

int main (int ac, char ** av)
{
	if (ac != 2 || av[1][0] == '\0')
	{
		std::cerr << BOLDCYAN << "Usage: ./btc input.txt" << RESET << std::endl;
		return 1;
	}
	try {
		std::string input = av[1];
		BitcoinExchange btc;
		btc.fillMap();
		btc.parseInput(input);
	} catch (std::exception &e) {
		std::cerr << BOLDRED << "Exception caught: " << e.what() << RESET << std::endl;
	}
}
