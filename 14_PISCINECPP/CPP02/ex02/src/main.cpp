/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:42:03 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/09/04 12:53:27 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const d(2147483648);
	Fixed const c(10);
	//if (a < c)
	//	std::cout << "a is less than c" << std::endl;
	//if (a > c)
	//	std::cout << "a is greater than c" << std::endl;
	//if (a <= c)
	//	std::cout << "a is less or equal than c" << std::endl;
	//if (a >= c)
	//	std::cout << "a is greater or equal than c" << std::endl;
	//if (a == c)
	//	std::cout << "a is equal to c" << std::endl;
	//if (a != c)
	//	std::cout << "a is different to c" << std::endl;

	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}
