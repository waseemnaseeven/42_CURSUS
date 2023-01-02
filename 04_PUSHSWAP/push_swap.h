/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:25:38 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/12/31 13:49:06 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int		*lst;
	int		size;

}	t_stack;

/* ***** Parsing functions ***** */
int		*parsing(int ac, char **av, int *size);
void	ft_checksign(char **res, int i);
int		check_doubles(int argc, int *stack_a);
void	check_minmax(char **split, int k);
int		*ft_filledstack(int *tab, int size);

/* ***** Utils functions ***** */
int		ft_freetab(char **tab, int boolean);
void	ft_check_if_sorted_arr(t_stack *a, int size);
void	ft_swap(int *tab1, int *tab2);
long	ft_atoi_long(const char *nptr);
void	ft_freelst(t_stack *a, t_stack *b);
int		ft_checkargs(int ac, char **av);

/* ***** Sorted functions ***** */
void	ft_sort_all(t_stack a, t_stack b, int size);
void	ft_sort_three(t_stack *a);
void	ft_sort_five(t_stack *a, t_stack *b);
void	ft_sort_bigstack(t_stack *a, t_stack *b);

/* ***** Doublemoves functions ***** */
void	ft_rrrotate(t_stack *a, t_stack *b, char c, int d);
void	ft_rrotate(t_stack *a, t_stack *b, char c, int d);

/* ***** Moves functions ***** */
void	ft_s(int *lst, char c);
void	ft_r(t_stack *tab, char c, int d);
void	ft_rr(t_stack *tab, char c, int d);
int		ft_p(t_stack *to, t_stack *from, char c, int *tab);

/* ***** Print functions ***** */
void	printarray(int *tab, int size);
void	printstack(t_stack *a, t_stack *b);

/* ***** Maths functions ******/
void	ft_pushmin(t_stack *a, char c);
int		ft_abs(int nb);
int		ft_getmax(t_stack *a);
int		ft_getmin(t_stack *a);
int		ft_valsup(t_stack *a, t_stack *b, int tab_index);

/* ***** Median Functions ******/
int		*ft_pre_sort(t_stack *a);
int		ft_calcul_median(t_stack *a, int *tab);
void	ft_median(int *tab, t_stack *a, t_stack *b);

/* ***** Calculprice functions ***** */
int		ft_getvalue(t_stack *stack, int tab_index);
void	swap_index(int tab_index[5], int *total, int i);
void	calculposition(int tab_index[5], t_stack *a, t_stack *b, int i);
int		ft_calcultotal(int price_a, int price_b);
void	ft_calculprice(t_stack *a, t_stack *b);

/* ***** Forthemoves functions ***** */
int		forthemoves(t_stack *a, t_stack *b, int tab_index[5]);
void	if_one_positive(t_stack *a, t_stack *b, int tab_index[5]);
void	if_one_negative(t_stack *a, t_stack *b, int tab_index[5]);

#endif
