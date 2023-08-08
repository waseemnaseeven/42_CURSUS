/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 09:34:07 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/31 14:51:03 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Animal.hpp"

Animal::Animal() : _type("Unknown"){
	std::cout << GREEN << "Animal constructor by default called. Type: " << _type << RESET << std::endl;
}

Animal::Animal(const Animal& src) {
	std::cout << GREEN << "Animal copy constructor called for " << _type << RESET << std::endl;
	*this = src;
}

Animal::~Animal() {
	std::cout  << GREEN << "Animal destructor called for " << _type << RESET << std::endl;
}

Animal& Animal::operator=(const Animal& src) {
    std::cout << GREEN << "Animal copy assignment operator called. Type: " << _type << RESET << std::endl;
	_type = src._type;
	return (*this);
}

void	Animal::makeSound() const {
	std::cout << GREEN << "Unknown type of animal." << RESET << std::endl;
}

std::string Animal::getType() const {
	return _type;
}

void	Animal::setType(std::string type) {
	this->_type = type;
}

