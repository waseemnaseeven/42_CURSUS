/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:30:48 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/10 19:27:29 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main ()
{
	std::string msg = "HI THIS IS BRAIN";
    std::string* stringPTR = &msg;
    std::string& stringREF = msg;

    std::cout << "Adresse de la string en mémoire : " << &msg << std::endl;
    std::cout << "Adresse stockée dans stringPTR : " << stringPTR << std::endl;
    std::cout << "Adresse stockée dans stringREF : " << &stringREF << std::endl;
    std::cout << "\n";
    std::cout << "Valeur de la string : " << msg << std::endl;
    std::cout << "Valeur pointée par stringPTR : " << *stringPTR << std::endl;
    std::cout << "Valeur pointée par stringREF : " << stringREF << std::endl;

    return (0);
}
