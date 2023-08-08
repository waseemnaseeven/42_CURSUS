/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:35:15 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/10 19:36:51 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <iomanip>
#include <string>

/*
	le choix d'utiliser un pointeur permet à HumanB
	de ne aps tujours avoir une arme car le pointeur
	peur être défini a NULL alors que la référence non.
	La référence est un pointeur constant, qui ne peut être changé
	elle garantit que HumanA aura toujours une arme
	car une référence doit être liée à un objet existant dès
	sa création.
*/
class Weapon {

	public:
		Weapon(const std::string& weaponType);
		~Weapon();
		const std::string&	getType() const;
		void			setType(const std::string& type);

	private:
		std::string _type;

};

#endif
