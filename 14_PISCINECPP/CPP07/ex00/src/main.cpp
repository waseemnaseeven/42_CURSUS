#include "includes/Templates.hpp"

int main() {
	int	a[5] = {1800, 5, 890 , 4, 89};
	int num1 = 10;
	int num2 = 10;
	int n = sizeof(a) / sizeof(a[0]);
	char c = 'g';
	char d = 'h';
	std::string str[] = {"Bonjour", "Je", "S'appelle", "Wroot", "Da", "Ruski", "P90"};
	int len = sizeof(str) / sizeof(str[0]);

	std::cout << BOLDMAGENTA << "\n\t ********** MY ARRAY ********** \n" << RESET << std::endl;
	std::cout << GREEN << "[ " << RESET;
	for (int i = 0; i < n; i++) {
		std::cout << GREEN << a[i] << " " << RESET;

	}
	std::cout << GREEN << "]" << RESET << std::endl;
	std::cout << GREEN << "[ " << RESET;
	for (int i = 0; i < len; i++) {
		std::cout << GREEN << str[i] << " " << RESET;

	}
	std::cout << GREEN << "]" << RESET << std::endl;
	std::cout << "\n";
	std::cout << BOLDMAGENTA << "\n\t ********** EVENTS ********** \n" << RESET << std::endl;
	std::cout << BLUE << *a << std::endl;
	std::cout << &a << std::endl;
	std::cout << a << std::endl;
	std::cout << sizeof(a) / sizeof(a[0]) << RESET << std::endl;

	std::cout << BOLDMAGENTA << "\n\t ********** SWAP EVENT ********** \n" << RESET << std::endl;
	swap<int>(a[0], a[4]);
	std::cout << GREEN << "[ " << RESET;
	for (int i = 0; i < n; i++) {
		std::cout << GREEN << a[i] << " " << RESET;
	}
	std::cout << GREEN << "]" << RESET << std::endl;
	std::swap<std::string>(str[3], str[5]);
	std::cout << GREEN << "[ " << RESET;
	for (int i = 0; i < len; i++) {
		std::cout << GREEN << str[i] << " " << RESET;

	}
	std::cout << GREEN << "]" << RESET << std::endl;

	std::cout << BOLDMAGENTA << "\n\t ********** MIN/MAX EVENTS ********** \n" << RESET << std::endl;
	std::cout << CYAN << "min of array is: " << min<int>(a[0], a[4]) << std::endl;
	std::cout << "max of the array is: " << max<int>(a[0], a[4]) << RESET << std::endl;
	std::cout << CYAN << "min of array is: " << min<int>(num1, num2) << std::endl;
	std::cout << "max of array is: " << max<int>(num1, num2) << RESET << std::endl;
	std::cout << CYAN << "min between char is: " << min<char>(c, d) << std::endl;
	std::cout << "max between char is: " << max<char>(c, d) << RESET << std::endl;
	std::cout << CYAN << "min between char && int is: " << min<int>(c, a[1]) << std::endl;
	std::cout << "max between char && int is: " << max<char>(c, a[0]) << RESET << std::endl;

	std::cout << BOLDMAGENTA << "\n\t ********** OPERATOR COMPARISON EVENTS ********** \n" << RESET << std::endl;
	// Test integer comparisons
	int p = 10;
	int b = 20;

	std::cout << YELLOW << "Integer Comparisons:" << std::endl;
	std::cout << "p = " << p << ", b = " << b << std::endl;
	std::cout << "a == b: " << (p == b) << std::endl;
	std::cout << "a != b: " << (p != b) << std::endl;
	std::cout << "a >= b: " << (p >= b) << std::endl;
	std::cout << "a <= b: " << (p <= b) << std::endl;

	// Test character comparisons
	char e = 'x';
	char f = 'y';

	std::cout << "\nCharacter Comparisons:" << std::endl;
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "e == d: " << (e == f) << std::endl;
	std::cout << "e != d: " << (e != f) << std::endl;
	std::cout << "e >= d: " << (e >= f) << std::endl;
	std::cout << "e <= d: " << (e <= f) << std::endl;

	// Test string comparisons
	std::string str1 = "apple";
	std::string str2 = "banana";

	std::cout << "\nString Comparisons:" << std::endl;
	std::cout << "str1 = " << str1 << ", str2 = " << str2 << std::endl;
	std::cout << "str1 == str2: " << (str1 == str2) << std::endl;
	std::cout << "str1 != str2: " << (str1 != str2) << std::endl;
	std::cout << "str1 >= str2: " << (str1 >= str2) << std::endl;
	std::cout << "str1 <= str2: " << (str1 <= str2) << RESET << std::endl;

	std::cout << BOLDMAGENTA << "\n\t ********** MAIN FROM THE SUBJECTS ********** \n" << RESET << std::endl;
	int purple = 2;
	int blue = 3;
	::swap( purple, blue );
	std::cout << "purple = " << purple << ", blue = " << blue << std::endl;
	std::cout << "min( purple, blue ) = " << ::min( purple, blue ) << std::endl;
	std::cout << "max( purple, blue ) = " << ::max( purple, blue ) << std::endl;
	std::string cyan = "chaine1";
	std::string red = "chaine2";
	::swap(cyan, red);
	std::cout << "cyan = " << cyan << ", red = " << red << std::endl;
	std::cout << "min( cyan, red ) = " << ::min( cyan, red ) << std::endl;
	std::cout << "max( cyan, red ) = " << ::max( cyan, red ) << std::endl;

	return (0);
}
