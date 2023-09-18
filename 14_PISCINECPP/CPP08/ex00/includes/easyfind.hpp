#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <exception>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <utility>
#include <map>
#include <algorithm>
#include "includes/Colors.hpp"

template<typename T>
bool find_info(T& container, int value) {

	try {
		std::vector<int>::iterator trouve = std::find(container.begin(), container.end(), value);
		if (trouve != container.end())
            return true;
        else
            return false;
	} catch (std::exception &e) {
		std::cerr << BOLDRED << "Exception caught: " << RESET << std::endl;
		return false;
	}
}

//class easyfind {
//	public:
//		easyfind();
//		~easyfind();
//		easyfind(const easyfind& src);
//		easyfind& operator=(const easyfind& src);

//	private:
//		std::string _str;
//		int	_value;

//};

#endif // EASYFIND_HPP
