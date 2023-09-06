/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:50:26 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/09/05 17:18:36 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Serialization.hpp"

int main()
{
	Data data;
	data.value = 42;
	data.symbol = 'A';

	uintptr_t ptr_seria = Serializer::serialize(&data);
	std::cout << BOLDCYAN << "\tseria: " << ptr_seria << RESET << std::endl;

	/* le cas ou ca fail */
	uintptr_t modifiedPtr = ptr_seria + 1;
	std::cout << BOLDCYAN << "\tseria: " << modifiedPtr << RESET << std::endl;

	// Data* ptr_deseria = Serializer::deserialize(ptr_seria);
	Data* ptr_deseria = Serializer::deserialize(modifiedPtr);

	if (ptr_deseria == &data)
		draw_tab(ptr_deseria, &data, true);
	else
		draw_tab(ptr_deseria, &data, false);
}

