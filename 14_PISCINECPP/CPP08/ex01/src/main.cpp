#include "includes/Span.hpp"

int main()
{
	try {
		Span span(5);
		span.addNumbers();

		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;

	} catch (std::exception &e ) {
		std::cerr << BOLDRED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	try {
		Span span(1);
		span.addNumbers();

		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;

	} catch (std::exception &e) {
		std::cerr << BOLDRED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	try {
		Span span(0);
		span.addNumbers();

		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;

	} catch (std::exception &e) {
		std::cerr << BOLDRED << "Exception caught: " << e.what() << RESET << std::endl;
	}
}

//int main()
//{
//	try {
//		Span sp = Span(5);
//		sp.addNumber(6);
//		sp.addNumber(3);
//		sp.addNumber(17);
//		sp.addNumber(9);
//		sp.addNumber(11);
//		std::cout << sp.shortestSpan() << std::endl;
//		std::cout << sp.longestSpan() << std::endl;


//	} catch (std::exception&e) {
//		std::cerr << BOLDRED << "Exception caught: " << e.what() << std::endl;
//	}
//	return 0;
//}
