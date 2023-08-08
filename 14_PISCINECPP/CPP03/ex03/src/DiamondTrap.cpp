/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:51:52 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/31 10:18:30 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/DiamondTrap.hpp"
#include "includes/Colors.hpp"

DiamondTrap::DiamondTrap(const std::string& name) :
	ClapTrap(name + "_clap_name"),
	ScavTrap(name),
	FragTrap(name),
	name(name)
{
	std::cout << "DiamondTrap constructor called for " << name << std::endl;
	FragTrap::_hitPts = 100;
    ScavTrap::_energyPts = 50;
    FragTrap::_attackDmg = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) :
	ClapTrap(src._name),
	ScavTrap(src._name),
 	FragTrap(src._name)
{
	std::cout << "DiamondTrap copy constructor called for " << _name << std::endl;
	*this = src;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called for " << _name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& src) {
	std::cout << "Copy assignment operator called" << std::endl;
	// same as this->_value = other.getRawBits()
	*this = src;
	return (*this);
}

void DiamondTrap::whoAmI() {
	std::cout << "I am DiamondTrap called " << name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}
