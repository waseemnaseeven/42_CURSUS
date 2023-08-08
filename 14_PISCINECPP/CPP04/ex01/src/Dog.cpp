/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:27:43 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/08/02 16:56:26 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Dog.hpp"

Dog::Dog() : dog_brain(new Brain()){
	_type = "Dog";
	std::cout << CYAN << "Dog constructor called. Type: " << _type << RESET << std::endl;
}

Dog::Dog(const Dog& src) : Animal(src), dog_brain(new Brain(*src.dog_brain)) {
	std::cout << CYAN << "Dog copy constructor called for " << _type << RESET << std::endl;
}

Dog::~Dog() {
	delete dog_brain;
	std::cout << CYAN << "Dog destructor called for " << _type << RESET << std::endl;
}

Dog& Dog::operator=(const Dog& src) {
    std::cout << CYAN << "Dog copy assignment operator called. Type: " << _type << RESET << std::endl;
	// Appel de la classe de base
    Animal::operator=(src);

    // Copie du pointeur de dog_brain
    *dog_brain = *src.dog_brain;

	return (*this);
}

void Dog::makeSound() const {
	std::cout << CYAN << "Bark.." << RESET << std::endl;
}

void Dog::setIdea(int index, const std::string& idea) {
    dog_brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const {
    return dog_brain->getIdea(index);
}
