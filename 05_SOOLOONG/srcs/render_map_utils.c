/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:28:19 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/01/17 17:42:46 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_rendertile(t_game *map, void *r_tile, t_img tile)
{
	int	d;

	d = 64;
	r_tile = mlx_xpm_file_to_image(map->mlx, "./img/water.xpm", &d, &d);
	if (!r_tile)
		key_error(map);
	mlx_put_image_to_window(map->mlx, map->win, r_tile, tile.w, tile.h);
	mlx_destroy_image(map->mlx, r_tile);
}

void	ft_renderwalls(t_game *map, void *r_tile, t_img tile)
{
	int	d;

	d = 64;
	r_tile = mlx_xpm_file_to_image(map->mlx, "./img/wall3.xpm", &d, &d);
	if (!r_tile)
		key_error(map);
	mlx_put_image_to_window(map->mlx, map->win, r_tile, tile.w, tile.h);
	mlx_destroy_image(map->mlx, r_tile);
}

void	ft_renderkyubi(t_game *map, void *r_tile, t_img tile)
{
	int	d;

	d = 64;
	r_tile = mlx_xpm_file_to_image(map->mlx, "./img/kyubi.xpm", &d, &d);
	if (!r_tile)
		key_error(map);
	mlx_put_image_to_window(map->mlx, map->win, r_tile, tile.w, tile.h);
	mlx_destroy_image(map->mlx, r_tile);
}

void	ft_renderplayer(t_game *map, void *r_tile, t_img tile)
{
	int	d;

	d = 64;
	r_tile = mlx_xpm_file_to_image(map->mlx, "./img/narutother.xpm", &d, &d);
	if (!r_tile)
		key_error(map);
	mlx_put_image_to_window(map->mlx, map->win, r_tile, tile.w, tile.h);
	mlx_destroy_image(map->mlx, r_tile);
}

void	ft_renderexit(t_game *map, void *r_tile, t_img tile)
{
	int	d;

	d = 64;
	r_tile = mlx_xpm_file_to_image(map->mlx, "./img/sharingan.xpm", &d, &d);
	if (!r_tile)
		key_error(map);
	mlx_put_image_to_window(map->mlx, map->win, r_tile, tile.w, tile.h);
	mlx_destroy_image(map->mlx, r_tile);
}
