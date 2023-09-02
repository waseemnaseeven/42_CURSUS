#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <limits>
#include <string>
#include <cmath>
#include "includes/Colors.hpp"

class ScalarConverter {

	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter &src);

		static void convert(const std::string& input);
};

#endif
