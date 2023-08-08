/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:49:33 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/06 16:04:28 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <iomanip>
#include <string>


class Zombie {

	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();

	void	announce(void) const;

	private:
		std::string _name;

};

Zombie*	zombieHorde( int N, std::string name );
Zombie* newZombie( std::string name );
void	randomChump( std::string name );

#endif
