#include "includes/RPN.hpp"

RPN::RPN() {
	std::cout << GREEN << "Constructor called for " << RESET << std::endl;

}

RPN::~RPN() {
	std::cout << RED << "Destructor called for " << RESET << std::endl;

}

RPN::RPN(const RPN& src) {
	(void) src;
	std::cout << GREEN << "Copy constructor called for " << RESET << std::endl;

}

RPN& RPN::operator=(const RPN& src) {
	std::cout << GREEN << "Assignation operator called" << RESET << std::endl;
	if (this != &src) {
		// this->_value = src._value;
	}

	return *this;
}

// int performOperation(int operand1, int operand2, char c) {
//     switch (c) {
//         case '+':
//             return operand1 + operand2;
//         case '-':
//             return operand1 - operand2;
//         case '*':
//             return operand1 * operand2;
//         case '/':
//             if (operand2 != 0) {
//                 return operand1 / operand2;
//             } else {
//                 throw std::runtime_error("Error: Division by zero.");
//             }
//         default:
//             throw std::runtime_error("Error: Invalid operation.");
//     }
// }

// int ReversePolishNotationCalculator(std::string& input)
// {
// 	std::stack<int> list;
// 	// int ret = 0;
// 	// int v1, v2;
// 	size_t i = 0;
// 	std::string token = "";
// 	// check for integer
// 	while (i < input.length())
// 	{
// 		while (std::isspace(input[i]))
// 			i++;
// 		if (std::isdigit(input[i]) || std::strchr("+-*/", input[i]))
// 			i++;
// 		else
// 			throw std::runtime_error("Error: bad input");
// 	}

// 	for (i = 0; i < input.length(); i++) {
// 		while (std::isspace(input[i]))
// 			i++;
// 		// Check for digits
// 		if (std::isdigit(input[i]))
// 		{
// 			token += input[i];
// 			i++;
// 		}
// 		list.push(std::atof(token.c_str()));
// 		token = "";
// 		// std::cout << list.top() << std::endl;
// 	}
// 	if (list.size() < 2)
// 		throw std::runtime_error("Error: need at least 2 int");

// 	std::cout << "list: " << list;
// 	return 0;
// }


int ReversePolishNotationCalculator(std::string& input) {
    std::stack<int> list;
    size_t i = 0;

    while (i < input.length()) {
        while (std::isspace(input[i]))
            i++;

        if (std::isdigit(input[i]) || std::strchr("+-*/", input[i])) {
            if (std::isdigit(input[i])) {
                std::string token = "";
                while (std::isdigit(input[i])) {
                    token += input[i];
                    i++;
                }
                list.push(std::atoi(token.c_str()));
				//
            } else if (std::strchr("+-*/", input[i])) {
                if (list.size() < 2) {
                    throw std::runtime_error("Error: not enough operands for operator.");
                }
                int operand2 = list.top();
                list.pop();
                int operand1 = list.top();
                list.pop();

                char operation = input[i];
                int result = 0;
                switch (operation) {
                    case '+':
                        result = operand1 + operand2;
                        break;
                    case '-':
                        result = operand1 - operand2;
                        break;
                    case '*':
                        result = operand1 * operand2;
                        break;
                    case '/':
                        if (operand2 == 0) {
                            throw std::runtime_error("Error: division by zero.");
                        }
                        result = operand1 / operand2;
                        break;
                    default:
                        throw std::runtime_error("Error: invalid operator.");
                }
                list.push(result);
                i++;
            }
        } else {
            throw std::runtime_error("Error: bad input.");
        }
    }

    if (list.size() != 1) {
        throw std::runtime_error("Error: invalid expression.");
    }

    int finalResult = list.top();

    return finalResult;
}


std::ostream &operator<<(std::ostream &os, std::stack<int> value)
{
	while (!value.empty())
	{
		os << GREEN << value.top() << " " << RESET << std::endl;
		value.pop();
	}
	return os;
}
