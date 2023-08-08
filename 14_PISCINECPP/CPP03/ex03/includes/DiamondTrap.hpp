/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:45:34 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/31 10:22:27 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "includes/ScavTrap.hpp"
#include "includes/FragTrap.hpp"
#include "includes/Colors.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {

	public:
		DiamondTrap(const std::string& name);
		DiamondTrap(const DiamondTrap& src);
		~DiamondTrap();

	DiamondTrap& operator=(const DiamondTrap& src);
	using ScavTrap::attack;
	void	whoAmI();

	private:
		std::string name;

};

#endif
