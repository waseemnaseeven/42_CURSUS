/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:30:22 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/31 14:53:19 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "includes/Animal.hpp"

class Cat : public Animal {
	public:
		Cat();
		Cat(const Cat& src);
		virtual ~Cat();

		Cat& operator=(const Cat& src);

	void	makeSound() const;
};

#endif
