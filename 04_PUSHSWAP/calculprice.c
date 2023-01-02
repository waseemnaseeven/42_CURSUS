/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculprice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:27:54 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/12/28 18:52:07 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	get_value calcule le cout du deplacement d'un element de la pile b
	vers sa position triee dans la pile a. Ce coût est basé sur la distance
	de l'élément à l'élément pivot (qui est supposé être l'élément du
	milieu de la pile). Si l'élément est du même côté du pivot que sa
	position triée, le coût est égal à la distance entre l'élément et
	sa position triée. Si l'élément est du côté opposé du pivot à sa
	position triée, le coût est égal à la somme des distances entre l'élément
	et le pivot, et entre le pivot et sa position triée.
*/

int	ft_getvalue(t_stack *stack, int tab_index)
{
	int		price;

	if (tab_index > stack->size / 2)
		price = stack->size - tab_index;
	else
		price = -tab_index;
	return (price);
}

/*
	ft_calcultotal calcule le coût total du déplacement
	de deux éléments de leurs positions actuelles vers leurs positions triées.
	Si les éléments sont du même côté de l'élément pivot, le coût total
	est le maximum des coûts individuels.
	Si les éléments se trouvent sur des côtés opposés de l'élément pivot,
	le coût total est la somme des coûts individuels.
*/

int	ft_calcultotal(int price_a, int price_b)
{
	int		a;
	int		b;

	a = ft_abs(price_a);
	b = ft_abs(price_b);
	if ((price_a < 0 && price_b < 0) || (price_a > 0 && price_b > 0))
	{
		if (a >= b)
			return (a);
		else
			return (b);
	}
	return (a + b);
}

/*
	calculposition calcule les coûts de déplacement d'un élément de la
	pile b (à l'indice i) et de l'élément de la pile a avec la valeur
	la plus élevée qui est toujours inférieure à l'élément de la pile b.

*/
void	calculposition(int tab_index[5], t_stack *a, t_stack *b, int i)
{
	int		valsup;

	valsup = 0;
	tab_index[3] = ft_getvalue(b, i);
	valsup = ft_valsup(a, b, i);
	tab_index[4] = ft_getvalue(a, valsup);
}

void	swap_index(int tab_index[5], int *total, int i)
{
	if (tab_index[0] > total[i])
	{
		tab_index[0] = total[i];
		tab_index[1] = tab_index[4];
		tab_index[2] = tab_index[3];
	}
}

/*
	ft_calculprice sélectionne à plusieurs reprises l'élément de la
	pile b avec le coût le plus bas d'être déplacé vers sa position triée
	dans la pile a, et l'élément de la pile a avec la valeur la plus élevée
	qui est toujours inférieure à l'élément de la pile b, et les déplace
	vers pile A. Ce processus continue jusqu'à ce que la pile b soit vide.
*/

void	ft_calculprice(t_stack *a, t_stack *b)
{
	int		tab_index[5];
	int		i;
	int		*total;

	total = malloc(sizeof(int) * b->size);
	if (!total)
		ft_freelst(a, b);
	while (b->size != 0)
	{
		i = -1;
		tab_index[0] = 99999999;
		while (++i < b->size)
		{
			calculposition(tab_index, a, b, i);
			total[i] = ft_calcultotal(tab_index[3], tab_index[4]);
			swap_index(tab_index, total, i);
		}
		forthemoves(a, b, tab_index);
	}
	free(total);
}
