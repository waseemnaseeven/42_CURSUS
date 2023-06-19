/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:03:45 by aaudevar          #+#    #+#             */
/*   Updated: 2023/06/11 12:17:52 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_instruction(char *line)
{
	if (!line[0] || line[0] == '\n' || line[0] == '\r')
		return (1);
	if (!ft_strncmp(line, "NO", 2) && line[2] == ' ')
		return (1);
	else if (!ft_strncmp(line, "SO", 2) && line[2] == ' ')
		return (1);
	else if (!ft_strncmp(line, "WE", 2) && line[2] == ' ')
		return (1);
	else if (!ft_strncmp(line, "EA", 2) && line[2] == ' ')
		return (1);
	else if (!ft_strncmp(line, "F", 1) && line[1] == ' ')
		return (1);
	else if (!ft_strncmp(line, "C", 1) && line[1] == ' ')
		return (1);
	return (0);
}

char	*look_for_map(int fd)
{
	int		i;
	char	*line;

	line = gnl(fd);
	while (line)
	{
		i = 0;
		while (line[i] == ' ')
			i++;
		if (!is_instruction(line + i))
			break ;
		free(line);
		line = gnl(fd);
	}
	return (line);
}
