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


std::string ScalarConverter::getType(int flag)
{
    switch (flag) {
        case 0:
            return "CHAR";
        case 1:
            return "INT";
        case 2:
            return "FLOAT";
        case 3:
            return "DOUBLE";
        default:
            return "UNKNOWN";
    }
}
void ScalarConverter::drawType(const std::string& input, int flag)
{
	std::cout << "============================================================" << std::endl;
	std::cout << "===================     Input: ";
	std::cout << input;
	std::cout << "       ====================" << std::endl;
	std::cout << "==================== Detected type: ";
	std::cout << getType(flag);
	std::cout << " ====================" << std::endl;
	std::cout << "============================================================" << std::endl;
}

int	is_fchar(const std::string& input)
{
	int i = 0;
	while (input[i])
		i++;
	if (input[i - 1] == 'f')
		return (1);
	return (0);
}

int	is_double(const std::string& input)
{
	int i = 0;
	bool ret = false;
	while (input[i])
	{
		if (input[i] == '.')
			ret = true;
		i++;
	}
	if (input[i - 1] == 'f')
		return (0);
	if (ret == true)
		return (1);
	return (0);
}

void ScalarConverter::convert(const std::string& input)
{
	int f_char = is_fchar(input);
	int	dot_zero = is_double(input);
	//std::cout << dot_zero << std::endl;
	try {
		int res = isdigit(input[0]);

		if ((input.length() > 1 || res > 0) || f_char == 1)
				throw std::exception();
		drawType(input, 0);
		char charValue = input[0];
		std::cout << BOLDMAGENTA << "char: '" << charValue << "'" <<  std::endl;
		std::cout << "int: " << static_cast<int>(charValue) << std::endl;
		std::cout << "float: " << static_cast<float>(charValue) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(charValue) << ".0" << RESET <<  std::endl;

	} catch(std::exception& e) {

		try {
			int intValue = atoi(input.c_str());
			char charValue = static_cast<char>(intValue);

			if ((intValue == 0 && input[0] != '0') || f_char == 1)
				throw std::exception();
			drawType(input, 1);
			if (intValue > 32 && intValue < 126)
				std::cout << BOLDBLUE << "char: '" << charValue << "'" <<  std::endl;
			else
				std::cout << BOLDBLUE << "char: Non displayable" << std::endl;

			std::cout << "int: " << intValue << std::endl;
			std::cout << "float: " << static_cast<float>(intValue) << ".0f" << std::endl;
			std::cout << "double: " << static_cast<double>(intValue) << ".0" << std::endl;

		} catch (std::exception& e) {
			drawType(input, 2);
			std::cout << BOLDRED << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			try {
				float floatValue = atof(input.c_str());

				if ((floatValue == 0 && input[0] != '0') || dot_zero == 1)
					throw std::exception();
				std::cout << "float: " << floatValue << "f" << std::endl;
				std::cout << "double: " << static_cast<double>(floatValue) << RESET << std::endl;

			} catch (std::exception& e) {
				drawType(input, 3);
				std::cout << BOLDGREEN << "float: impossible" << std::endl;
				try {
					double doubleValue = atof(input.c_str());

					if (doubleValue == 0 && input[0] != '0')
						throw std::exception();
					std::cout << "double: " << doubleValue << ".0" << RESET << std::endl;

				} catch (std::exception& e) {
					std::cout << "double: impossible" << RESET << std::endl;
				}
			}
		}
	}
}
