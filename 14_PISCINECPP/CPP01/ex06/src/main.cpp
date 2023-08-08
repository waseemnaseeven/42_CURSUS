/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 11:44:25 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/10 21:54:13 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Harl.hpp"

int	ConvertMsgForSwitch(std::string msg)
{
	if (msg == "DEBUG" || msg == "debug")
		return (1);
	else if (msg == "INFO" || msg == "info")
		return (2);
	else if (msg == "WARNING" || msg == "warning")
		return (3);
	else if (msg == "ERROR" || msg == "error")
		return (4);
	else
		return (0);
}

int main (int ac, char* av[])
{
	(void) av;
	if (ac < 2 || ac > 2)
	{
		std::cout << "Invalid parameters" << std::endl;
		return (0);
	}
	Harl		harl;
	std::string msg = av[1];
	int 		gravity = ConvertMsgForSwitch(msg);


	switch (gravity) {
		case 1:
			harl.complain("debug");
			harl.complain("info");
			harl.complain("warning");
			harl.complain("error");
			break;
		case 2:
			harl.complain("info");
			harl.complain("warning");
			harl.complain("error");
			break;
		case 3:
			harl.complain("warning");
			harl.complain("error");
			break;
		case 4:
			harl.complain("error");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return (0);

}
