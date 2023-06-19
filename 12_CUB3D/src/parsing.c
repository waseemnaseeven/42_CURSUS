/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:00:16 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/06/17 12:22:34 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_file_name(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	if (i <= 4)
		exit(exit_error("Usage : ./cub3D file.cub", NULL));
	i = i - 4;
	if (file[i] != '.')
		exit(exit_error("Usage : ./cub3D file.cub", NULL));
	i++;
	if (file[i] != 'c')
		exit(exit_error("Usage : ./cub3D file.cub", NULL));
	i++;
	if (file[i] != 'u')
		exit(exit_error("Usage : ./cub3D file.cub", NULL));
	i++;
	if (file[i] != 'b')
		exit(exit_error("Usage : ./cub3D file.cub", NULL));
}

void	collect_rows_cols(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	data->cols = 0;
	data->rows = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
			x++;
		y++;
	}
	data->cols = --x;
	data->rows = y;
}

char	*new_line(char *str, int max)
{
	char	*new;
	int		i;

	new = ft_calloc((max + 1), sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	while (i < max)
	{
		new[i] = ' ';
		i++;
	}
	new[i] = '\0';
	free(str);
	return (new);
}

void	add_space(char **map)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	max = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j > max)
			max = j;
		i++;
	}
	i = 0;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) < max)
			map[i] = new_line(map[i], max);
		if (!map[i])
			exit_error("Fatal Error: bad maloc", NULL);
		i++;
	}
}

void	ft_parsing(t_data *data, char *argv[], int fd)
{
	check_element(fd);
	map_size(fd, argv, data);
	parse_element(fd, argv, data);
	parse_map(fd, argv, data);
	add_space(data->map);
	collect_rows_cols(data);
	check_map_characters(data);
	check_map_closed(data);
	check_correct_texture(data);
}
