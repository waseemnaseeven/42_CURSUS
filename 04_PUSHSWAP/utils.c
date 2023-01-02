/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:54:49 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/12/28 13:24:39 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_freetab(char **tab, int boolean)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	if (boolean)
		return (0);
	ft_printf("Error\n");
	exit(1);
}

void	ft_freelst(t_stack *a, t_stack *b)
{
	free(a->lst);
	free(b->lst);
	exit(EXIT_SUCCESS);
}

void	ft_swap(int *tab1, int *tab2)
{
	int		tmp;

	tmp = *tab1;
	*tab1 = *tab2;
	*tab2 = tmp;
}

long	ft_atoi_long(const char *nptr)
{
	int			i;
	long		res;
	int			sign;

	i = 0;
	res = 0;
	sign = 1;
	if (!nptr)
		return (res);
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if ((nptr[i] == '-') || (nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}

void	ft_check_if_sorted_arr(t_stack *a, int size)
{
	int		i;
	int		j;

	i = -1;
	while (++i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (a->lst[i] > a->lst[j])
				return ;
			j++;
		}
	}
	if (i == (size))
	{
		free(a->lst);
		exit (1);
	}
}
