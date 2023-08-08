/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:04:36 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/08/02 17:37:57 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Animal.hpp"
#include "includes/Dog.hpp"
#include "includes/Cat.hpp"
#include "includes/Colors.hpp"
#include "includes/Brain.hpp"

int main() {

	std::cout << BOLDMAGENTA << "\n\t========== CONSTRUCTOR ==========\t\n" <<  RESET << std::endl;
	const Animal *animals[4] = {
		new Dog(),
		new Dog(),
		new Cat(),
		new Cat()
	};


	std::cout << BOLDMAGENTA << "\n\t========== EVENTS ==========\t\n" <<  RESET << std::endl;
	Dog dog1;
    dog1.setIdea(0, "Idea from dog1");
    Dog dog2 = dog1;

    std::cout << "Idea from dog2: " << dog2.getIdea(0) << std::endl;

    dog2.setIdea(0, "Modified idea from dog2");

    std::cout << "Idea from dog1 after modification in dog2: " << dog1.getIdea(0) << std::endl;


	std::cout << BOLDMAGENTA << "\n\t========== DELETE ==========\t\n" <<  RESET << std::endl;

	for (int i = 0; i < 2; i++) {
		delete animals[i];
	}
	for (int i = 2; i < 4; i++) {
		delete animals[i];
	}

	std::cout << BOLDMAGENTA << "\n\t========== DESTRUCTOR ==========\t\n" <<  RESET << std::endl;

	return (0);
}
