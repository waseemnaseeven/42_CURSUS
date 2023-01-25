/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:11:02 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/01/23 14:29:50 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_end_game(t_game *map)
{
	mlx_destroy_window(map->mlx, map->win);
	mlx_destroy_display(map->mlx);
	free(map->mlx);
	free_map(map);
	ft_printf("You have done the game with [%d] moves\n", map->move);
	ft_printf("can you do better ?\n");
	exit(1);
}

int	ft_close_window(t_game *map)
{
	if (map->end_game == 1)
		ft_end_game(map);
	return (1);
}

void	ft_collect(t_game *map, int y, int x)
{
	int	p_y;
	int	p_x;

	p_y = map->p_y;
	p_x = map->p_x;
	ft_remove_collectible(&map->map[p_y][p_x], &map->map[p_y + y][p_x + x]);
}

void	ft_exit(t_game *map, int y, int x)
{
	int	p_y;
	int	p_x;

	p_y = map->p_y;
	p_x = map->p_x;
	if (map->collectible == 0)
	{
		ft_remove_exit(&map->map[p_y][p_x], &map->map[p_y + y][p_x + x]);
		map->end_game = 1;
		ft_printf("You may quit this game\n");
	}
	else
		ft_printf("Please, collect all the kyubi !!\n");
}

void	ft_move_player(t_game *map, int y, int x)
{
	int		p_x;
	int		p_y;

	p_y = map->p_y;
	p_x = map->p_x;
	if (map->map[p_y + y][p_x + x] != '1')
	{
		if (map->map[p_y + y][p_x + x] == '0')
			ft_swap_tiles(&map->map[p_y][p_x], &map->map[p_y + y][p_x + x]);
		else if (map->map[p_y + y][p_x + x] == 'E' && map->collectible > 0)
			ft_swap_exit(&map->map[p_y][p_x], &map->map[p_y + y][p_x + x]);
		else if (map->map[p_y + y][p_x + x] == 'C')
			ft_collect(map, y, x);
		else if (map->map[p_y + y][p_x + x] == 'E' && map->collectible == 0)
			ft_exit(map, y, x);
		ft_printf("Move : [%d]\n", ++map->move);
	}
	ft_collectinfomap(map);
}
