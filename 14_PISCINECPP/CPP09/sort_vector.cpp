#include <iostream>
#include <vector>
#include <list>

// Fonction pour trier une sous-séquence avec insertion sort
template <typename Iterator>
void insertionSort(Iterator begin, Iterator end) {
    for (Iterator i = begin + 1; i != end; ++i) {
        typename Iterator::value_type key = *i;
        Iterator j = i - 1;

        while (j >= begin && *j > key) {
            *(j + 1) = *j;
            --j;
        }

        *(j + 1) = key;
    }
}

// Fonction pour fusionner deux sous-séquences triées en une séquence triée
template <typename Iterator>
void merge(Iterator begin, Iterator middle, Iterator end) {
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

    // Copiez les éléments restants de la sous-séquence gauche, le cas échéant
    while (left < temp.begin() + (middle - begin)) {
        *result = *left;
        ++left;
        ++result;
    }

    // Copiez les éléments restants de la sous-séquence droite, le cas échéant
    while (right < temp.end()) {
        *result = *right;
        ++right;
        ++result;
    }
}

// Fonction principale de Ford-Johnson
template <typename Iterator>
void fordJohnsonSort(Iterator begin, Iterator end) {
    // Déterminez si la séquence est déjà triée (par exemple, en comparant les éléments adjacentes)
    bool alreadySorted = true;
    for (Iterator it = begin; it != end - 1; ++it) {
        if (*it > *(it + 1)) {
            alreadySorted = false;
            break;
        }
    }

    // Si la séquence est déjà triée, rien à faire
    if (alreadySorted) {
        return;
    }

    // Déterminez la taille des sous-séquences pour l'insertion sort
    size_t sequenceSize = 16; // Ajustez la taille en fonction de vos besoins

    while (begin + sequenceSize <= end) {
        insertionSort(begin, begin + sequenceSize);
        begin += sequenceSize;
    }

    // Triez les sous-séquences restantes avec insertion sort
    insertionSort(begin, end);
	size_t b = end - begin;
    // Fusionnez progressivement les sous-séquences triées
    while (sequenceSize < b) {
        Iterator current = begin;
        while (current < end - sequenceSize) {
            Iterator middle = current + sequenceSize;
            Iterator next = middle + sequenceSize;
            merge(current, middle, next);
            current = next;
        }
        sequenceSize *= 2;
    }
}

int main() {
    std::vector<int> data = {8, 3, 5, 1, 9, 4, 7, 2, 6};
    std::cout << "Before sorting:";
    for (size_t i = 0; i < data.size(); ++i) {
        std::cout << " " << data[i];
    }
    std::cout << std::endl;

    fordJohnsonSort(data.begin(), data.end());

    std::cout << "After sorting:";
    for (size_t i = 0; i < data.size(); ++i) {
        std::cout << " " << data[i];
    }
    std::cout << std::endl;


    // std::list<int> stack = {8, 3, 5, 1, 9, 4, 7, 2, 6};
    // std::cout << "Before sorting:";
    // for (size_t i = 0; i < stack.size(); ++i) {
    //     std::cout << " " << stack[i];
    // }
    // std::cout << std::endl;

    // fordJohnsonSort(stack.begin(), stack.end());

    // std::cout << "After sorting:";
    // for (size_t i = 0; i < stack.size(); ++i) {
    //     std::cout << " " << stack[i];
    // }
    // std::cout << std::endl;
    return 0;
}
