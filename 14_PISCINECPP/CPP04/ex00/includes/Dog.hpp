/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:27:57 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/08/03 12:00:03 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "includes/Animal.hpp"

class Dog : public Animal {
	public:
		Dog();
		Dog(const Dog& src);
		virtual ~Dog();

	Dog& operator=(const Dog& src);
	virtual void	makeSound() const;

};

#endif
