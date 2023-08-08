/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:35:34 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/07 15:13:34 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "includes/Weapon.hpp"

class HumanA {
	public:
		HumanA(const std::string& name, Weapon& humanWeapon);
		~HumanA();

		void	attack() const;

	private:
		std::string _nameA;
		Weapon &_weapon;

};

#endif
