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
		Array<T>() : _size(0) {
			std::cout << PURPLE << "Constructor by default called for a new array " << RESET << std::endl;
			this->_array = new T[_size];
		}

		Array<T>(unsigned int n) : _size(n) {
			std::cout << PURPLE << "Constructor by default with parameters called " << RESET << std::endl;
			this->_array = new T[this->_size];
			//for (unsigned int i = 0; i < n; ++i) {
			//	_array[i] = 0;
			//}
		}
		~Array<T>() {
			std::cout << PURPLE << "Array Destructor" << RESET << std::endl;
			if (this->_array != NULL)
				delete [] _array;
		}

		//Array<T>(Array<T> const &src) : _array(new T[src._size]), _size(src._size) {
		//	std::cout << PURPLE << "New array (copy constructor)" << RESET << std::endl;
		//	for (unsigned int i = 0; i < _size; i++) {
		//		_array[i] = src._array[i];
		//	}
		//}

		Array<T>(Array<T> const &src) : _size(src._size) {
			std::cout << PURPLE << "New array (copy constructor)" << RESET << std::endl;
			this->_array = NULL;
			*this = src;
		}

		Array<T>& operator=(const Array& src) {
			if (this != &src) {
				T* newArray = new T[src._size];
				for (unsigned int i = 0; i < src._size; ++i) {
					newArray[i] = src._array[i];
				}
				delete [] _array;
				_array = newArray;
				_size = src._size;
			}
			return (*this);
		}

		T &operator[](int index)
		{
			int d = (unsigned int)_size;
			if (index >= d)
				throw Array<T>::IndexOutOfBound();
			return (this->_array[index]);
		}

		unsigned int size() const {
			return _size;
		}

		void print(){
			for (unsigned int i = 0; i < _size; ++i)
			{
        		std::cout << BOLDCYAN << "\n " << *(_array + i);

			}
   	 		std::cout << RESET << std::endl;
		}

	private:
		T* _array;
		unsigned int _size;

		class IndexOutOfBound : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Index out of bound: ");
				}

		};

};

#endif // ARRAY_HPP
