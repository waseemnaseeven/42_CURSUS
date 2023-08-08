/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:42:16 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/11 16:53:41 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Fixed.hpp"

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _value(other._value) {
	std::cout << "Copy constructor called" << std::endl;
}

/*

	operator= effectue operation d'assignation en 2 objets
	elle vérifie si l'objet source (other) est différent de l'objet actuel (this)
	pour éviter une auto-assignation indésirable.
	ensuite elle copie simplement la valeur de _value de l'objet source
	dans _value de l'objet actuel.

	Cette fonction permet de faire une copie profonde des données de l'objet source
	vers l'objet actuel, en s'assurant qu'ils restent indépendants l'un de l'autre.
	Cela garantit que les deux objets Fixed peuvent être utilisés et modifiés
	séparément après l'opération d'assignation.

*/

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
    this->_value = other.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

