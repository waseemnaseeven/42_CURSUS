#include "includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << GREEN << "Constructor called for an AMAZING scalarconverter " << RESET << std::endl;
}

ScalarConverter::~ScalarConverter() {
	std::cout << RED << "Destructor called to destroy scalarconverter " << RESET << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& src) { (void) src; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &src) {
	(void) src;
	return (*this);
}

void ScalarConverter::convert(const std::string &input)
{
	// Try to convert to int
	int intValue = atoi(input.c_str());
	std::cout << intValue << std::endl;
	char charValue = static_cast<char>(intValue);
	std::cout << charValue << std::endl;
	float floatValue = static_cast<float>(intValue);
	std::cout << floatValue << std::endl;
	double doubleValue = static_cast<double>(intValue);
	std::cout << doubleValue << std::endl;

	try {
		if (intValue == 0 && input != "0")
			throw std::invalid_argument("Conversion to int failed");
		if (intValue > 2147483647 || intValue < -2147483648)
			throw std::invalid_argument("Under the limits");
		std::cout << BOLDRED << "char: ";
		if (!isprint(charValue))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << charValue << std::endl;

		std::cout << "int: " << intValue << std::endl;
		std::cout << "float: " << floatValue << "f" << std::endl;
		std::cout << "double: " << doubleValue << RESET << std::endl;
	} catch (const std::invalid_argument&) {
		// Conversion to int failed
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << input << "f" << std::endl;
		std::cout << "double: " << input << std::endl;
	}
}
