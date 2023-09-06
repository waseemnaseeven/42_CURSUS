#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include "includes/Colors.hpp"

class Base {
	public:
		virtual ~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};


#endif
