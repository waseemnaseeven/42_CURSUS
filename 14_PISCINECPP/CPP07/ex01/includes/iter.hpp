#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <exception>
#include "includes/Colors.hpp"

template <typename T>
void plus_one(T &arr) {
    arr += 1;
}

template <typename T>
void plus_str(T &arr) {
    arr += 'o';
}

template <typename T, typename F>
void iter(T *array, int len, F func) {
    for (int i = 0; i < len; i++) {
    	func(array[i]);
    }
}

//class iter {
//	public:
//		iter();
//		~iter();
//		iter(const iter& src);
//		iter& operator=(const iter& src);


//};

#endif // ITER_HPP
