/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:26:18 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/01/17 17:43:05 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	p_line(t_game *map)
{
	int	y;
	int	x;

	y = map->p_y;
	x = map->p_x;
	while (map->map[y][x])
	{
		if (map->map[y][x] == 'X')
			put_cross(map, y, x);
		x++;
	}
}

void	put_cross_map(t_game *map)
{
	int	y;
	int	x;
	int	z;

	z = 0;
	while (z < map->rows * map->cols)
	{
		y = 0;
		while (map->map[y])
		{
			x = 0;
			while (map->map[y][x])
			{
				if (map->map[y][x] == 'X')
					put_cross(map, y, x);
				x++;
			}
			y++;
		}
		z++;
	}
}

int	ft_checkpathfinding(t_game *map)
{
	int	i;
	int	x;

	i = 0;
	while (map->map[i])
	{
		x = 0;
		while (map->map[i][x])
		{
			if (map->map[i][x] == 'E' || map->map[i][x] == 'C')
				return (0);
			x++;
		}
		i++;
	}
	return (1);
}

void	load_good_map(char *file, t_game *map)
{
	map->map = ft_creating_map(file, map);
}

void	ft_pathfinding(char *file, t_game *map)
{
	int	p_y;
	int	p_x;

	p_y = map->p_y;
	p_x = map->p_x;
	before_pathfinding(map, p_y, p_x);
	if (ft_checkpathfinding(map) == 0)
		ft_patherror(map);
	free_map(map);
	load_good_map(file, map);
}
