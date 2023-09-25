#include "includes/easyfind.hpp"

int main()
{
	std::vector<int> tab(5, 4);
	tab.push_back(6);
	tab.push_back(8);
	//tab.push_back(5);
	for (size_t i(0); i < tab.size(); ++i)
		std::cout << tab[i] << " ";
	std::cout << "\n";
	int value = 5;
	if (find_info(tab, value))
		std::cout << BOLDGREEN << "Found the value" << RESET << std::endl;
	else
		std::cout << BOLDRED << "Value not found" << RESET << std::endl;
}
