/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 09:57:21 by aaudevar          #+#    #+#             */
/*   Updated: 2023/06/16 11:21:35 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	get_tex_color(char *texData, int texx, int texy, int bpp)
{
	int				offset;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned int	*tex_pixel;

	offset = (texx * bpp / 8) + (texy * TEXWIDTH * bpp / 8);
	tex_pixel = (unsigned int *)(texData + offset);
	r = (*tex_pixel >> 16) & 0xFF;
	g = (*tex_pixel >> 8) & 0xFF;
	b = *tex_pixel & 0xFF;
	return ((r << 16) | (g << 8) | b);
}

void	get_tex_x_y_pos(t_data *data)
{
	if (data->ray->side == 0)
		data->img->wallx = data->posy
			+ data->ray->perpwalldist * data->ray->raydiry;
	else
		data->img->wallx = data->posx
			+ data->ray->perpwalldist * data->ray->raydirx;
	data->img->wallx -= floor(data->img->wallx);
	data->img->texx = (int)(data->img->wallx * (double)TEXWIDTH);
	if (data->ray->side == 0 && data->ray->raydirx > 0)
		data->img->texx = TEXWIDTH - data->img->texx - 1;
	if (data->ray->side == 1 && data->ray->raydiry < 0)
		data->img->texx = TEXWIDTH - data->img->texx - 1;
	data->img->step = 1.0 * TEXHEIGHT / data->ray->lineheight;
	data->img->texpos = (data->ray->drawstart - SCREENHEIGHT / 2
			+ data->ray->lineheight / 2) * data->img->step;
	data->img->y = data->ray->drawstart;
}

void	wall_color(t_data *data, int x)
{
	int	color;

	while (data->img->y < data->ray->drawend)
	{
		data->img->texy = (int)data->img->texpos & (TEXHEIGHT - 1);
		data->img->texpos += data->img->step;
		if (data->ray->side == 0 && data->ray->raydirx < 0)
				color = get_tex_color(data->img->no_addr, data->img->texx,
					data->img->texy, data->img->no_bits_per_pixel);
		if (data->ray->side == 0 && data->ray->raydirx > 0)
				color = get_tex_color(data->img->so_addr, data->img->texx,
					data->img->texy, data->img->so_bits_per_pixel);
		if (data->ray->side == 1 && data->ray->raydiry > 0)
				color = get_tex_color(data->img->ea_addr, data->img->texx,
					data->img->texy, data->img->ea_bits_per_pixel);
		if (data->ray->side == 1 && data->ray->raydiry < 0)
				color = get_tex_color(data->img->we_addr, data->img->texx,
					data->img->texy, data->img->we_bits_per_pixel);
		my_mlx_pixel_put(data, x, data->img->y, color);
		data->img->y++;
	}
}
