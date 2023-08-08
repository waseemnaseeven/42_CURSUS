/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:37:54 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/07 14:58:28 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/HumanB.hpp"

HumanB::HumanB(const std::string& name) : _weapon(NULL), _nameB(name) {}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &type)
{
	_weapon = &type;
}

void HumanB::attack() const
{
	std::cout << _nameB << " attacks with their " << _weapon->getType() << std::endl;
}


