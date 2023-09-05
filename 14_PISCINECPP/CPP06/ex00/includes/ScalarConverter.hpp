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
		static void convert(const std::string& input);
		static std::string getType(int flag);
		static void drawType(const std::string& input, int flag);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter &src);

};

int is_fchar(const std::string&input);
int	is_double(const std::string& input);

#endif
