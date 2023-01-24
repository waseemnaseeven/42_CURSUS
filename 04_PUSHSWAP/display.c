/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:57:29 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/12/27 13:57:20 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printarray(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_printf("%d\n", tab[i]);
		i++;
	}
}

void	printstack(t_stack *a, t_stack *b)
{
	int		i;
	int		j;

	i = 0;
	while (i < a->size)
	{
		ft_printf("a->lst[%d] est : %d\n", i, a->lst[i]);
		i++;
	}
	ft_printf("STACK A\n");
	j = 0;
	while (j < b->size)
	{
		ft_printf("b->lst[%d] est : %d\n", j, b->lst[j]);
		j++;
	}
	ft_printf("STACK B\n");
}
