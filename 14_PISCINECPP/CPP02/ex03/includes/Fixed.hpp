/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:42:24 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/12 12:07:06 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

class Fixed {

	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed(const int n);
		Fixed(const float n);
		~Fixed();

		Fixed& operator=(const Fixed& other);

		bool operator<(const Fixed& other) const;
		bool operator>(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;

		Fixed operator+(const Fixed &fixed) const;
   		Fixed operator-(const Fixed &fixed) const;
    	Fixed operator*(const Fixed &fixed) const;
    	Fixed operator/(const Fixed &fixed) const;

		Fixed operator++();
		Fixed operator++(int);
		Fixed operator--();
		Fixed operator--(int);

		int		getRawBits( void ) const;
		void 	setRawBits( int const raw );
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int	_value;
		static const int fractionalBits = 8;
};

std::ostream & operator<<(std::ostream & o, Fixed const & other);

#endif /* FIXED_HPP */
