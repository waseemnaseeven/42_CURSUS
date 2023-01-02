/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:36:28 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/12/27 10:39:38 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_all(t_stack a, t_stack b, int size)
{
	if (size == 2)
		ft_s(a.lst, 'a');
	else if (size == 3)
		ft_sort_three(&a);
	else if (size == 5)
		ft_sort_five(&a, &b);
	else
		ft_sort_bigstack(&a, &b);
}

void	ft_sort_bigstack(t_stack *a, t_stack *b)
{
	int		*tab;

	tab = ft_pre_sort(a);
	if (!tab)
		exit (1);
	ft_median(tab, a, b);
	ft_calculprice(a, b);
	ft_pushmin(a, 'a');
}

void	ft_sort_five(t_stack *a, t_stack *b)
{
	ft_pushmin(a, 'a');
	ft_p(b, a, 'b', a->lst);
	ft_pushmin(a, 'a');
	ft_p(b, a, 'b', a->lst);
	ft_sort_three(a);
	ft_p(a, b, 'a', b->lst);
	ft_p(a, b, 'a', b->lst);
}

void	ft_sort_three(t_stack *a)
{
	if (a->lst[1] < a->lst[0] && a->lst[1] < a->lst[2]
		&& a->lst[0] < a->lst[2])
		ft_s(a->lst, 'a');
	else if (a->lst[1] < a->lst[0] && a->lst[1] > a->lst[2]
		&& a->lst[0] > a->lst[2])
	{
		ft_s(a->lst, 'a');
		ft_rr(a, 'a', 0);
	}
	else if (a->lst[1] < a->lst[0] && a->lst[1] < a->lst[2]
		&& a->lst[0] > a->lst[2])
		ft_r(a, 'a', 0);
	else if (a->lst[1] > a->lst[0] && a->lst[1] > a->lst[2]
		&& a->lst[0] < a->lst[2])
	{
		ft_s(a->lst, 'a');
		ft_r(a, 'a', 0);
	}
	else if (a->lst[1] > a->lst[0] && a->lst[1] > a->lst[2]
		&& a->lst[0] > a->lst[2])
		ft_rr(a, 'a', 0);
}
