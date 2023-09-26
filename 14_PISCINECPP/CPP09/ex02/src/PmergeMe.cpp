#include "includes/PmergeMe.hpp"

PmergeMe::PmergeMe() {
	std::cout << GREEN << "Constructor called for " << RESET << std::endl;

}

PmergeMe::~PmergeMe() {
	std::cout << RED << "Destructor called for " << RESET << std::endl;

}

PmergeMe::PmergeMe(const PmergeMe& src) {
	(void) src;
	std::cout << GREEN << "Copy constructor called for " << RESET << std::endl;

}

PmergeMe& PmergeMe::operator=(const PmergeMe& src) {
	std::cout << GREEN << "Assignation operator called" << RESET << std::endl;
	if (this != &src) {
		// this->_value = src._value;
	}

	return *this;
}

void	print_before(std::vector<int> tab)
{
	for (std::vector<int>::iterator it = tab.begin(); it != tab.end(); ++it) {
            std::cout << "Before: " << *it << " ";
        }
}
/*

1- Divisez la séquence initiale en sous-séquences de taille fixe ou inférieure à
un certain seuil (séquences plus courtes).

2- Triez chaque sous-séquence avec l'algorithme d'insertion sort,
ce qui est efficace pour de petites séquences.

3- Fusionnez progressivement les sous-séquences triées pour
obtenir une séquence triée plus grande.
Lors de la fusion, assurez-vous de maintenir l'ordre trié.

4- Répétez les étapes 1 à 3 jusqu'à ce que toute la séquence soit triée.

*/

