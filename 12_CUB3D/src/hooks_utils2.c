/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:50:50 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/06/12 19:46:04 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rotate_right(t_data *data)
{
	data->ray->olddirx = data->ray->dirx;
	data->ray->dirx = data->ray->dirx
		* cos(-data->p_speed) - data->ray->diry * sin(-data->p_speed);
	data->ray->diry = data->ray->olddirx
		* sin(-data->p_speed) + data->ray->diry * cos(-data->p_speed);
	data->ray->oldplanex = data->ray->planex;
	data->ray->planex = data->ray->planex
		* cos(-data->p_speed) - data->ray->planey * sin(-data->p_speed);
	data->ray->planey = data->ray->oldplanex
		* sin(-data->p_speed) + data->ray->planey * cos(-data->p_speed);
}

void	rotate_left(t_data *data)
{
	data->ray->olddirx = data->ray->dirx;
	data->ray->dirx = data->ray->dirx
		* cos(data->p_speed) - data->ray->diry * sin(data->p_speed);
	data->ray->diry = data->ray->olddirx
		* sin(data->p_speed) + data->ray->diry * cos(data->p_speed);
	data->ray->oldplanex = data->ray->planex;
	data->ray->planex = data->ray->planex
		* cos(data->p_speed) - data->ray->planey * sin(data->p_speed);
	data->ray->planey = data->ray->oldplanex
		* sin(data->p_speed) + data->ray->planey * cos(data->p_speed);
}

int	display_(t_data *data)
{
	draw_map3d(data);
	handle_events(data);
	return (0);
}
