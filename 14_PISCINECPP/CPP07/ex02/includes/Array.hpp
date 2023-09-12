#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <exception>
#include "includes/Colors.hpp"

template<class T> class Array {
	public:
		Array();
		Array(unsigned int n);
		~Array();
		Array(const Array& src);
		Array& operator=(const Array& src) {
			if (this != &src) {
				delete[] _array;
				_n = src._n;
				_array = new T[src._n];
				for (unsigned int i = 0; i < src._n; i++) {
					_array[i] = src._array[i];
				}
			}
			return (*this);
		}

		T &operator[](int index)
		{
			int d = (unsigned int)_n;
			if (index >= d)
				throw Array<T>::IndexOutOfBound();
			return (this->_array[index]);
		}

		//T const &operator[](int index) const
		//{
		//	int d = (unsigned int)_n;
		//	if (index >= d)
		//		throw Array<T>::IndexOutOfBound();
		//	return (this->_array[index]);
		//}
		unsigned int size() const;
		void print();

	private:
		T* _array;
		unsigned int _n;

		class IndexOutOfBound : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Index out of bound: ");
				}

		};

};

template <typename T> Array<T>::Array() : _n(0) {
	std::cout << "Constructor by default called " << std::endl;
	_array = new T[0];
}

template <typename T> Array<T>::Array(unsigned int n) : _n(n) {
	std::cout << "Constructor by default with parameters called " << std::endl;
	_array = new T[n];
	for (unsigned int i = 0; i < this->_n; i++) {
		_array[i] = 0;
	}
}

template <typename T> Array<T>::~Array() {
		delete [] _array;
}

template<typename T> Array<T>::Array(const Array<T> &src) {
	delete[] _array;
	*this = src;
}

template <typename T> void Array<T>::print()
{
    for (unsigned int i = 0; i < _n; i++)
        std::cout << BOLDCYAN << "\n " << *(_array + i);
    std::cout << RESET << std::endl;
}

template<typename T> unsigned int Array<T>::size() const {
	return _n;
}

#endif // ARRAY_HPP
