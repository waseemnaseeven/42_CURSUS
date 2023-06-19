/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:57:55 by aaudevar          #+#    #+#             */
/*   Updated: 2023/06/12 19:13:55 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

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

int	ft_freebots(float **tab, int *direction)
{
	int		i;

	i = 0;
	if (!tab || !tab[0])
		return (1);
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	free(direction);
	return (0);
}
