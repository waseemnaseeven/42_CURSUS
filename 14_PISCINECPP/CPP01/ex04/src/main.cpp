/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:32:28 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/10 19:55:39 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/sed.hpp"


int main (int ac, char *av[])
{
	if (ac < 4 || ac > 4) {
		std::cout << "Invalid parameters" << std::endl;
		return (1);
	}
	else {
		char* filename = av[1];
		std::string s1 = av[2];
		std::string s2 = av[3];

		replaceString(filename, s1, s2);
	}
	return (0);
}
