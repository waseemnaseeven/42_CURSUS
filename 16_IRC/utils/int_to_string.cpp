#include "../includes/Server.hpp"

string	int_to_string(int n)
{
	std::stringstream ss;

	ss << n;
	return  ss.str();
}