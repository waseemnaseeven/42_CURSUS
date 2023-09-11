#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <exception>
#include "includes/Colors.hpp"

template <typename T> class Templates {
	public:
		Templates() {}
		~Templates() {}
		Templates(const Templates& src) {}
		Templates& operator=(const Templates& src) {return *this;}

	template <typename T>
	void swap(T *a, T *b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	}

	template <typename T>
	T min(T a, T b)
	{
		return (a < b) ? a : b;
	}

	template <typename T>
	T max(T a, T b)
	{
		return (a > b) ? a : b;
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

};

#endif // TEMPLATES_HPP
