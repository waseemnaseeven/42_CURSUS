/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:44:49 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/31 09:45:01 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/FragTrap.hpp"

FragTrap::FragTrap(const std::string& name)
	: ClapTrap(name)
{
	_hitPts = 100;
	_energyPts = 100;
	_attackDmg = 30;
	std::cout << YELLOW << "FragTrap constructor called for " << _name << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap& src)
 : ClapTrap(src._name) {
	std::cout << "FragTrap copy constructor called for " << _name << std::endl;
	*this = src;
}

FragTrap::~FragTrap() {
	std::cout << YELLOW << "FragTrap destructor called for " << _name << RESET << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& src) {
	std::cout << "Copy assignment operator called" << std::endl;
	// same as this->_value = other.getRawBits()
	*this = src;
	return (*this);
}

void	FragTrap::highFivesGuys()
{
	std::cout << YELLOW << "FragTrap " << _name << " request a positive high five!" << RESET << std::endl;
}
