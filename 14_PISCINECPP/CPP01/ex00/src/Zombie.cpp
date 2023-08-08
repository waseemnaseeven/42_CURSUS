/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:48:48 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/10 19:23:28 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Zombie initialized without name" << std::endl;
}

Zombie::Zombie( std::string name ) : _name(name)
{
	std::cout << "Zombie " << name << " initialized" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Destructor called for zombie " << _name << std::endl;
}

void	Zombie::announce() const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
