/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:40:19 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/05 13:38:41 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <stdlib.h>

class Contact
{
	public:
		Contact();
		~Contact();

	void		set_info_contact();
	void		display_contact_info() const;
	bool		is_empty() const;
	std::string	getInfo(const std::string& str);
	
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string dark_secret;

};

#endif
