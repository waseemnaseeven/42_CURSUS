#include "includes/ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2 || av[1][0] == '\0')
	{
		std::cout << BOLDCYAN << "Usage: ./convert <input>" << RESET << std::endl;
		return 1;
	}
	else {
		std::string input = av[1];
		ScalarConverter::convert(input);
	}
	return 0;
}
