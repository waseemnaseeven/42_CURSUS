/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:00:39 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/08/02 16:59:50 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Cat.hpp"

Cat::Cat() : cat_brain(new Brain()){
	_type = "Cat";
	std::cout << RED <<  "Cat constructor called. Type: " << _type << RESET <<std::endl;
}

Cat::Cat(const Cat& src) : Animal(src), cat_brain(new Brain(*src.cat_brain)) {
	std::cout << RED << "Cat copy constructor called for " << _type << RESET << std::endl;
}

Cat::~Cat() {
	delete cat_brain;
	std::cout  << RED << "Cat destructor called for " << _type << RESET << std::endl;
}

Cat& Cat::operator=(const Cat& src) {
    std::cout << RED << "Cat copy assignment operator called. Type: " << _type << RESET << std::endl;
	// Appel de la classe de base
    Animal::operator=(src);

    // Copie du pointeur de cat_brain
    *cat_brain = *src.cat_brain;

	return (*this);
}

void Cat::makeSound() const{
	std::cout << RED <<  "Meow.." << RESET << std::endl;
}

void Cat::setIdea(int index, const std::string& idea) {
    cat_brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const {
    return cat_brain->getIdea(index);
}
