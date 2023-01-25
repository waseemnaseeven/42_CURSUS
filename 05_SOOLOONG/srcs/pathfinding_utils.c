/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:48:19 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/01/20 15:03:36 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_patherror(t_game *map)
{
	ft_printf("Error\n");
	ft_printf("Please, provide a valid path\n");
	free_map(map);
	exit (1);
}

void	put_cross_y(t_game *map, int y, int x)
{
	int	tmp_y;

	tmp_y = y;
	while (map->map[y][x] != '1' && y < map->rows)
	{
		map->map[y][x] = 'X';
		y++;
	}
	y = tmp_y;
	while (map->map[y][x] != '1' && y > 0)
	{
		map->map[y][x] = 'X';
		y--;
	}
	y = tmp_y;
}

void	put_cross_x(t_game *map, int y, int x)
{
	int	tmp_x;

	tmp_x = x;
	while (map->map[y][x] != '1' && x > 0)
	{
		map->map[y][x] = 'X';
		x--;
	}
	x = tmp_x;
	while (map->map[y][x] != '1' && x < map->cols)
	{
		map->map[y][x] = 'X';
		x++;
	}
	x = tmp_x;
}

void	put_cross(t_game *map, int y, int x)
{
	put_cross_y(map, y, x);
	put_cross_x(map, y, x);
}

void	before_pathfinding(t_game *map, int p_y, int p_x)
{
	put_cross(map, p_y, p_x);
	p_line(map);
	put_cross_map(map);
}
