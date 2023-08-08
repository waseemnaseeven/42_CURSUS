/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:40:02 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/05 15:23:53 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void	Contact::set_info_contact()
{
	std::cout << "\nEnter First Name:\t";
	std::getline(std::cin, first_name);

	std::cout << "Enter Last Name:\t";
	std::getline(std::cin, last_name);

	std::cout << "Enter Nickname:\t";
	std::getline(std::cin, nickname);

	std::cout << "Enter Phone Number:\t";
	std::getline(std::cin, phone_number);

	std::cout << "Enter Darkest Secret:\t";
	std::getline(std::cin, dark_secret);

	std::cout << "\n";
}

void	Contact::display_contact_info() const
{
	std::cout << "First Name:\t" << first_name << std::endl;
	std::cout << "Last Name:\t" << last_name << std::endl;
	std::cout << "Nickname:\t" << nickname << std::endl;
	std::cout << "Phone Number:\t" << phone_number << std::endl;
	std::cout << "Darkest Secret:\t" << dark_secret << std::endl;
	std::cout << "\n";
}

bool	Contact::is_empty() const
{
	if (first_name.empty() && last_name.empty() && nickname.empty()
		&& phone_number.empty() && dark_secret.empty())
		return (false);
	return (true);
}

std::string	Contact::getInfo(const std::string& str)
{
	if (str == "First Name")
		return (first_name);
	else if (str == "Last Name")
		return (last_name);
	else if (str == "Nickname")
		return (nickname);
	return "";
}
