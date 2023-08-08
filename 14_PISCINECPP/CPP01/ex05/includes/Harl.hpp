/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 11:44:22 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/08 19:30:48 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Harl {

	public:
		Harl();
		~Harl();
	typedef void (Harl::*FunctionPtr)() const;
	void	complain(const std::string level) const;

	private:
		void debug() const;
		void info() const;
		void warning() const;
		void error() const;

};


#endif
