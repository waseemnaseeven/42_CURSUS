import sys

def hpp_creation(class_name):
    hpp_content = f"""#ifndef {class_name.upper()}_HPP
#define {class_name.upper()}_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <exception>
#include "includes/Colors.hpp"

class {class_name} {{
	public:
		{class_name}();
		~{class_name}();
		{class_name}(const {class_name}& src);
		{class_name}& operator=(const {class_name}& src);

	private:
		std::string _str;
		int	_value;

}};

#endif // {class_name.upper()}_HPP
"""
    return hpp_content

def cpp_creation(class_name, hpp_file_name):
    cpp_content = f"""#include "{hpp_file_name}"

{class_name}::{class_name}() {{
	std::cout << GREEN << "Constructor called for " << RESET << std::endl;

}}

{class_name}::~{class_name}() {{
	std::cout << RED << "Destructor called for " << RESET << std::endl;

}}

{class_name}::{class_name}(const {class_name}& src) {{
	std::cout << GREEN << "Copy constructor called for " << RESET << std::endl;

}}

{class_name}& {class_name}::operator=(const {class_name}& src) {{
	std::cout << GREEN << "Assignation operator called" << RESET << std::endl;
	if (this != &src) {{
		// this->_value = src._value;
	}}

	return *this;
}}
	"""
    return cpp_content

def main():
    if len(sys.argv) != 2:
        print("Usage: python3 generate_class.py <class_name>")
        sys.exit(1)

    class_name = sys.argv[1]
    hpp_file_name = class_name + ".hpp"
    cpp_file_name = class_name + ".cpp"

    hpp_content = hpp_creation(class_name)
    cpp_content = cpp_creation(class_name, hpp_file_name)
    # switch case to know which kind of file i want
	# use try except && assert
    with open(hpp_file_name, 'w') as hpp_file, open(cpp_file_name, 'w') as cpp_file:
        hpp_file.write(hpp_content)
        cpp_file.write(cpp_content)

if __name__ == '__main__':
    main()
