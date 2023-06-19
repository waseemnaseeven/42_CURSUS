/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:57:55 by aaudevar          #+#    #+#             */
/*   Updated: 2023/06/07 10:28:54 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	free_exit(t_data *data, char *msg)
{
	free_data(data);
	return (exit_error(msg, NULL));
}

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (data->textures[i])
			free(data->textures[i]);
		i++;
	}
	i = 0;
	if (data->map && data->map[i])
	{
		while (data->map[i])
		{
			free(data->map[i]);
			i++;
		}
	}
	if (data->map)
		free(data->map);
}

int	exit_error(char *msg, char *file)
{
	int	i;

	write(2, "Error\n", 6);
	i = 0;
	if (msg)
	{
		while (msg[i])
		{
			write(2, &msg[i], 1);
			i++;
		}
	}
	if (file)
	{
		i = 0;
		while (file[i])
		{
			write(2, &file[i], 1);
			i++;
		}
	}
	write(2, "\n", 1);
	return (1);
}
