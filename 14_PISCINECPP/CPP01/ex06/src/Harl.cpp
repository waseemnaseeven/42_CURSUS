/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 11:44:27 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/10 21:42:54 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::debug() const
{
	std::cout << "I love having extra bacon for my" ;
	std::cout << "7XL-double-cheese-triple-pickle-specialketchup burger.";
	std::cout << " I really do !" << std::endl;
}

void	Harl::info() const
{
	std::cout << "I cannot believe adding extra bacon costs more";
	std::cout << "money. You didnt put enough bacon in my burger !";
	std::cout << " If you did, I wouldnt be asking for more !" << std::endl;

}

void	Harl::warning() const
{
	std::cout <<  "I think I deserve to have some extra bacon for";
	std::cout << " free. Ive been coming for years whereas you started";
	std::cout << "working here since last month." << std::endl;
}

void	Harl::error() const
{
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;

}

void	Harl::complain(const std::string level) const
{
	FunctionPtr ptr[4] = {&Harl::debug,  &Harl::info, &Harl::warning, &Harl::error};

	const std::string array[4] = {"debug", "info", "warning", "error"};

	for (int i = 0; i < 4; i++) {
		if (level == array[i])
		{
			(this->*ptr[i])();
			return ;
		}
	}
	std::cout << "Invalid level: " << level << std::endl;
}
