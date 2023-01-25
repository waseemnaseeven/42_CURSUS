/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:50:01 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/01/18 15:19:38 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_line(char *line)
{
	get_next_line(0, 1);
	free(line);
}

void	full_free(t_game *map)
{
	int	y;

	y = 0;
	while (map->map[y])
	{
		free(map->map[y]);
		y++;
	}
	free(map->map);
}

void	free_map(t_game *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map[i]);
	free(map->map);
}

void	ft_print_map(t_game map)
{
	int	j;

	j = 0;
	while (map.map[j])
	{
		printf("%s", map.map[j]);
		j++;
	}
}

void	display(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		ft_printf("%s", map[i]);
}
