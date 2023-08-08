/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:42:16 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/27 16:20:27 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Fixed.hpp"

Fixed::Fixed() : _value(0) {

}

Fixed::Fixed(const Fixed& other) {
	*this = other;
}

Fixed::Fixed(const int n) : _value(n << fractionalBits) {

}

Fixed::~Fixed() {

}

Fixed::Fixed(const float n) : _value(static_cast<float>(roundf(n * (1 << fractionalBits)))) {

}

Fixed& Fixed::operator=(const Fixed& other) {
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

Fixed Fixed::operator++() {
	++_value;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed old = *this;
	++_value;
	return (old);
}

Fixed Fixed::operator--() {
	--_value;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed old = *this;
	--_value;
	return (old);
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
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

