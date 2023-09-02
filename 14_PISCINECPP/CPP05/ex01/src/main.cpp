/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:04:36 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/08/03 11:54:12 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Colors.hpp"
#include "includes/Bureaucrat.hpp"
#include "includes/Form.hpp"

int main() {

	try {
		std::cout << BOLDMAGENTA << "\n 🛠 🛠  ========== CONSTRUCTOR ========== 🛠 🛠 \n" <<  RESET << std::endl;
		Bureaucrat b1("Was", 99);
		Bureaucrat b2("Ali", 10);
		Form f1("Form1", 100, 50);
		Form f2("Form2", 10, 2);

		std::cout << BOLDMAGENTA << "\n 💻💻 ========== EVENTS ========== 💻💻 \n" <<  RESET << std::endl;
        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;


        b1.signForm(f1); // This should sign the form1
		b2.signForm(f2); // This should sign the form2
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
        
		/* Changing the tests */
        b1.incrementGrade();
        b1.signForm(f1);// This should sign the form1

        b2.decrementGrade();
        b2.signForm(f2); // This should throw Form::GradeTooLowException

        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;

		
		std::cout << BOLDMAGENTA << "\n 💥💥 ========== DESTRUCTOR ========== 💥💥 \n" <<  RESET << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
		// std::cout << BOLDMAGENTA << "\n 🧨🧨 ========== DELETE ========== 🧨🧨 \n" <<  RESET << std::endl;
	return (0);
}
