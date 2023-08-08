/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:24:58 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/17 14:27:13 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Point.hpp"

Point::Point() : _x(0), _y(0) {
	std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float xCoord, const float yCoord) : _x(xCoord), _y(yCoord) {
	std::cout << "Floats initialized with his parameters" << std::endl;
}

Point::Point(const Point& src) : _x(src._x), _y(src._y) {
	std::cout << "Copy constructor called" << std::endl;
}

Point& Point::operator=(const Point& src) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src) {
		_x = src.getX();
		_y = src.getY();
	}
	return (*this);
}

Point Point::operator-(const Point &src) const {
	return (Point(_x - src._x, _y - src._y));
}

Point::~Point() {
	std::cout << "Destructor called" << std::endl;
}

float Point::getX() const {
	return (_x);
}

float Point::getY() const {
	return (_y);
}

float Point::cross(const Point& src) const {
    return _x * src._y - _y * src._x;
}
