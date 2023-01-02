/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:26:19 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/12/28 18:24:59 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Pour la recherche de la valeur superieur ou la valeur min dans la lst A:
	Si la valeur pointer par i++ > a l'index indiquant la valeur max
		return la valeur minimum

		Si la valeur de a->lst[i] depasse celle de la b_lst[b->size]
	et que la pile_a[max] > a la valeur de a->lst
		alors max sera la valeur superieur ou pointer pour pa.
*/

int	ft_valsup(t_stack *a, t_stack *b, int tab_index)
{
	int		valsup;
	int		max;
	int		i_a;
	int		j_b;

	i_a = -1;
	j_b = tab_index;
	valsup = 0;
	max = ft_getmax(a);
	while (++i_a < a->size)
	{
		if (a->lst[i_a] > b->lst[j_b]
			&& a->lst[max] > a->lst[i_a])
			max = i_a;
	}
	if (b->lst[j_b] > a->lst[max])
		return (valsup = ft_getmin(a));
	return (max);
}

int	ft_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

int	ft_getmax(t_stack *a)
{
	int	i;
	int	res;
	int	tmp;

	i = 0;
	res = 0;
	tmp = a->lst[i];
	while (i < a->size)
	{
		if (tmp < a->lst[i])
		{
			tmp = a->lst[i];
			res = i;
		}
		i++;
	}
	return (res);
}

int	ft_getmin(t_stack *a)
{
	int	i;
	int	res;
	int	tmp;

	i = 0;
	res = 0;
	tmp = a->lst[i];
	while (i < a->size)
	{
		if (tmp > a->lst[i])
		{
			tmp = a->lst[i];
			res = i;
		}
		i++;
	}
	return (res);
}

void	ft_pushmin(t_stack *a, char c)
{
	if (ft_getmin(a) > ((a->size) / 2))
		while (ft_getmin(a) != 0)
			ft_rr(a, c, c);
	else
		while (ft_getmin(a) != 0)
			ft_r(a, c, c);
}
