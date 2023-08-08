/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:51:43 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/10 19:25:43 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Zombie.hpp"

/*
	L'operateur de placement new(&zombies[i]) Zombie(name)
	permet de construire UN objet dans une memoire pre-alloue.
	Il est utilise pour appeler explicitement le constructeur d'un objet
	dans un emplacement memoire specifique.
	new (adresse) Type(constructor_arguments);

	Dans le cas de la fonction zombieHorde, nous utilisons l'opérateur de
	placement new pour construire les objets Zombie directement dans la mémoire
	allouée par new Zombie[N].
*/

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie*	zombies = new Zombie[N]; // Appel du constructeur 'without name'

	for (int i = 0; i < N; i++) {
		new(&zombies[i]) Zombie(name); // Attribution du name
	}
	return (zombies);
}
