/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:11:21 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/01/18 17:13:39 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_open_verif_map(char *file, int *size)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\n");
		ft_printf("Can't open the map\n");
		ft_printf("Please, try again!\n");
		exit(1);
	}
	else
	{
		ft_verif_map(fd, size);
		if (close(fd) != 0)
		{
			ft_printf("Error\n");
			exit(1);
		}
	}
}
