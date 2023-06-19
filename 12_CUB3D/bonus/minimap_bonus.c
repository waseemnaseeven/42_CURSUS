/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:38:47 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/06/17 12:39:36 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	draw_map_color_helper(char cube, unsigned char *pixel)
{
	if (cube == 'D')
	{
		pixel[0] = 105;
		pixel[1] = 105;
		pixel[2] = 2;
		pixel[3] = 24;
	}
	else if (cube == '1')
	{
		pixel[0] = 105;
		pixel[1] = 105;
		pixel[2] = 105;
		pixel[3] = 255;
	}
}

void	draw_map_color(char cube, unsigned char *pixel)
{
	if (cube == '0')
	{
		pixel[0] = 153;
		pixel[1] = 198;
		pixel[2] = 225;
		pixel[3] = 255;
	}
	else if (cube == 'B')
	{
		pixel[0] = 15;
		pixel[1] = 102;
		pixel[2] = 105;
		pixel[3] = 255;
	}
	draw_map_color_helper(cube, pixel);
}

void	draw_character(unsigned char *pixel)
{
	pixel[0] = 60;
	pixel[1] = 20;
	pixel[2] = 220;
	pixel[3] = 255;
}

void	draw_map_helper(t_data data, char **map, int x, int y)
{
	int				start_x;
	int				start_y;
	int				i;
	int				j;
	unsigned char	*pixel;

	start_x = x * (MINIWIDTH / (int)data.cols);
	start_y = y * (MINIHEIGHT / (int)data.rows);
	i = start_y;
	while (i < start_y + (MINIHEIGHT / (int)data.rows))
	{
		j = start_x;
		while (j < start_x + (MINIWIDTH / (int)data.cols))
		{
			pixel = (unsigned char *)data.mini_addr +(i * MINIWIDTH + j)
				* (data.mini_bpp / 8);
			if ((int)data.posy == x && (int)data.posx == y)
				draw_character(pixel);
			else
				draw_map_color(map[y][x], pixel);
			j++;
		}
		i++;
	}
}

void	draw_map(t_data data, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			draw_map_helper(data, map, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data.mlx, data.win, data.mini_img, 0, 0);
}
