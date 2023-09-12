#include "includes/iter.hpp"

int main() {

	std::string str[] = {"Bonjour", "Je", "S'appelle", "Wroot", "Da", "Ruski", "P90"};
	int lenght = sizeof(str) / sizeof(str[0]);

    int arr[] = {1, 2, 3, 4, 5};
	double doublearr[] = {14.9, 6.8, 33.0, 44.0, 5.3};
    int len = sizeof(arr) / sizeof(arr[0]);

	std::cout << BOLDMAGENTA << "\n\t ********** MY ARRAY ********** \n" << RESET << std::endl;
   	std::cout << GREEN << "[ Original array: ";
    for (int i = 0; i < len; i++) {
        std::cout << arr[i] << " ";
    }
   	std::cout << "]" << RESET << std::endl;

	std::cout << GREEN << "[ Original array: ";
	for (int i = 0; i < lenght; i++) {
        std::cout << str[i] << " ";
    }
   	std::cout << "]" << RESET << std::endl;

	std::cout << GREEN << "[ Original array: ";
    for (int i = 0; i < len; i++) {
        std::cout << doublearr[i] << " ";
    }
   	std::cout << "]" << RESET << std::endl;


	std::cout << BOLDMAGENTA << "\n\t ********** ITER EVENTS ********** \n" << RESET << std::endl;

    iter(arr, len, plus_one<int>);
	iter(str, 6, plus_one<std::string>);
	iter(doublearr, len, plus_one<double>);

   	std::cout << GREEN << "[ Modified array: ";
    for (int i = 0; i < len; i++) {
        std::cout << arr[i] << " ";
    }
   	std::cout << "]" << RESET << std::endl;
	std::cout << GREEN << "[ Modified array: ";
	for (int i = 0; i < lenght; i++) {
        std::cout << str[i] << " ";
    }
   	std::cout << "]" << RESET << std::endl;
	std::cout << GREEN << "[ Modifed array: ";
    for (int i = 0; i < len; i++) {
        std::cout << doublearr[i] << " ";
    }
   	std::cout << "]" << RESET << std::endl;

	return (0);
}
