#include <iostream>
#include <deque>

template <typename Iterator>
void insertionSort(Iterator begin, Iterator end) {
    for (Iterator i = begin + 1; i != end; i++) {
        typename Iterator::value_type key = *i;
        Iterator j = i - 1;
        while (j >= begin && *j > key) {
            *(j + 1) = *j;
			--j;
        }
        *(j + 1) = key;
    }
}

template <typename Iterator>
void merge(Iterator begin, Iterator middle, Iterator end) {
    std::deque<typename Iterator::value_type> temp(begin, middle);
    Iterator left = temp.begin();
    Iterator right = middle;
    Iterator result = begin;

    while (left != temp.end() && right != end) {
        if (*left <= *right) {
            *result = *left;
            ++left;
        } else {
            *result = *right;
            ++right;
        }
        ++result;
    }

    while (left != temp.end()) {
        *result = *left;
        ++left;
        ++result;
    }
}

template <typename Iterator>
void fordJohnsonSort(Iterator begin, Iterator end) {
    bool alreadySorted = true;
    for (Iterator it = begin; it != end; ++it) {
        Iterator next = it;
        ++next;
        if (next != end && *it > *next) {
            alreadySorted = false;
            break;
        }
    }

    if (alreadySorted) {
        return;
    }

    size_t sequenceSize = 16;
    size_t b = std::distance(begin, end);

    while (b >= sequenceSize) {
        insertionSort(begin, std::next(begin, sequenceSize));
        begin += sequenceSize;
        b -= sequenceSize;
    }

    insertionSort(begin, end);

    while (sequenceSize < b) {
        Iterator current = begin;

        while (b >= sequenceSize * 2) {
            Iterator middle = current;
            std::advance(middle, sequenceSize);
            Iterator next = middle;
            std::advance(next, sequenceSize);
            merge(current, middle, next);
            current = next;
            b -= sequenceSize * 2;
        }

        sequenceSize *= 2;
    }
}

int main() {
    std::deque<int> data;
    data.push_back(8);
    data.push_back(3);
    data.push_back(5);
    data.push_back(1);
    data.push_back(9);
    data.push_back(4);
    data.push_back(7);
    data.push_back(2);
    data.push_back(6);

    std::cout << "Before sorting:";
    for (std::deque<int>::iterator it = data.begin(); it != data.end(); ++it) {
        std::cout << " " << *it;
    }
    std::cout << std::endl;

    fordJohnsonSort(data.begin(), data.end());

    std::cout << "After sorting:";
    for (std::deque<int>::iterator it = data.begin(); it != data.end(); ++it) {
        std::cout << " " << *it;
    }
    std::cout << std::endl;

    return 0;
}
