/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:16:08 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/05 14:34:50 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

#include "includes/Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <stdlib.h>

class PhoneBook
{
	public:
		PhoneBook(); // initialise le repertoire avec 0 contact
		~PhoneBook();

	void		add_contact(void); // utilisateur doit remplir les informations
	void		search_contact(void); // affiche seulement ce qui est demandé par l'utilisateur
	std::string	truncate(const std::string& str, size_t max_len);
	int			my_atoi(const std::string& input);

	private:
		static const int	m_max_contact = 9;
		Contact				m_contact[m_max_contact]; // tableau de contact
		int					m_index_contact; // nb actuel de contact dans le repertoire

};

#endif
