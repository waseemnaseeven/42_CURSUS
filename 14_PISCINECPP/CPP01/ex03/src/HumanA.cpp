/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:37:31 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/07 15:13:31 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weaponType)
	: _nameA(name), _weapon(weaponType) {}

HumanA::~HumanA() {}

void	HumanA::attack() const
{
	std::cout << _nameA << " attack with their " << this->_weapon.getType() << std::endl;
}


