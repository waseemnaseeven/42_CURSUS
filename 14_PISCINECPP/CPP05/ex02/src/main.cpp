/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:04:36 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/09/01 09:47:15 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Colors.hpp"
#include "includes/Bureaucrat.hpp"
#include "includes/AForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/PresidentialPardonForm.hpp"


int main() {
	try {
		std::cout << BOLDMAGENTA << "\n 🛠 🛠  ========== CONSTRUCTOR ========== 🛠 🛠 \n" <<  RESET << std::endl;
		Bureaucrat b1("Was", 137);
		Bureaucrat b2("Ali", 46);
		Bureaucrat b3("Wisty",26);
		ShrubberyCreationForm f1("form1");
		RobotomyRequestForm f2("form2");
		PresidentialPardonForm f3("form3");

		std::cout << BOLDMAGENTA << "\n 💻💻 ========== EVENTS ========== 💻💻 \n" <<  RESET << std::endl;
        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;
		std::cout << b3 << std::endl;
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
		std::cout << f3 << std::endl;


        b1.signForm(f1); // This should sign the form1
		b2.signForm(f2); // This should sign the form2
		b3.signForm(f3); // This should sign the form2

		b1.executeForm(f1);
		b2.executeForm(f2);
		b3.executeForm(f3);


		std::cout << BOLDMAGENTA << "\n 💥💥 ========== DESTRUCTOR ========== 💥💥 \n" <<  RESET << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
		// std::cout << BOLDMAGENTA << "\n 🧨🧨 ========== DELETE ========== 🧨🧨 \n" <<  RESET << std::endl;
	return (0);
}
