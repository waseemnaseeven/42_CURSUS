/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublemoves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:55:12 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/12/31 13:39:50 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrotate(t_stack *a, t_stack *b, char c, int d)
{
	(void) c;
	(void) d;
	ft_r(a, 'c', 0);
	ft_r(b, 'x', 0);
}

void	ft_rrrotate(t_stack *a, t_stack *b, char c, int d)
{
	(void) c;
	(void) d;
	ft_rr(a, 'c', 0);
	ft_rr(b, 'x', 0);
}

int	ft_checkargs(int ac, char **av)
{
	int	i;
	int	k;

	i = 0;
	while (++i < ac)
	{
		k = 0;
		while (av[i][k] == ' ' && av[i][k] != '\0')
			k++;
		if (av[i][k] == '\0')
		{
			ft_printf("Error\n");
			exit(1);
		}
	}
	return (0);
}
