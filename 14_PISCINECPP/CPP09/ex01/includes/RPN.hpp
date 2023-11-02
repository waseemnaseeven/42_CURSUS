#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <exception>
#include <fstream>
#include <sstream>
#include <cstring>
#include <limits>
#include <ctime>
#include <cstdlib>
#include <stack>
#include "includes/Colors.hpp"

class RPN {
	public:
		RPN();
		~RPN();
		RPN(const RPN& src);
		RPN& operator=(const RPN& src);
};

int ReversePolishNotationCalculator(std::string& input);
bool performOperation(int operand1, int operand2);
std::ostream &operator<<(std::ostream &os, std::stack<int> value);


#endif // RPN_HPP
