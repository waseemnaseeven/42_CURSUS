/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:55:14 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/10 20:00:55 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/sed.hpp"

std::string my_strcat(std::string filename)
{
	std::string newfile;
	std::string replace = ".replace";
	return (filename + replace);
}

void	replaceString(std::string filename, std::string s1, std::string s2)
{
	std::ifstream input;
	input.open(filename.c_str()); // c_str pour obtenir un pointeur const char*
	if (!input) {
		std::cout << "can't open the file" << std::endl;
		input.close();
		return ;
	}
	std::string outputname = my_strcat(filename);
	std::ofstream output(outputname.c_str());
	if (!output) {
		std::cout << "Can't create the output file" << std::endl;
		return ;
	}
	std::string line;
	/*
		found localise la premiere occurence de s1
		pos va servir a trouver s'il y a d'autres occurence de s1 dans line
		Tant que S1 se trouve dans ma ligne
			alors on ajoute la sous chaine a la ligne
			on recalcule la position de depart (donc found) + la suite de la chaine
			on recalcule found pour savoir s'il retrouve s1 à la position de pos
		S'il ne trouve plus alors il n'y a plus qu'a ajouter la sous-chaine à line
		puis de l'afficher.
	*/
	while (std::getline(input, line)) {
		std::string modify;
		size_t found = line.find(s1);
		size_t pos = 0;
		while (found != std::string::npos) {
			modify += line.substr(pos, found - pos) + s2;
			pos = found + s1.length();
			found = line.find(s1, pos);
		}
		modify += line.substr(pos);
		output << modify << std::endl;
	}

	input.close();
	output.close();
}

