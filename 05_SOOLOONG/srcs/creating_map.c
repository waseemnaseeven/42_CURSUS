/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:31:27 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/01/16 17:03:39 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_close_file(int fd, char **ret[])
{
	if (close(fd) == 0)
		return (*ret);
	else
	{
		free(*ret);
		ft_printf("Error\n");
		exit(1);
	}
}

int	ft_open(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\n");
		ft_printf("Can't open the map");
		exit(1);
	}
	return (fd);
}

char	**ft_creating_map(char *file, t_game *map)
{
	int		fd;
	int		i;
	char	**ret;
	char	*line;

	i = 0;
	fd = 0;
	fd = ft_open(file);
	ret = ft_calloc(sizeof(char *), (map->size));
	if (!ret)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd, 0);
		if (line == NULL)
			break ;
		ret[i] = ft_strdup(line);
		free(line);
		i++;
	}
	free(line);
	return (ft_close_file(fd, &ret));
}
