#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

#include <iostream>
#include <sstream>
#include <limits>
#include <string>
#include <cmath>
//#include <cstdint>
#include "includes/Colors.hpp"

typedef unsigned long uintptr_t;

struct Data {
	int value;
	char symbol;

};

class Serializer {

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

};

void	draw_tab(uintptr_t raw, Data* ptr, bool flag);

#endif
