/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bots_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 11:41:40 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/06/18 09:07:26 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	check_map_bots_helper(t_data *data, int i, int j, int k)
{
	data->bots->pos_e[k] = ft_calloc(2, sizeof(float));
	if (!data->bots->pos_e[k])
		exit (exit_error("Fatal error: bad malloc ", NULL));
	data->bots->pos_e[k][x] = (float)i + 0.5;
	data->bots->pos_e[k][y] = (float)j + 0.5;
	data->bots->s_direction[k] = data->map[(int)i][(int)j];
	k++;
}

void	check_map_bots(t_data *data)
{
	int	k;
	int	i;
	int	j;

	i = 0;
	k = 0;
	data->bots->pos_e = ft_calloc(data->bots->n_bots, (sizeof(float *)));
	if (!data->bots->pos_e[k])
		exit (exit_error("Fatal error: bad malloc ", NULL));
	data->bots->s_direction = ft_calloc(data->bots->n_bots, (sizeof(float)));
	if (!data->bots->s_direction)
		exit (exit_error("Fatal error: bad malloc ", NULL));
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'B')
				check_map_bots_helper(data, i, j, k);
			j++;
		}
		i++;
	}
}
