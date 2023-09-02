/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:04:36 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/09/01 10:56:19 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Colors.hpp"
#include "includes/Bureaucrat.hpp"

int main() {
	try {
		std::cout << BOLDMAGENTA << "\n\t========== CONSTRUCTOR ==========\t\n" <<  RESET << std::endl;
		Bureaucrat b1("Was", 40);
		Bureaucrat b2("Alicia", 150);

		std::cout << BOLDMAGENTA << "\n\t========== EVENTS ==========\t\n" <<  RESET << std::endl;
		std::cout << b1 << std::endl;
		b1.incrementGrade();
		std::cout << b1 << std::endl;
		b1.decrementGrade();
		std::cout << b1 << std::endl;

		std::cout << b2 << std::endl;
		b1 = b2;
		std::cout << "After the copy constructor : " << b1 << std::endl;
		Bureaucrat b3("Couscous", 151);
		std::cout << b3 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	// std::cout << BOLDMAGENTA << "\n\t========== DELETE ==========\t\n" <<  RESET << std::endl;

	// std::cout << BOLDMAGENTA << "\n\t========== DESTRUCTOR ==========\t\n" <<  RESET << std::endl;

	return (0);
}
