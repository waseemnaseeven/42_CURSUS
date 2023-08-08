/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:42:08 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/30 20:03:12 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "includes/ClapTrap.hpp"
#include "includes/Colors.hpp"

class FragTrap : virtual public ClapTrap {

	public:
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& src);
		~FragTrap();

	FragTrap& operator=(const FragTrap& src);

	void	highFivesGuys();
};

#endif
