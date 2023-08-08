/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:14:13 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/05 17:53:23 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/PhoneBook.hpp"

int main(void)
{
	PhoneBook	PhoneBook;
	/*
		a partir d'ici, tout ce qu'il y a dans mon constructeur va être déclaré.
	*/
	std::string input;
	std::string get_word = "[Please enter 'ADD' 'SEARCH' or 'EXIT']\n";
	while (1)
	{
		std::cout << "\033[36m" << get_word << "\033[0m" << std::endl;
		std::getline(std::cin, input);
		if (input == "ADD")
			PhoneBook.add_contact();
		else if (input == "SEARCH")
			PhoneBook.search_contact();
		else if (input == "EXIT")
			break;
		else
			std::cout << "Invalid command. Please try again.\n" << std::endl;
	}
	return (0);
}
