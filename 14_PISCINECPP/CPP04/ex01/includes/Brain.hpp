/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:59:54 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/08/02 17:01:59 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "includes/Animal.hpp"
#include "includes/Colors.hpp"

class Brain {

	public:
		Brain();
		Brain(const Brain& src);
		~Brain();

	Brain& operator=(const Brain& src);
	void setIdea(int index, const std::string& idea);
	std::string getIdea(int index) const;

	private:
		std::string ideas[100];

};

#endif
