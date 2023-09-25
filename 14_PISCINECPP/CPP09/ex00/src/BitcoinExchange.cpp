#include "includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	std::cout << GREEN << "Constructor called for " << RESET << std::endl;

}

BitcoinExchange::~BitcoinExchange() {
	std::cout << RED << "Destructor called for " << RESET << std::endl;

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) {
	(void) src;
	std::cout << GREEN << "Copy constructor called for " << RESET << std::endl;

}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src) {
	std::cout << GREEN << "Assignation operator called" << RESET << std::endl;
	if (this != &src) {
		this->_value = src._value;
	}

	return *this;
}

void BitcoinExchange::fillMap()
{
	std::string database = "./data.csv";
	std::ifstream file;
	std::string delimiter2 = ",";
	std::string line;
	std::string token;

	file.open(database.c_str());

	if (file.fail())
	{
		throw std::invalid_argument("can't open the file");
		file.close();
		return ;
	}

	while (getline(file, line)) {
		size_t found = line.find(delimiter2);
		size_t pos = 0;
		size_t pos2 = 0;
		if (found != std::string::npos) {
			token = line.substr(pos, found - pos);
			pos2 = found + 1;
			found = line.find(delimiter2, pos2);
		}
		std::string date = line.substr(0, pos2 - 1);
		token = line.substr(pos2);
		char *endptr;
		double value = strtod(token.c_str(), &endptr);
		_data.insert(std::make_pair(date, value));
	}

	file.close();
}

void BitcoinExchange::parseInput(std::string filename)
{
	//std::cout << "pb sur input.txt" << std::endl;
	std::ifstream input;
	input.open(filename.c_str());
	if (!input) {
		throw std::invalid_argument("can't open the file");
		input.close();
		return ;
	}
	std::string line;
	std::string date;
	std::string value;
	std::string header = "date | value";
	BitcoinExchange tmp;
	if (std::getline(input, line))
		if (strcmp(line.c_str(), header.c_str()))
			std::cerr << PURPLE << "Error: No header found" << RESET << std::endl;
	while (std::getline(input, line)) {
		// si la date ainsi que le pipe ainsi que la valeur après le pipe sont corrects
			// alors conversion sinon message cerr
		if (line.empty())
		{
			std::cerr << PURPLE << "Error: empty line" << RESET << std::endl;
			continue ;
		}

		std::string date = line.substr(0, line.find(" |"));
   		if (!this->is_date_valid(date))
		{
			std::cerr << PURPLE << "Error: bad input => " << date << RESET << std::endl;
			continue ;
		}

		if (line.find("|") == std::string::npos) // ne se trouve pas dans la ligne
		{
			std::cerr << PURPLE << "Error: no pipe" << RESET << std::endl;
			continue ;
		}

		std::string value = line.substr(line.find("| ") + 2);
		std::string error_message = is_value_valid(value);
		if (!error_message.empty())
		{
		    std::cerr << PURPLE << "Error: " << tmp.is_value_valid(value) << RESET << std::endl;
			continue ;
		}

		double res = multiply_function(date, value);
		std::cout << CYAN << date << " => " << value << " = " << res << RESET << std::endl;
	}

	input.close();
}

double BitcoinExchange::multiply_function(std::string const &date, std::string const &value)
{

	// Rechercher la date la plus proche ou exacte avec lower_bound()
	std::map<std::string, double>::const_iterator it = _data.lower_bound(date);
	if (it->first == date)
	{
		// std::cout << "date trouvée: " << it->first << " valeur trouvée: " << it->second << std::endl;
		double res = it->second * std::atof(value.c_str());
		return res;
	}
	else if (it != _data.end() || it->first != date)
	{
		if (it == _data.begin())
			return 0.0;
		--it; // Sinon on se déplace vers la date précédente
	}

	// std::cout << "date trouvée: " << it->first << " valeur trouvée: " << it->second << std::endl;
	double res = it->second * std::atof(value.c_str());
	return res;

}

std::string BitcoinExchange::is_value_valid(std::string const &value) const
{
	double convert = std::atof(value.c_str());
	unsigned int dot = 0;
	std::string not_int = "not an integer.";

	if (convert < 0)
		return "not a positive number.";

	if (convert > 1000)
		return "too large a number.";
	for (size_t i = 0; i < value.size(); i++) {
		if (value[i] == '.')
		{
			dot++;
			continue;
		}

		if (!std::isdigit(value[i]))
			return not_int;
	}
	if (dot > 1)
		return not_int;

	return "";
}

bool BitcoinExchange::is_date_valid(std::string const &date) const
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	int year, month, day;
    if (std::sscanf(date.c_str(), "%4d-%2d-%2d", &year, &month, &day) != 3) {
        return false;
	}

	if (year < 2000 || year > 2023 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

	return true;

}

void BitcoinExchange::printMap(void)
{
	for (std::multimap<std::string, double>::iterator it = _data.begin(); it != _data.end(); ++it) {
        std::cout << "Date is: " << it->first << " and the value is: " << it->second << std::endl;
    }
}

