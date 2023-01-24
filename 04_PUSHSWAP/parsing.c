/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:00:59 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/12/28 16:08:50 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_doubles(int argc, int *stack_a)
{
	int		i;
	int		j;

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (stack_a[j] == stack_a[i] && j != i)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_checksign(char **res, int i)
{
	int	j;

	j = 0;
	while (res[i][j])
	{
		while (res[i][j] == ' ')
			j++;
		if (res[i][j] == '-' || res[i][j] == '+')
			j++;
		if (res[i][j] == '-' || res[i][j] == '+')
			ft_freetab(res, 0);
		while (ft_isdigit(res[i][j]))
			j++;
		if (res[i][j] != '\0')
			ft_freetab(res, 0);
	}
}

int	*ft_filledstack(int *tab, int size)
{
	int		*lst;
	int		i;

	if (!check_doubles(size, tab))
	{
		ft_printf("Error\n");
		exit(1);
	}
	lst = malloc(sizeof(int) * size);
	if (!lst)
		return (NULL);
	i = -1;
	while (++i < size)
		lst[i] = tab[i];
	return (lst);
}

void	check_minmax(char **split, int k)
{
	if (ft_atoi_long(split[k]) > 2147483647)
		ft_freetab(split, 0);
	if (ft_atoi_long(split[k]) < -2147483648)
		ft_freetab(split, 0);
}

int	*parsing(int ac, char **av, int *size)
{
	int		i;
	char	**split;
	int		tmp[10000];
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (++i < ac)
	{
		split = ft_split(av[i], ' ');
		k = -1;
		while (split[++k])
		{
			if (split[k][1] == '\0' && !ft_isdigit(split[k][0]))
				ft_freetab(split, 0);
			ft_checksign(split, k);
			check_minmax(split, k);
			tmp[j++] = ft_atoi_long(split[k]);
		}
		ft_freetab(split, 1);
	}
	return (ft_filledstack(tmp, *size = j));
}
