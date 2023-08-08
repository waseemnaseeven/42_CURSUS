/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:15:33 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/05 15:25:24 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/PhoneBook.hpp"

PhoneBook::PhoneBook() : m_index_contact(1) {} // init le tableau

PhoneBook::~PhoneBook() {}

void	PhoneBook::add_contact(void)
{
	Contact new_contact;
	new_contact.set_info_contact();
	if (new_contact.is_empty() != false)
	{
		m_contact[m_index_contact] = new_contact;
		std::cout << "Contact [" << m_index_contact << "] has been added successfully."<< std::endl;
		std::cout << "\n";
		m_index_contact++;
		if (m_index_contact == m_max_contact)
			m_index_contact = 1;
	}
	else
		std::cout << "Invalid register, please try again." << std::endl;
}

void	PhoneBook::search_contact()
{
	if (m_index_contact == 1)
	{
		std::cout << "\nPhoneBook is empty. No contacts to display.\n" << std::endl;
		return ;
	}
	std::cout << "\n" << std::setw(10) << "Index" << " | "
		<< std::setw(10) << "First Name" << " | "
		<< std::setw(10) << "Last Name" << " | "
		<< std::setw(10) << "Nickname" << std::endl;

	for (int i = 1; i < m_max_contact; i++)
	{
		std::cout << std::setw(10) << i
			<< " | " << std::setw(10)
			<< truncate(m_contact[i].getInfo("First Name"), 10)
			<< " | " << std::setw(10)
			<< truncate(m_contact[i].getInfo("Last Name"), 10)
			<< " | " << std::setw(10)
			<< truncate(m_contact[i].getInfo("Nickname"), 10) << std::endl;
	}

	std::cout << "\nEnter the index of the contact to display: " << std::endl;
	bool valid_input = false;
	std::string input;
	while (valid_input == false)
	{
		std::getline(std::cin, input);
		int index = my_atoi(input);
		if (index >= 1 && index < m_max_contact)
		{
			valid_input = true;
			std::cout << "\n";
			m_contact[index].display_contact_info();
		}
		else
			std::cout << "Invalid index. Contact not found. Please try again." << std::endl;
	}
}

std::string PhoneBook::truncate(const std::string& str, size_t max_len)
{
	if (str.length() <= max_len)
		return (str);
	else
		return (str.substr(0, max_len - 1) + ".");
}

int	PhoneBook::my_atoi(const std::string& input)
{
	int	res = 0;
	int	sign = 1;
	int	i = 0;

	while (input[i] == 32 || (input[i] >= 9 && input[i] <= 13))
		i++;
	if (input[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (input[i] >= '0' && input[i] <= '9')
	{
		res = res * 10 + (input[i] - '0');
		i++;
	}
	return (res * sign);
}

