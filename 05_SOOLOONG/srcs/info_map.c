/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:45:26 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/01/18 12:52:58 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_stats(t_game *map)
{
	map->rows = 0;
	map->cols = 0;
	map->end_game = 0;
	map->size = 0;
	map->cols = 0;
	map->rows = 0;
	map->p_x = 0;
	map->p_y = 0;
	map->e_x = 0;
	map->e_y = 0;
	map->move = 0;
	map->e = 0;
	map->c = 0;
	map->p = 0;
}

void	ft_collectinfomap2(t_game *map, int y, int x)
{
	if (map->map[y][x] == 'C')
		map->collectible++;
	else if (map->map[y][x] == 'P')
	{
		map->p_x = x;
		map->p_y = y;
	}
	else if (map->map[y][x] == 'E')
	{
		map->e_x = x;
		map->e_y = y;
	}
}

void	ft_collectinfomap(t_game *map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	map->collectible = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			ft_collectinfomap2(map, y, x);
			x++;
		}
		y++;
	}
	map->rows = y;
	map->cols = --x;
}
