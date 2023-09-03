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

void ScalarConverter::convert(const std::string& input)
{
	try {
		int intValue = atoi(input.c_str());
		if (intValue == 0 && input[0] != '0')
			throw std::exception();
		char charValue = static_cast<char>(intValue);
		float floatValue = static_cast<float>(intValue);
		double doubleValue = static_cast<double>(intValue);
		if (intValue < 32 || intValue > 126)
			std::cout << BOLDBLUE << "char: Non displayable" << std::endl;
		else
			std::cout << BOLDBLUE<< "char: " << charValue << std::endl;

		std::cout << "int: " << intValue << std::endl;
		std::cout << "float: " << floatValue << ".0f" << std::endl;
		std::cout << "double: " << doubleValue << ".0" << RESET << std::endl;
	} catch (const std::exception& e) {
		std::cout << BOLDMAGENTA << "char: impossible" << std::endl;
		std::cout << "int: impossible"  << std::endl;

		try {
			float floatValue = atof(input.c_str());
			if (floatValue == 0 && input[0] != '0')
				throw std::exception();
			double doubleValue = static_cast<double>(floatValue);
			std::cout << "float: " << floatValue << "f" << std::endl;
			std::cout << "double: " << doubleValue << RESET << std::endl;
		} catch (const std::exception& e) {
			std::cout << BOLDMAGENTA << "float: impossible" << std::endl;
			std::cout << "double: impossible" << RESET << std::endl;
		}
	}
}
