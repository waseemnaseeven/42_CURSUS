/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:04:36 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/31 15:01:20 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Animal.hpp"
#include "includes/Dog.hpp"
#include "includes/Cat.hpp"
#include "includes/WrongCat.hpp"
#include "includes/WrongAnimal.hpp"
#include "includes/Colors.hpp"

int main() {

	std::cout << BOLDMAGENTA << "\n\t========== CONSTRUCTOR ==========\t\n" <<  RESET << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << BOLDMAGENTA << "\n\t========== EVENTS ==========\t\n" <<  RESET << std::endl;
	std::cout << CYAN << j->getType() << " " <<  RESET << std::endl;
	std::cout << RED << i->getType() << " " <<  RESET << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongCat* wrongCat = new WrongCat();
    wrongAnimal->makeSound();
    wrongCat->makeSound();

	std::cout << BOLDMAGENTA << "\n\t========== DESTRUCTOR ==========\t\n" <<  RESET << std::endl;
	delete i;
	delete j;
	delete meta;
	delete wrongAnimal;
	delete wrongCat;

	return 0;
}

