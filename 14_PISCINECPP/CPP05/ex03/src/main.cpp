/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:04:36 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/09/02 10:57:18 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Colors.hpp"
#include "includes/Bureaucrat.hpp"
#include "includes/AForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/Intern.hpp"


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


        b1.signForm(f1);
		b2.signForm(f2);
		b3.signForm(f3);

		b1.executeForm(f1);
		b2.executeForm(f2);
		b3.executeForm(f3);
		Intern someRandomIntern;
		AForm *rrf;

		rrf = someRandomIntern.makeForm("pardon", "Bender");
		//b1.signForm(*rrf);
		//std::cout << rrf->getName() << std::endl;
		//std::cout << b1 << std::endl;

		std::cout << BOLDMAGENTA << "\n 🧨🧨 ========== DELETE ========== 🧨🧨 \n" <<  RESET << std::endl;

		if (rrf != NULL)
		{
			std::cout << RED << "delete " << *rrf << RESET << std::endl;
			delete rrf;
		}

		std::cout << BOLDMAGENTA << "\n 💥💥 ========== DESTRUCTOR ========== 💥💥 \n" <<  RESET << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	return (0);
}
