/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forthemoves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:14:12 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/12/28 15:52:46 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	if_one_positive(t_stack *a, t_stack *b, int tab_index[5])
{
	while (tab_index[1] > 0)
	{
		if (tab_index[2] > 0)
			ft_rrrotate(a, b, tab_index[2]--, 0);
		else
			ft_rr(a, 'a', tab_index[1]);
		tab_index[1]--;
	}
}

void	if_one_negative(t_stack *a, t_stack *b, int tab_index[5])
{
	while (tab_index[1] < 0)
	{
		if (tab_index[2] < 0)
			ft_rrotate(a, b, tab_index[2]++, 0);
		else
			ft_r(a, 'a', tab_index[1]);
		tab_index[1]++;
	}
}

int	forthemoves(t_stack *a, t_stack *b, int tab_index[5])
{
	if (tab_index[0] == 0)
		return (ft_p(a, b, 'a', b->lst));
	if_one_positive(a, b, tab_index);
	while (tab_index[2] > 0)
	{
		ft_rr(b, 'b', 0);
		tab_index[2]--;
	}
	if_one_negative(a, b, tab_index);
	while (tab_index[2] < 0)
	{
		ft_r(b, 'b', 0);
		tab_index[2]++;
	}
	return (ft_p(a, b, 'a', b->lst));
}
