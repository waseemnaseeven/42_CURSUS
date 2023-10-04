#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <exception>
#include "includes/Colors.hpp"

class Channel {
	public:
		Channel();
		~Channel();
		Channel(const Channel& src);
		Channel& operator=(const Channel& src);

	private:
		std::string _str;
		int	_value;

};

#endif // CHANNEL_HPP
