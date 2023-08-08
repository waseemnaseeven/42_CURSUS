/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:27:57 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/08/03 11:59:53 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "includes/Animal.hpp"
#include "includes/Brain.hpp"

class Dog : virtual public Animal {
	public:
		Dog();
		Dog(const Dog& src);
		virtual ~Dog();

	Dog& operator=(const Dog& src);
	void	makeSound() const;
	void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;

	private:
		Brain* dog_brain;

};

#endif
