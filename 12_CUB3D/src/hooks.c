/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:37:06 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/06/12 19:45:58 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	release_helper(int key, t_data *data)
{
	if (key == A || key == Q)
	{
		if (data->cmds[2])
			data->cmds[2] = false;
	}
	else if (key == D)
	{
		if (data->cmds[3])
			data->cmds[3] = false;
	}
	else if (key == LEFT_ARR)
	{
		if (data->cmds[4])
			data->cmds[4] = false;
	}
	else if (key == RIGHT_ARR)
	{
		if (data->cmds[5])
			data->cmds[5] = false;
	}
}

int	ft_keyboard_release_events(int key, t_data *data)
{
	if (key == W || key == Z)
	{
		if (data->cmds[0])
			data->cmds[0] = false;
	}
	else if (key == S)
	{
		if (data->cmds[1])
			data->cmds[1] = false;
	}
	release_helper(key, data);
	return (0);
}

void	handle_events(t_data *data)
{
	if (data->cmds[0])
		upper(data);
	if (data->cmds[1])
		lower(data);
	if (data->cmds[2])
		left(data);
	if (data->cmds[3])
		right(data);
	if (data->cmds[4])
		rotate_left(data);
	if (data->cmds[5])
		rotate_right(data);
}

int	ft_keyboard_events(int key, t_data *data)
{
	if (key == ESC)
		cross_exit(data);
	if ((key == W || key == Z))
		data->cmds[0] = true;
	else if (key == S)
		data->cmds[1] = true;
	else if (key == A || key == Q)
		data->cmds[2] = true;
	else if (key == D)
		data->cmds[3] = true;
	else if (key == LEFT_ARR)
		data->cmds[4] = true;
	else if (key == RIGHT_ARR)
		data->cmds[5] = true;
	return (1);
}

void	ft_hooks(t_data *data)
{
	mlx_loop_hook(data->mlx, display_, data);
	mlx_hook(data->win, KeyPress, 1L << 0, ft_keyboard_events, data);
	mlx_hook(data->win, KeyRelease, 1L << 1, ft_keyboard_release_events, data);
	mlx_hook(data->win, 17, 1L << 17, cross_exit, data);
}
