#include "includes/Span.hpp"

Span::Span(unsigned int N) : _maxSize(N) {
	std::cout << GREEN << "Constructor called " << RESET << std::endl;

}

Span::~Span() {
	std::cout << RED << "Destructor called " << RESET << std::endl;

}

Span::Span(const Span& src) {
	(void) src;
	std::cout << GREEN << "Copy constructor called " << RESET << std::endl;

}

Span& Span::operator=(const Span& src) {
	std::cout << GREEN << "Assignation operator called" << RESET << std::endl;
	if (this != &src) {
		// this->_value = src._value;
	}

	return *this;
}

void Span::addNumber(unsigned int number)
{
	if (tab.size() >= _maxSize)
		throw std::overflow_error("Span is full.");
	tab.push_back(number);
}

unsigned int Span::shortestSpan()
{
	if (tab.empty() || tab.size() == 1)
		throw std::runtime_error("Not enough numbers to find a span");

	std::sort(tab.begin(), tab.end());

    unsigned int minSpan = std::numeric_limits<unsigned int>::max();

    for (size_t i = 0; i < tab.size() - 1; ++i) {
        unsigned int span = tab[i + 1] - tab[i];
        if (span < minSpan)
            minSpan = span;
    }

    return minSpan;
}

unsigned int Span::longestSpan()
{
	if (tab.empty() || tab.size() == 1)
		throw std::runtime_error("Not enough numbers to find a span");

	unsigned int min = find_value(tab, 1);
	unsigned int max = find_value(tab, 2);

	unsigned int ret = (max - min);

	return ret;
}

void Span::addNumbers()
{
	std::srand(time(NULL));
	std::vector<unsigned int> tmp(_maxSize);
	std::generate(tmp.begin(), tmp.end(), send_int);

	for (std::vector<unsigned int>::iterator it=tmp.begin(); it!= tmp.end(); ++it)
		std::cout << *it << " ";
	std::cout << "\n";
	this->tab = tmp;
}

unsigned int send_int()
{
	return (std::rand() % (20 - 10) + 10);
}
