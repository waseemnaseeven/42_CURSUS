/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:48:51 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/10 19:19:00 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Zombie.hpp"

int main ()
{
	Zombie zombie;
	Zombie* zombie1 = newZombie("Was");
	zombie1->announce();

	randomChump("Akadil");

	delete zombie1;

	return (0);

}
