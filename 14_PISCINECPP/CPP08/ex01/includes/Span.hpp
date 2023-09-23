#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <exception>
#include <list>
#include <vector>
#include <algorithm>
#include <limits>
#include "includes/Colors.hpp"


template<typename T>
typename T::value_type find_value(const T &arr, int flag) {

    typename T::const_iterator it = arr.begin();
    typename T::value_type minVal = *it;

    for (++it; it != arr.end(); ++it) {
		if (flag == 1)
		{
			if (*it < minVal)
				minVal = *it;
		}
		else
		{
			if (*it > minVal)
				minVal = *it;
		}
    }

    return minVal;
}

class Span {
	public:
		Span(unsigned int N);
		~Span();
		Span(const Span& src);
		Span& operator=(const Span& src);

		void addNumber(unsigned int number);
		void addNumbers();
		unsigned int shortestSpan() ;
		unsigned int longestSpan() ;

	private:
		unsigned int _maxSize;
		std::vector<unsigned int> tab;

};

unsigned int send_int();


#endif // SPAN_HPP
