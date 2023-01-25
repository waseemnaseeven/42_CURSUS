/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:42:54 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/01/20 16:29:01 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_wallfloor(t_game *map)
{
	static void	*r_tile;
	t_img		tile;
	int			x;
	int			y;

	y = 0;
	while (y < map->rows)
	{
		x = 0;
		tile.h = y * 32;
		while (x < map->cols)
		{
			tile.w = x * 32;
			if (map->map[y][x] == '0')
				ft_rendertile(map, r_tile, tile);
			else if (map->map[y][x] == '1')
				ft_renderwalls(map, r_tile, tile);
			x++;
		}
		y++;
	}
}

void	ft_put_sprites(t_game *map)
{
	static void	*r_tile;
	t_img		tile;
	int			x;
	int			y;

	y = 0;
	while (y < map->rows)
	{
		x = 0;
		tile.h = y * 32;
		while (x < map->cols)
		{
			tile.w = x * 32;
			if (map->map[y][x] == 'C')
				ft_renderkyubi(map, r_tile, tile);
			else if (map->map[y][x] == 'P')
				ft_renderplayer(map, r_tile, tile);
			else if (map->map[y][x] == 'E' && map->collectible == 0)
				ft_renderexit(map, r_tile, tile);
			else if ((map->map[y][x] == 'E' && map->collectible > 0))
				ft_rendertile(map, r_tile, tile);
			x++;
		}
		y++;
	}
}

void	ft_render_map(t_game *map)
{
	int	screen_w;
	int	screen_h;

	screen_w = map->cols * 32;
	screen_h = map->rows * 32;
	map->mlx = mlx_init();
	if (map->mlx == NULL)
		exit (1);
	map->win = mlx_new_window(map->mlx, screen_w, screen_h, "42 genjutsu");
	if (map->win == NULL)
	{
		free(map->win);
		exit(1);
	}
	ft_put_wallfloor(map);
	ft_put_sprites(map);
	ft_hook(map);
	mlx_loop(map->mlx);
}
