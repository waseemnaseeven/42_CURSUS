#include "includes/RPN.hpp"

int main (int ac, char ** av)
{
	if (ac != 2 || av[1][0] == '\0')
	{
		std::cerr << BOLDCYAN << "Usage: ./RPN <expression>" << RESET << std::endl;
		return 1;
	}
	try {
		std::string input = av[1];
		//Infix == (4 * (12 + 3) / 2 * (5 + 5) - (100 * 2))/2 Answer 50
		// std::string expr = "4 12 3 + * 2 / 5 5 + * 100 2 * - 2 /";
		// Infix2 == ((8*9) - 9 - 9 - 9 - 4 + 1) = réponse 42
		// std::string expr2 = "8 9 * 9 - 9 - 9 - 4 - 1 +";
		int res = ReversePolishNotationCalculator(input); // input
		std::cout << PURPLE << "Final Result: " << res << std::endl;
	} catch (std::exception &e) {
		std::cerr << BOLDRED << e.what() << RESET << std::endl;
		return 1;
	}
	return 0;
}
