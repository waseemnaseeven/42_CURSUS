/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:10:25 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/08/02 17:02:06 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Brain.hpp"

Brain::Brain() {

	std:: cout << YELLOW << "Brain constructor called" << RESET << std::endl;
	for (int i = 0; i < 100; i++) {
		ideas[i] = "";
	}
}

Brain::Brain(const Brain& src) {
	std:: cout << YELLOW << "Brain copy constructor called" << RESET << std::endl;
	for (int i = 0; i < 100; i++) {
		ideas[i] = src.ideas[i];
	}
}

Brain::~Brain() {
}

Brain& Brain::operator=(const Brain& src) {
    std::cout << YELLOW << "Brain copy assignment operator called." << RESET << std::endl;
	for (int i = 0; i < 100; i++) {
		ideas[i] = src.ideas[i];
	}
	return (*this);
}

void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100) {
        ideas[index] = idea;
    }
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100) {
        return ideas[index];
    }
    return "";
}
