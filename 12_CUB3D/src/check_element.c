/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:53:28 by aaudevar          #+#    #+#             */
/*   Updated: 2023/06/19 11:55:39 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	no_dup_helper(t_type tab[6], t_type t)
{
	int	i;
	int	j;

	i = 0;
	while (i < 6 && (tab[i] == F || tab[i] == C
			|| tab[i] == NO || tab[i] == SO || tab[i] == EA || tab[i] == WE))
	{
		j = 0;
		if (tab[i] == t)
		{
			while ((j < 6) && (tab[j] == F || tab[j] == C || tab[j] == NO
					|| tab[j] == SO || tab[j] == EA || tab[j] == WE))
			{
				if (tab[j] == t && j != i)
					exit (exit_error("Invalid map", NULL));
				j++;
			}
		}
		i++;
	}
}

void	check_no_duplicate(t_type tab[6])
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (tab[i] == PROBLEM)
			exit (exit_error("Invalid map", NULL));
		i++;
	}
	no_dup_helper(tab, NO);
	no_dup_helper(tab, EA);
	no_dup_helper(tab, SO);
	no_dup_helper(tab, WE);
	no_dup_helper(tab, C);
	no_dup_helper(tab, F);
}

void	fill_tab(t_type tab[6], t_type t, int *j, char *line)
{
	if (*j > 5)
	{
		free (line);
		exit (exit_error("Invalid map", NULL));
	}
	tab[*j] = t;
	(*j)++;
}

int	check_element_helper(t_type tab[6], char *line, int *j)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
			i++;
	if (!ft_strncmp(line + i, "NO", 2) && line[i + 2] == ' ')
		fill_tab(tab, NO, j, line);
	else if (!ft_strncmp(line + i, "SO", 2) && line[i + 2] == ' ')
		fill_tab(tab, SO, j, line);
	else if (!ft_strncmp(line + i, "WE", 2) && line[i + 2] == ' ')
		fill_tab(tab, WE, j, line);
	else if (!ft_strncmp(line + i, "EA", 2) && line[i + 2] == ' ')
		fill_tab(tab, EA, j, line);
	else if (!ft_strncmp(line + i, "F", 1) && line[i + 1] == ' ')
		fill_tab(tab, F, j, line);
	else if (!ft_strncmp(line + i, "C", 1) && line[i + 1] == ' ')
		fill_tab(tab, C, j, line);
	else if (line[i] != '1')
		fill_tab(tab, PROBLEM, j, line);
	return (i);
}

void	check_element(int fd)
{
	char	*line;
	int		i;
	t_type	tab[6];
	int		j;

	j = 0;
	line = gnl(fd);
	while (line)
	{
		line = ignore_empty_line(line, fd);
		i = check_element_helper(tab, line, &j);
		if (line[i] == '1')
		{
			free(line);
			break ;
		}	
		free(line);
		line = gnl(fd);
	}
	if (j != 6)
		exit (exit_error("Invalid map", NULL));
	check_no_duplicate(tab);
}
