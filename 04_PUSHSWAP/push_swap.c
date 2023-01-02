/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:16:04 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/12/31 13:39:49 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;
	int			size;

	if (ac == 2)
		return (0);
	ft_checkargs(ac, av);
	a.lst = parsing(ac, av, &size);
	if (!a.lst)
	{
		free(a.lst);
		return (0);
	}
	ft_check_if_sorted_arr(&a, size);
	a.size = size;
	b.lst = malloc(sizeof(int) * a.size);
	if (!b.lst)
		return (0);
	b.size = 0;
	ft_sort_all(a, b, size);
	ft_freelst(&a, &b);
}
