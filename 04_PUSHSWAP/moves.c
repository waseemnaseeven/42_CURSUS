/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:59:29 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/12/27 15:44:52 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_s(int *tab, char c)
{
	int		tmp;

	tmp = tab[0];
	tab[0] = tab[1];
	tab[1] = tmp;
	ft_printf("s%c\n", c);
}

void	ft_r(t_stack *tab, char c, int d)
{
	int		first;
	int		sizetmp;
	int		i;

	(void) d;
	i = -1;
	first = tab->lst[0];
	sizetmp = tab->size;
	sizetmp--;
	while (++i < sizetmp)
		tab->lst[i] = tab->lst[i + 1];
	tab->lst[i] = first;
	if (c == 'a')
		ft_printf("r%c\n", c);
	else if (c == 'b')
		ft_printf("r%c\n", c);
	else if (c == 'c')
		ft_printf("rr\n");
}

void	ft_rr(t_stack *tab, char c, int d)
{
	int		last;
	int		sizetmp;

	(void) d;
	sizetmp = tab->size;
	last = tab->lst[sizetmp - 1];
	while (--sizetmp > 0)
		tab->lst[sizetmp] = tab->lst[sizetmp - 1];
	tab->lst[0] = last;
	if (c == 'a')
		ft_printf("rr%c\n", c);
	else if (c == 'b')
		ft_printf("rr%c\n", c);
	else if (c == 'c')
		ft_printf("rrr\n");
}

int	ft_p(t_stack *to, t_stack *from, char c, int *tab)
{
	int		i;
	int		tmpfrom;
	int		tmpto;

	if (!from->size)
		return (0);
	tmpfrom = from->size--;
	to->size++;
	tmpto = to->size;
	while (--tmpto > 0)
		to->lst[tmpto] = to->lst[tmpto - 1];
	to->lst[0] = tab[0];
	i = 0;
	while (++i < tmpfrom)
		tab[i - 1] = tab[i];
	return (ft_printf("p%c\n", c));
}
