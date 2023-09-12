#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <exception>
#include "includes/Colors.hpp"


template <typename T>
void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T min(T a, T b)
{
	if (a == b)
		return b;
	if (a < b)
		return a;
	return b;
}

template <typename T>
T max(T a, T b)
{
	if (a == b)
		return b;
	if (a > b)
		return a;
	return b;
}

template <typename T>
bool operator==(const T &a, const T &b) {
	return (a == b);
}

template <typename T>
bool operator>=(const T &a, const T &b) {
	return (a >= b);
}

template <typename T>
bool operator<=(const T &a, const T &b) {
	return (a <= b);
}

template <typename T>
bool operator!=(const T &a, const T &b) {
	return (a != b);
}

//template <typename C> class Templates {
//	public:
//		Templates() {}
//		~Templates() {}
//		Templates(const Templates& src) {(void) src;}
//		Templates& operator=(const Templates& src) {
//			(void) src;
//			return *this;
//		}

//};

#endif // TEMPLATES_HPP
