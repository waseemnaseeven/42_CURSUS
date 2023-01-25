/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 09:59:08 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/01/20 10:58:20 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_countmap(char *line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

void	ft_check_charerror(t_game *map)
{
	ft_printf("Error\n");
	if (map->c < 1)
		ft_printf("Map must have at least one collectible\n");
	else if (map->p != 1)
		ft_printf("Map must have at least one character\n");
	else if (map->e != 1)
		ft_printf("Map must have only one exit\n");
	full_free(map);
	exit (1);
}

void	ft_charcount(t_game *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'C')
				map->c++;
			else if (map->map[y][x] == 'E')
				map->e++;
			else if (map->map[y][x] == 'P')
				map->p++;
			x++;
		}
		y++;
	}
	if (map->c < 1 || map->e != 1 || map->p != 1)
		ft_check_charerror(map);
}

/*
	Fonction principal du parsing
	ou line + 1 pour retirer les '\n' pour *size ?
*/

void	ft_verif_map(int fd, int *size)
{
	char	*line;
	char	*previous_line;

	previous_line = NULL;
	while (1)
	{
		line = get_next_line(fd, 0);
		if (line == NULL)
			break ;
		else if (previous_line != NULL)
			free(previous_line);
		*size += ft_countmap(line);
		if (previous_line == NULL)
			ft_check_horizontal(line);
		else
			ft_check_middle(line);
		ft_check_is_rectangular(line);
		ft_check_foreign_char(line);
		previous_line = line;
	}
	ft_check_horizontal(previous_line);
	free(previous_line);
}
