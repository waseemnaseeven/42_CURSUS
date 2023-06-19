/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 10:00:37 by aaudevar          #+#    #+#             */
/*   Updated: 2023/06/18 09:00:59 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

char	*gnl(int fd)
{
	int		i;
	int		rd;
	char	character;
	char	*buffer;

	i = 0;
	rd = 0;
	buffer = malloc(BUFFER);
	if (!buffer)
		exit(exit_error("Fatal Error: Bad Malloc", NULL));
	rd = read(fd, &character, 1);
	while (rd > 0)
	{
		buffer[i++] = character;
		if (character == '\n')
			break ;
		rd = read(fd, &character, 1);
	}
	buffer[i] = '\0';
	if (rd == -1 || i == 0 || (!buffer[i - 1] && !rd))
		return (free(buffer), NULL);
	return (buffer);
}

char	*ignore_empty_line(char *line, int fd)
{
	while (!line[0] || line[0] == '\n' || line[0] == '\r')
	{
		free(line);
		line = gnl(fd);
		if (!line)
			exit(exit_error("No map", NULL));
	}
	return (line);
}

void	display_arr(char *textures[6])
{
	int	i;

	i = 0;
	while (i < 6)
	{
		ft_printf("%s\n", textures[i]);
		i++;
	}
}

void	display_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

void	printarray(float *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_printf("%d\n", tab[i]);
		i++;
	}
}
