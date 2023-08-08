/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 09:09:37 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/08/03 11:56:29 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include "Colors.hpp"

class Animal {

	public:
		Animal();
		Animal(const Animal& src);
		virtual ~Animal();

	Animal& operator=(const Animal& src);

	virtual void makeSound() const;
	virtual std::string getType() const;
	virtual void setType(std::string type);

	protected:
		std::string _type;
};

#endif
