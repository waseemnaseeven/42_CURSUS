/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:40:18 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/07 14:13:02 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "includes/Weapon.hpp"

class HumanB {
	public:
		HumanB(const std::string& name);
		~HumanB();

		void	setWeapon(Weapon &type);
		void	attack() const;

	private:
		Weapon *_weapon;
		std::string _nameB;

};

#endif
