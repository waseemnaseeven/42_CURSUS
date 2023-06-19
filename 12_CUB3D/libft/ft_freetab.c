/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:06:09 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/02/27 17:48:39 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_freetab(char **tab, int boolean)
{
	int		i;

	i = 0;
	if (!tab || !tab[0])
		return (1);
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	if (boolean)
		return (0);
	ft_printf("Error\n");
	exit(1);
}
