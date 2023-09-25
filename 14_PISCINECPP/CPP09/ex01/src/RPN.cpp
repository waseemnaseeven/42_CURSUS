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
