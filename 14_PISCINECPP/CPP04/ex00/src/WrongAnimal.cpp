/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:32:28 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/27 12:48:01 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Unknown") {
	std::cout << "WrongAnimal constructor by default called. Type: " << _type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal destructor called. Type: " << _type << std::endl;
}

void	WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal sound." << std::endl;
}

std::string WrongAnimal::getType() const {
	return _type;
}
