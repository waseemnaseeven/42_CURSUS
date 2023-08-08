/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:17:03 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/31 10:13:27 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name)
 : ClapTrap(name) {
	_hitPts = 100;
	_energyPts = 50;
	_attackDmg = 20;
	std::cout << RED << "ScavTrap constructor called for " << _name << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src)
 : ClapTrap(src._name) {
	std::cout << "ScavTrap copy constructor called for " << _name << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap() {
	std::cout << RED << "ScavTrap destructor called for " << _name << RESET << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src) {
	std::cout << "Copy assignment operator called" << std::endl;
	// same as this->_value = other.getRawBits()
	*this = src;
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (_hitPts == 0)
	{
		std::cout << RED << "ScavTrap " << _name << "has no Hit Points" << RESET << std::endl;
		return ;
	}
	if (_energyPts > 0)
	{
		std::cout << RED << "ScavTrap " << _name << " attacks " << target;
		std::cout << ", causing " << _attackDmg << " points of damage!";
		_energyPts--;
	}
	else
	{
		std::cout << "No energyPts, " << _name << " can't do anything.";
		return ;
	}
	std::cout << " Energy points remaining : " << _energyPts << RESET << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << RED << "ScavTrap " << _name << " is now in Gater Mode!" << RESET << std::endl;
}
