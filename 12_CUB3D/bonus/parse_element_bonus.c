/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:49:49 by aaudevar          #+#    #+#             */
/*   Updated: 2023/06/09 15:39:04 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	fill_texture(t_type t, t_data *data, char *line)
{
	char	*totrim;

	totrim = ft_strdup(line);
	data->textures[t] = ft_strtrim(totrim, " \r\n");
	free(totrim);
}

void	make_texture_array(char *line, t_data *data)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (!ft_strncmp(line + i, "NO", 2) && line[i + 2] == ' ')
		fill_texture(NO, data, line + i + 2);
	else if (!ft_strncmp(line + i, "SO", 2) && line[i + 2] == ' ')
		fill_texture(SO, data, line + i + 2);
	else if (!ft_strncmp(line + i, "WE", 2) && line[i + 2] == ' ')
		fill_texture(WE, data, line + i + 2);
	else if (!ft_strncmp(line + i, "EA", 2) && line[i + 2] == ' ')
		fill_texture(EA, data, line + i + 2);
	else if (!ft_strncmp(line + i, "F", 1) && line[i + 1] == ' ')
		fill_texture(F, data, line + i + 1);
	else if (!ft_strncmp(line + i, "C", 1) && line[i + 1] == ' ')
		fill_texture(C, data, line + i + 1);
}

int	reset_gnl(int fd, char **argv)
{
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit (exit_error("Can't open ", argv[1]));
	return (fd);
}

void	parse_element(int fd, char **argv, t_data *data)
{
	char	*line;
	int		i;

	fd = reset_gnl(fd, argv);
	line = gnl(fd);
	while (line)
	{
		i = 0;
		line = ignore_empty_line(line, fd);
		while (line[i] == ' ')
			i++;
		if (line[i] == '1')
		{
			free(line);
			break ;
		}
		make_texture_array(line, data);
		free(line);
		line = gnl(fd);
	}
}
