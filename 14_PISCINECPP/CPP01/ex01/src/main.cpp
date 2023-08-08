/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:51:03 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/10 19:28:28 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Zombie.hpp"

int main ()
{
	Zombie 		*zombies;
	const int	N = 5;

	zombies = zombieHorde(N, "Was");

	for (int i = 0; i < N; i++) {
		zombies[i].announce(); // <name> : message
	}

	delete[] (zombies); // Destructeur de tous les zombies nommés

	return (0);
}

