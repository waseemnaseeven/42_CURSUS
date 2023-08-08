/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:17:04 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/31 09:43:03 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ClapTrap.hpp"
#include "includes/Colors.hpp"

ClapTrap::ClapTrap(const std::string& name)
	: _name(name),
	  _hitPts(10),
	  _energyPts(10),
	  _attackDmg(0)
{

	std::cout << GREEN << "ClapTrap constructor by default called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src) {
	std::cout << "ClapTrap copy constructor called for " << _name << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap() {
	std::cout  << GREEN << "ClapTrap destructor called for " << _name << RESET << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src) {
	std::cout << "Copy assignment operator called" << std::endl;
	// same as this->_value = other.getRawBits()
	*this = src;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hitPts == 0)
	{
		std::cout << BLUE << "ClapTrap " << _name << "has no Hit Points" << RESET << std::endl;
		return ;
	}
	if (_energyPts > 0)
	{
		std::cout << BLUE << "ClapTrap " << _name << " attacks " << target;
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

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPts > 0)
	{
		if (amount >= _hitPts)
		{
			_hitPts = 0;
			std::cout << BLUE << "ClapTrap " << _name << " takes " << amount << " points of damage and is destroyed" << RESET << std::endl;
		}
		else
		{
			_hitPts -= amount;
			std::cout << BLUE << "ClapTrap " << _name << " takes " << amount << " points of damage";
			std::cout << " Hit points remaining : " << _hitPts << RESET << std::endl;
		}
	}
	else
	    std::cout << BLUE << "ClapTrap " << _name << " is already destroyed. No hit points left." << RESET << std::endl;

}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPts == 0)
	{
		std::cout << BLUE << "ClapTrap " << _name << " has no Hit Points" << std::endl;
		return ;
	}
	if (_energyPts > 0)
	{
		_hitPts += amount;
		if (_hitPts > 100)
			_hitPts = 100;
		std::cout << BLUE << "ClapTrap " << _name << " is repaired for " << amount << " points. Hit points remaining : " << _hitPts;
		_energyPts--;
	}
	else
	{
		std::cout << "No energyPts, " << _name << " can't do anything.";
		return ;
	}
	std::cout << " Energy points remaining : " << _energyPts << RESET << std::endl;
}
