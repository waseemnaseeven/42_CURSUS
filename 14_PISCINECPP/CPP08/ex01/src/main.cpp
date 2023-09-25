#include "includes/Span.hpp"

int main()
{
	std::cout << BOLDMAGENTA << "\n 💻💻 ========== TEST 1 ========== 💻💻 \n" <<  RESET << std::endl;
	try {
		Span span(10001);
		span.addNumbers();

		std::cout << "Shortest span is: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span is: " << span.longestSpan() << std::endl;

	} catch (std::exception &e ) {
		std::cerr << BOLDRED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << BOLDMAGENTA << "\n 💻💻 ========== TEST 2 ========== 💻💻 \n" <<  RESET << std::endl;

	try {
		Span span(1);
		span.addNumbers();

		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;

	} catch (std::exception &e) {
		std::cerr << BOLDRED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << BOLDMAGENTA << "\n 💻💻 ========== TEST 3 ========== 💻💻 \n" <<  RESET << std::endl;
	try {
		Span span(0);
		span.addNumbers();

		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;

	} catch (std::exception &e) {
		std::cerr << BOLDRED << "Exception caught: " << e.what() << RESET << std::endl;
	}

		std::cout << BOLDMAGENTA << "\n 💻💻 ========== TEST 4 ========== 💻💻 \n" <<  RESET << std::endl;
	try {
		Span span(10);
		span.addNumbers();

		std::cout << "Shortest span is: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span is: " << span.longestSpan() << std::endl;

	} catch (std::exception &e) {
		std::cerr << BOLDRED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << BOLDMAGENTA << "\n 💻💻 ========== MAIN FROM SUBJECT ========== 💻💻 \n" <<  RESET << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
		std::cout << "Shortest span is: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span is: " << sp.longestSpan() << std::endl;
	return 0;
}

