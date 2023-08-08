/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:00:39 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/08/03 12:00:50 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Cat.hpp"

Cat::Cat() {
	_type = "Cat";
	std::cout << RED <<  "Cat constructor called. Type: " << _type << RESET <<std::endl;
}

Cat::Cat(const Cat& src) : Animal (src) {
	std::cout << RED << "Cat copy constructor called for " << _type << RESET << std::endl;
	*this = src;
}

Cat::~Cat() {
	std::cout  << RED << "Cat destructor called for " << _type << RESET << std::endl;
}

Cat& Cat::operator=(const Cat& src) {
    std::cout << RED << "Cat copy assignment operator called. Type: " << _type << RESET << std::endl;
	_type = src._type;
	return (*this);
}

void Cat::makeSound() const{
	std::cout << RED <<  "Meow.." << RESET << std::endl;
}
