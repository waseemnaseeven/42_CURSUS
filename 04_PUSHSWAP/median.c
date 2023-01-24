/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:27:37 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/12/28 14:19:15 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_pre_sort(t_stack *a)
{
	int		*tab;
	int		i;
	int		j;

	tab = (int *)malloc(sizeof(int) * a->size);
	if (!tab)
	{
		free(tab);
		exit (0);
	}
	i = -1;
	while (++i < a->size)
		tab[i] = a->lst[i];
	i = -1;
	while (++i < a->size)
	{
		j = i;
		while (++j < a->size)
		{
			if (tab[i] > tab[j])
				ft_swap(&tab[i], &tab[j]);
		}
	}
	return (tab);
}

/*
	Si la liste a un nbr impair d'éléments,
		la médiane est l'élément du milieu.
	Sinon
		la mediane est la moyenne des deux elements du milieu
*/

int	ft_calcul_median(t_stack *a, int *tab)
{
	if (a->size % 2 == 1)
		return (tab[a->size / 2]);
	else
		return ((tab[a->size / 2 - 1] + tab[a->size / 2]) / 2);
}

void	ft_median(int *tab, t_stack *a, t_stack *b)
{
	int		median;
	int		i;

	median = ft_calcul_median(a, tab);
	while (a->size != 3)
	{
		i = 0;
		if (a->lst[i] >= median)
		{
			ft_p(b, a, 'b', a->lst);
			median = ft_calcul_median(a, tab);
		}
		else
			ft_r(a, 'a', i++);
	}
	ft_sort_three(a);
	free(tab);
}
