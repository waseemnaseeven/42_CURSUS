/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:20:05 by aaudevar          #+#    #+#             */
/*   Updated: 2023/06/17 12:40:54 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	map_size(int fd, char **argv, t_data *data)
{
	char	*line;
	int		j;

	fd = reset_gnl(fd, argv);
	j = 0;
	line = look_for_map(fd);
	while (line)
	{
		if (!line[0] || line[0] == '\n' || line[0] == '\r')
		{
			free(line);
			exit (exit_error("The map must be the last element ", NULL));
		}
		free(line);
		line = gnl(fd);
		j++;
	}
	data->size_map = j;
}

void	parse_map(int fd, char **argv, t_data *data)
{
	char	*line;
	int		i;
	char	*totrim;

	fd = reset_gnl(fd, argv);
	line = look_for_map(fd);
	data->map = ft_calloc(data->size_map + 1, sizeof(char *));
	if (!data->map)
		exit (exit_error("Fatal error: bad malloc ", NULL));
	i = 0;
	while (line)
	{
		totrim = ft_strdup(line);
		data->map[i] = ft_strtrim(totrim, "\r\n");
		if (!data->map[i])
			exit (exit_error("Fatal error: bad malloc ", NULL));
		free(totrim);
		i++;
		free(line);
		line = gnl(fd);
	}
	data->map[i] = NULL;
}

void	check_char_helper(t_data *data, int *count, float i, float j)
{
	(*count)++;
	data->starting_direction = data->map[(int)i][(int)j];
	data->posx = i + 0.5;
	data->posy = j + 0.5;
	data->map[(int)i][(int)j] = '0';
}

void	check_map_characters(t_data *data)
{
	int	i;
	int	j;
	int	count_player;

	i = 0;
	count_player = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			is_in_map(data, i, j);
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
				check_char_helper(data, &count_player, i, j);
			else if (data->map[i][j] != '1' && data->map[i][j] != '0'
				&& data->map[i][j] != ' ' && data->map[i][j] != 'B'
				&& data->map[i][j] != 'D')
				exit(free_exit(data, "Invalid map"));
			j++;
		}
		i++;
	}
	if (count_player != 1)
		exit(free_exit(data, "Invalid map"));
}

void	check_map_closed(t_data *data)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			size = (int)ft_strlen(data->map[i]);
			if (data->map[i][j] == '0')
			{
				if (!i || !j || i + 1 == data->size_map || j + 1 == size
					|| data->map[i - 1][j] == ' ' || data->map[i + 1][j] == ' '
					|| data->map[i][j + 1] == ' ' || data->map[i][j - 1] == ' ')
				{
					exit(free_exit(data, "Invalid map 1"));
				}
			}
			j++;
		}
		i++;
	}
}
