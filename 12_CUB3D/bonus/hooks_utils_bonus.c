/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:43:51 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/06/17 12:51:59 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	cross_exit(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img->img_no);
	mlx_destroy_image(data->mlx, data->img->img_so);
	mlx_destroy_image(data->mlx, data->img->img_ea);
	mlx_destroy_image(data->mlx, data->img->img_we);
	mlx_destroy_image(data->mlx, data->mini_img);
	mlx_destroy_image(data->mlx, data->image);
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_data(data);
	data->win = NULL;
	free(data->win);
	free((void *)data->ray);
	free((void *)data->img);
	free((void *)data->bots);
	free((void *)data->doors);
	free((void *)data->sprites);
	exit(0);
}

void	left(t_data *data)
{
	float	leftx;
	float	lefty;

	leftx = data->ray->diry * -1;
	lefty = data->ray->dirx;
	data->newposx = data->posx + leftx * data->p_speed;
	data->newposy = data->posy + lefty * data->p_speed;
	if (data->map[(int)data->newposx][(int)data->posy] != '1')
		data->posx = data->newposx;
	if (data->map[(int)data->posx][(int)data->newposy] != '1')
		data->posy = data->newposy;
}

void	right(t_data *data)
{
	float	leftx;
	float	lefty;

	leftx = data->ray->diry;
	lefty = data->ray->dirx * -1;
	data->newposx = data->posx + leftx * data->p_speed;
	data->newposy = data->posy + lefty * data->p_speed;
	if (data->map[(int)data->newposx][(int)data->posy] != '1')
		data->posx = data->newposx;
	if (data->map[(int)data->posx][(int)data->newposy] != '1')
		data->posy = data->newposy;
}

void	upper(t_data *data)
{
	data->newposx = data->posx + data->ray->dirx * data->p_speed;
	data->newposy = data->posy + data->ray->diry * data->p_speed;
	if (data->map[(int)data->newposx][(int)data->posy] != '1')
		data->posx = data->newposx;
	if (data->map[(int)data->posx][(int)data->newposy] != '1')
		data->posy = data->newposy;
}

void	lower(t_data *data)
{
	data->newposx = data->posx - data->ray->dirx * data->p_speed;
	data->newposy = data->posy - data->ray->diry * data->p_speed;
	if (data->map[(int)data->newposx][(int)data->posy] != '1')
		data->posx = data->newposx;
	if (data->map[(int)data->posx][(int)data->newposy] != '1')
		data->posy = data->newposy;
}
