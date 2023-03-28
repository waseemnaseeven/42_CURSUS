/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkargs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:10:33 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/01/02 19:10:49 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checkargs(int ac, char **av)
{
	int	i;
	int	k;

	i = 0;
	while (++i < ac)
	{
		k = 0;
		while (av[i][k] == ' ' && av[i][k] != '\0')
			k++;
		if (av[i][k] == '\0')
		{
			ft_printf("Error\n");
			exit(1);
		}
	}
	return (0);
}
