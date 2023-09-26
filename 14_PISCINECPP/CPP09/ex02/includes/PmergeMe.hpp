#ifndef PMERGEME_HPP
#define PMERGEME_HPP

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
#include <vector>
#include <deque>
#include <sys/time.h>
#include "includes/Colors.hpp"

/*
	- i = initialise au deuxième de la liste
	- On stocke dans key la valeur de n'importe quel type
	- j = i -1 : on l'initialise avec l' l'élément précédent
	à l'élément actuellement sélectionné (i - 1).
*/

template <typename Iterator>
void insertionSort_vector(Iterator begin, Iterator end)
{
	for (Iterator i = begin + 1; i != end; i++) {
		typename Iterator::value_type key = *i;
		Iterator j = i - 1;

	/*
		tant que l'élément pointé par j est supérieur a la valeur pointé par i
		alors on itère sinon c'est que la valeur devient la key et donc l'élément
		pivot auquel on se réfère pour le tri.
	*/
		while (j >= begin && *j > key) {
			/*
				*(j + 1) = *j;: Si la condition de la boucle while est vraie,
				cela signifie que nous décalons l'élément actuellement pointé
				par j vers la droite (l'élément suivant) en copiant sa valeur.
			*/
			*(j + 1) = *j;
			--j;
		}
		/*
			Lorsque la boucle while se termine, nous avons trouvé la position
			correcte pour key dans la séquence triée. Nous plaçons donc la
			valeur de key à cet emplacement en utilisant *(j + 1).
		*/
		*(j + 1) = key;
	}
}

// Fonction pour fusionner deux sous-séquences triées en une séquence triée
template <typename Iterator>
void merge_vector(Iterator begin, Iterator middle, Iterator end) {
    std::vector<typename Iterator::value_type> temp(begin, end);
    Iterator left = temp.begin();
    Iterator right = temp.begin() + (middle - begin);
    Iterator result = begin;

    while (left < temp.begin() + (middle - begin) && right < temp.end()) {
        if (*left <= *right) {
            *result = *left;
            ++left;
        } else {
            *result = *right;
            ++right;
        }
        ++result;
    }

    // Copiez les éléments restants de la sous-séquence gauche
    while (left < temp.begin() + (middle - begin)) {
        *result = *left;
        ++left;
        ++result;
    }

    // Copiez les éléments restants de la sous-séquence droite
    while (right < temp.end()) {
        *result = *right;
        ++right;
        ++result;
    }
}

template <typename Iterator>
void FordJohnsonSort_vector(Iterator begin, Iterator end)
{
	bool isSorted = true;
	for (Iterator it = begin; it != end; ++it) {
		if (*it > *(it + 1)) {
			isSorted = false;
			break;
		}
	}

	if (isSorted)
		return ;

	size_t sequenceSize = 16;
	while (begin + sequenceSize <= end) {
		insertionSort_vector(begin, begin + sequenceSize);
		begin += sequenceSize;
	}

	// Triez les sous-séquences restantes avec insertion sort
	insertionSort_vector(begin, end);
	size_t size = end - begin;

	// Fusionnez progressivement les sous-séquences triées
	while (sequenceSize < size) {
		Iterator current = begin;
		while (current < end - sequenceSize) {
			Iterator middle = current + sequenceSize;
			Iterator next = middle + sequenceSize;
			current = next;
		}
		sequenceSize *= 2;
	}
}

class PmergeMe {
	private:
		std::vector<int> tab;
		std::deque<int> stack;
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& src);
		PmergeMe& operator=(const PmergeMe& src);

};

void print_before(std::vector<int> tab);


#endif // PMERGEME_HPP
