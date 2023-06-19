/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:20:27 by aaudevar          #+#    #+#             */
/*   Updated: 2023/06/09 15:36:16 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	is_xpm_file(char *texture)
{
	int	i;

	i = 0;
	while (texture[i])
		i++;
	if (i <= 4)
		return (0);
	i = i - 4;
	if (texture[i] != '.')
		return (0);
	i++;
	if (texture[i] != 'x')
		return (0);
	i++;
	if (texture[i] != 'p')
		return (0);
	i++;
	if (texture[i] != 'm')
		return (0);
	return (1);
}

int	number_is_color(char *color, int *i, t_data *d)
{
	int	j;

	j = *i;
	while (color[j] && color[j] != ',')
		j++;
	d->color_number = ft_calloc(j + 1, sizeof(char));
	if (!d->color_number)
		exit(free_exit(d, "Fatal error: bad malloc"));
	j = 0;
	while (color[*i] && color[*i] != ',')
	{
		if (!ft_isdigit(color[*i]))
			return (0);
		d->color_number[j] = color[*i];
		(*i)++;
		if (j == 2)
			while (color[*i] == ' ')
				(*i)++;
		if (++j > 3)
			return (0);
	}
	d->color_number[j] = '\0';
	if (ft_atoi(d->color_number) < 0 || ft_atoi(d->color_number) > 255)
		return (0);
	return (1);
}

int	is_correct_format(char *color)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (color[i])
	{
		if (color[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		return (0);
	return (1);
}

int	is_correct_color(char *color, t_data *d)
{
	int	i;
	int	count;

	if (!is_correct_format(color))
		return (0);
	i = 0;
	count = 0;
	while (count < 3)
	{
		if (!color[i])
			break ;
		while (color[i] == ' ')
			i++;
		if (!number_is_color(color, &i, d))
		{
			free(d->color_number);
			return (0);
		}
		free(d->color_number);
		count++;
		i++;
	}
	return (1);
}

void	check_correct_texture(t_data *d)
{
	if (!is_xpm_file(d->textures[NO]) || !is_xpm_file(d->textures[SO])
		|| !is_xpm_file(d->textures[EA]) || !is_xpm_file(d->textures[WE]))
		exit(free_exit(d, "Textures must be .xpm file"));
	if (!is_correct_color(d->textures[C], d)
		|| !is_correct_color(d->textures[F], d))
		exit(free_exit(d, "Color format is : [0][255],[0][255],[0][255]"));
}
