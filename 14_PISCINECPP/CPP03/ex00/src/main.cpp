/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:57:29 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/31 09:38:36 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ClapTrap.hpp"
#include "includes/Colors.hpp"


int main(void)
{
	std::cout << BOLDMAGENTA << "\t========== CONSTRUCTOR ==========\t" <<  RESET << std::endl;
	ClapTrap claptrap("Was");

	std::cout << BOLDMAGENTA << "\t========== EVENTS ==========\t" <<  RESET << std::endl;

	claptrap.attack("Chien1");
	claptrap.takeDamage(1);
	claptrap.beRepaired(2);

	std::cout << BOLDMAGENTA << "\t========== DESTRUCTOR ==========\t" <<  RESET << std::endl;
	return (0);
}
