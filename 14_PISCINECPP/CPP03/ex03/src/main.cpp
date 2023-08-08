/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:57:29 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/31 10:20:39 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/DiamondTrap.hpp"
#include "includes/ScavTrap.hpp"
#include "includes/ClapTrap.hpp"
#include "includes/FragTrap.hpp"

int main(void)
{
	std::cout << BOLDMAGENTA << "\t========== CONSTRUCTOR ==========\t" <<  RESET << std::endl;
    ClapTrap 	clapTrap("Was");
    ScavTrap 	scavTrap("Nico");
	FragTrap 	fragtrap("Akadil");
	DiamondTrap	diamondtrap("Nassim");

	std::cout << BOLDMAGENTA << "\t========== EVENTS ==========\t" <<  RESET << std::endl;
    clapTrap.attack("Chien1");
    clapTrap.takeDamage(5);
    clapTrap.attack("Chien2");
    clapTrap.beRepaired(3);
    clapTrap.attack("Chien3");
    clapTrap.takeDamage(15);
    clapTrap.beRepaired(10);

    scavTrap.guardGate();
    scavTrap.attack("Chien1");
    scavTrap.takeDamage(50);
    scavTrap.beRepaired(20);
    scavTrap.attack("Chien2");

	fragtrap.highFivesGuys();
	fragtrap.attack("Chien1");
    fragtrap.takeDamage(40);
    fragtrap.beRepaired(50);
	fragtrap.attack("Chien2");

	diamondtrap.whoAmI();
	diamondtrap.attack("Chien1");
	diamondtrap.highFivesGuys();
    diamondtrap.takeDamage(40);
    diamondtrap.beRepaired(50);
	diamondtrap.attack("Chien2");

	std::cout << BOLDMAGENTA << "\t========== DESTRUCTOR ==========\t" <<  RESET << std::endl;
	return (0);
}
