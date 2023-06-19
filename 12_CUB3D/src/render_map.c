/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:28:09 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/06/08 09:04:27 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_camera_and_ray(t_data *data, int x)
{
	data->ray->camerax = 2 * x / (float)SCREENWIDTH - 1;
	data->ray->raydirx = data->ray->dirx
		+ data->ray->planex * data->ray->camerax;
	data->ray->raydiry = data->ray->diry
		+ data->ray->planey * data->ray->camerax;
	data->ray->mapx = abs((int)data->posx);
	data->ray->mapy = abs((int)data->posy);
	data->ray->deltadistx = len_of_ray(data->ray->raydirx);
	data->ray->deltadisty = len_of_ray(data->ray->raydiry);
}

void	get_sidedist(t_data *data)
{
	if (data->ray->raydirx < 0)
	{
		data->ray->stepx = -1;
		data->ray->sidedistx = (data->posx
				- data->ray->mapx) * data->ray->deltadistx;
	}
	else
	{
		data->ray->stepx = 1;
		data->ray->sidedistx = (data->ray->mapx
				+ 1.0 - data->posx) * data->ray->deltadistx;
	}
	if (data->ray->raydiry < 0)
	{
		data->ray->stepy = -1;
		data->ray->sidedisty = (data->posy
				- data->ray->mapy) * data->ray->deltadisty;
	}
	else
	{
		data->ray->stepy = 1;
		data->ray->sidedisty = (data->ray->mapy
				+ 1.0 - data->posy) * data->ray->deltadisty;
	}
	data->ray->hitwall = false;
}

void	hit_wall(t_data *data)
{
	while (data->ray->hitwall == false)
	{
		if (data->ray->sidedistx < data->ray->sidedisty)
		{
			data->ray->sidedistx += data->ray->deltadistx;
			data->ray->mapx += data->ray->stepx;
			data->ray->side = 0;
		}
		else
		{
			data->ray->sidedisty += data->ray->deltadisty;
			data->ray->mapy += data->ray->stepy;
			data->ray->side = 1;
		}
		if (data->map[data->ray->mapx][data->ray->mapy] == '1')
			data->ray->hitwall = true;
	}
}

void	get_draw_start_end(t_data *data)
{
	if (data->ray->side == 0)
			data->ray->perpwalldist = (data->ray->mapx - data->posx
				+ (1 - data->ray->stepx) / 2) / data->ray->raydirx;
	else
		data->ray->perpwalldist = (data->ray->mapy
				- data->posy + (1 - data->ray->stepy) / 2) / data->ray->raydiry;
	data->ray->lineheight = (int)(SCREENHEIGHT / data->ray->perpwalldist);
	data->ray->drawstart = -data->ray->lineheight / 2 + SCREENHEIGHT / 2;
	if (data->ray->drawstart < 0)
		data->ray->drawstart = 0;
	data->ray->drawend = data->ray->lineheight / 2 + SCREENHEIGHT / 2;
	if (data->ray->drawend >= SCREENHEIGHT)
		data->ray->drawend = SCREENHEIGHT - 1;
}

int	draw_map3d(t_data *data)
{
	int		x;

	x = 0;
	while (x < SCREENWIDTH)
	{
		get_camera_and_ray(data, x);
		get_sidedist(data);
		hit_wall(data);
		get_draw_start_end(data);
		get_tex_x_y_pos(data);
		wall_color(data, x);
		floor_color(data, data->ray->drawend, x);
		ceiling_color(data, data->ray->drawstart, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image, 0, 0);
	return (1);
}
