/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:56:38 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/11/18 11:45:00 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

// void	print_list(t_list *lst)
// {
// 	while (lst != NULL)
// 	{
// 		printf("%d\n",*(int *)(lst->content));
// 		lst = lst->next;
// 	}
// }

// int main(void)
// {
//     char *m = "Hello";
// 	t_list *s = ft_lstnew(m);
// 	printf("%s\n", ((char *)(s->content)));
// 	printf("%p\n", s->next);

// 	t_list *lst;

// 	lst = (t_list *)malloc(sizeof(t_list));
// 	lst = NULL;
// 	int a = 1;
// 	int b = 2;
// 	int c = 3;
// 	void *ptr_a = &a;
// 	void *ptr_b = &b;
//	void *ptr_c = &c;
// 	ft_lstadd_front(&lst, ptr_a);
// 	ft_lstadd_front(&lst, ptr_b);
// 	ft_lstadd_front(&lst, ptr_c);

// 	print_list(lst);
//  free (lst);
// }
