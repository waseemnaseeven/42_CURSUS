/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:30:22 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/08/02 16:59:59 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "includes/Animal.hpp"
#include "includes/Brain.hpp"

class Cat : virtual public Animal {
	public:
		Cat();
		Cat(const Cat& src);
		virtual ~Cat();

		Cat& operator=(const Cat& src);

	void	makeSound() const;
	void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;

	private:
		Brain* cat_brain;

};

#endif
