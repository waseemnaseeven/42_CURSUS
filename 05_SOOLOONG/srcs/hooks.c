/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:25:18 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/01/17 15:34:15 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cross_exit(t_game *map)
{
	mlx_destroy_window(map->mlx, map->win);
	mlx_destroy_display(map->mlx);
	free(map->mlx);
	free_map(map);
	map->win = NULL;
	free(map->win);
	exit(1);
}

void	key_error(t_game *map)
{
	mlx_destroy_window(map->mlx, map->win);
	mlx_destroy_display(map->mlx);
	free(map->mlx);
	free_map(map);
	map->win = NULL;
	free(map->win);
	exit(1);
}

int	ft_key_events(t_game *map, int py, int px, int direction)
{
	ft_move_player(map, py, px);
	map->direction = direction;
	ft_put_wallfloor(map);
	ft_put_sprites(map);
	return (1);
}

int	ft_keyboard_events(int key, t_game *map)
{
	if (key == ESC)
		key_error(map);
	if (map->end_game != 1)
	{
		if (key == W)
			ft_key_events(map, -1, 0, 0);
		else if (key == S)
			ft_key_events(map, 1, 0, 0);
		else if (key == D)
			ft_key_events(map, 0, 1, 0);
		else if (key == A)
			ft_key_events(map, 0, -1, 0);
	}
	else
		ft_close_window(map);
	return (1);
}

void	ft_hook(t_game *map)
{
	mlx_hook(map->win, 2, 1L << 0, ft_keyboard_events, map);
	mlx_hook(map->win, 17, 1L << 17, cross_exit, map);
}
