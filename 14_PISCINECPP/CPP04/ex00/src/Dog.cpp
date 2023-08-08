/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:27:43 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/08/03 12:00:38 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Dog.hpp"

Dog::Dog() {
	_type = "Dog";
	std::cout << CYAN << "Dog constructor called. Type: " << _type << RESET << std::endl;
}

Dog::Dog(const Dog& src) : Animal (src){
	std::cout << CYAN << "Dog copy constructor called for " << _type << RESET << std::endl;
	*this = src;
}

Dog::~Dog() {
	std::cout << CYAN << "Dog destructor called for " << _type << RESET << std::endl;
}

Dog& Dog::operator=(const Dog& src) {
    std::cout << CYAN << "Dog copy assignment operator called. Type: " << _type << RESET << std::endl;
	_type = src._type;
	return (*this);
}

void Dog::makeSound() const {
	std::cout << CYAN << "Bark.." << RESET << std::endl;
}


