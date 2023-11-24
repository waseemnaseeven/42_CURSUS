/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 09:35:06 by aaudevar          #+#    #+#             */
/*   Updated: 2023/05/04 09:35:06 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	player_orientation_helper(t_data *data)
{
	if (data->starting_direction == 'E')
	{
		data->ray->dirx = 0;
		data->ray->diry = 1;
		data->ray->planex = 0.66;
		data->ray->planey = 0;
	}
	else if (data->starting_direction == 'W')
	{
		data->ray->dirx = 0;
		data->ray->diry = -1;
		data->ray->planex = -0.66;
		data->ray->planey = 0;
	}
}

void	player_orientation(t_data *data)
{
	if (data->starting_direction == 'N')
	{
		data->ray->dirx = -1;
		data->ray->diry = 0;
		data->ray->planex = 0;
		data->ray->planey = 0.66;
	}
	else if (data->starting_direction == 'S')
	{
		data->ray->dirx = 1;
		data->ray->diry = 0;
		data->ray->planex = 0;
		data->ray->planey = -0.66;
	}
	player_orientation_helper(data);
}

void	ft_initialize(t_data *data)
{
	int	i;

	i = 0;
	while (i <= 5)
		data->cmds[i++] = false;
	data->p_speed = 0.01;
	data->count_key = 0;
	data->ray->raydirx = 0;
	data->ray->raydiry = 0;
	data->endx = 0;
	data->endy = 0;
	data->ray->deltadistx = cos(data->ray->camerax) * 5;
	data->ray->deltadisty = sin(data->ray->camerax) * 5;
	data->ray->hitwall = false;
	data->ray->stepx = 0;
	data->ray->stepy = 0;
	data->ray->sidedistx = 0;
	data->ray->sidedisty = 0;
	data->ray->side = 0;
	data->ray->perpwalldist = 0.0;
	data->ray->lineheight = 0;
	data->ray->drawstart = 0;
	data->ray->drawend = 0;
	player_orientation(data);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_data	data;

	if (argc != 2)
		return (exit_error("Usage : ./cub3D file.cub", NULL));
	check_file_name(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (exit_error("Can't open ", argv[1]));
	ft_parsing(&data, argv, fd);
	data.ray = ft_calloc(1, sizeof(t_ray));
	if (!data.ray)
		return (-1);
	data.img = ft_calloc(1, sizeof(t_img));
	if (!data.img)
		return (-1);
	ft_initialize(&data);
	init_window(&data);
	free_data(&data);
}
