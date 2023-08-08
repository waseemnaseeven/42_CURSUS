/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:42:45 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/27 12:48:58 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/WrongCat.hpp"

WrongCat::WrongCat() {
	_type = "WrongCat";
	std::cout << "WrongCat constructor called. Type: " << _type << std::endl;
}

//WrongCat::WrongCat(const WrongCat& src) {
//	std::cout << "WrongCat copy constructor called" << std::endl;
//	*this = src;
//}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called. Type: " << _type << std::endl;
}

void WrongCat::makeSound() const{
	std::cout << "WrongCat sound." << std::endl;
}
