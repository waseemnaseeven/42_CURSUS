#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

#include <iostream>
#include <sstream>
#include <limits>
#include <string>
#include <cmath>
//#include <cstdint>
#include "includes/Colors.hpp"

// representation entiere non signee de pointeurs
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

void	draw_tab(Data* deseria, Data* data, bool flag);

#endif
