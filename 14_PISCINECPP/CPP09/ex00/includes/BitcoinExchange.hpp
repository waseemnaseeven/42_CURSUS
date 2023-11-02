#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <exception>
#include <fstream>
#include <sstream>
#include <map>
#include <cstring>
#include <limits>
#include <ctime>
#include <cstdlib>
#include "includes/Colors.hpp"

class BitcoinExchange {
	private:
		std::multimap<std::string, double> _data;

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& src);
		BitcoinExchange& operator=(const BitcoinExchange& src);

		void fillMap(void);
		void printMap(void);
		void parseInput(std::string filename);
		bool is_date_valid(std::string const &date_str) const;
		std::string is_value_valid(std::string const &value) const;
		double multiply_function(std::string const &date, std::string const &value);

};

#endif // BITCOINEXCHANGE_HPP
