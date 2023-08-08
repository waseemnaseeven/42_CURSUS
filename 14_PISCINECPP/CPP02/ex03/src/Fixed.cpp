/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:42:16 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/12 12:04:52 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Fixed.hpp"

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int n) : _value(n << fractionalBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n) : _value(static_cast<float>(roundf(n * (1 << fractionalBits)))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
    setRawBits(other.getRawBits());
	// same as this->_value = other.getRawBits()
	return (*this);
}

bool Fixed::operator<(const Fixed& other) const {
	return (this->_value < other.getRawBits());
}

bool Fixed::operator>(const Fixed& other) const {
	return (this->_value > other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other) const {
	return (this->_value <= other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other) const {
	return (this->_value >= other.getRawBits());
}

bool Fixed::operator==(const Fixed& other) const {
	return (this->_value == other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other) const {
	return (this->_value != other.getRawBits());
}

Fixed Fixed::operator+(const Fixed &src) const {
    return (Fixed(this->toFloat() + src.toFloat()));
}

Fixed Fixed::operator-(const Fixed &src) const {
    return (Fixed(this->toFloat() - src.toFloat()));
}

Fixed Fixed::operator*(const Fixed &src) const {
    return (Fixed(this->toFloat() * src.toFloat()));
}

Fixed Fixed::operator/(const Fixed &src) const {
    return (Fixed(this->toFloat() / src.toFloat()));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const {
	return (this->_value);
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

float Fixed::toFloat() const {
	return static_cast<float>(this->_value) / (1 << fractionalBits);
}

int Fixed::toInt() const {
	return (this->getRawBits() >> this->fractionalBits);

}

std::ostream & operator<<(std::ostream & o, Fixed const & other) {
  	o << other.toFloat();
    return o;
}

