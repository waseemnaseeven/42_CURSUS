/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:13:56 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/01/20 10:53:44 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_line_len(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	return (i);
}

/*
	 11111111
	 00000P01
	 1C0E0001
	 11111111
		OU
	 11111111
	 10000P01
	 1C0E0000
	 11111111
*/

void	ft_check_middle(char *line)
{
	if (line[0] != '1' || line[ft_map_line_len(line) - 1] != '1' )
	{
		ft_printf("Error\n");
		ft_printf("Map has to be surrounded by walls\n");
		free_line(line);
		exit (1);
	}
}

/*
	 11111101
	 10000P01
	 1C0E0001
	 11111111
		OU
	 11111111
	 10000P01
	 1C0E0001
	 11111101
*/

void	ft_check_horizontal(char *line)
{
	int	i;

	i = 0;
	if (!line)
	{
		ft_printf("Error\nEmpty map\n");
		free(line);
		exit (1);
	}
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] != '1')
		{
			ft_printf("Error\n");
			ft_printf("Map must have only wall at the top and at the bottom\n");
			free_line(line);
			exit(1);
		}
		i++;
	}
}

/*
	11111111
	10000P01
	1C0E00A1
	11111111
*/

void	ft_check_foreign_char(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'P'
			&& line[i] != 'E' && line[i] != 'C')
		{
			ft_printf("Error\n");
			ft_printf("Please, just provide 1, 0, C, E or P\n");
			free_line(line);
			exit (1);
		}
		i++;
	}
}

/*
1111111111111111111111111111
1E0010C000000000000000000001
1000111000000000000000000001
1P00000000000000000000000001
10000000000000000000000001
100C000000000000000000000001
1111111111111111111111111111
*/

void	ft_check_is_rectangular(char *line)
{
	static int	line_len;

	if (!line_len)
		line_len = ft_map_line_len(line);
	else if (ft_map_line_len(line) != line_len)
	{
		ft_printf("Error\n");
		ft_printf("Map has to be rectangular\n");
		free_line(line);
		exit(1);
	}
}
