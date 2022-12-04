/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:00:03 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/11/18 11:46:55 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	if (lst == NULL)
		return (0);
	else
		return (ft_lstsize(lst->next) + 1);
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
// 	void *ptr_c = &c;
// 	ft_lstadd_front(&lst, ptr_a);
// 	ft_lstadd_front(&lst, ptr_b);
// 	ft_lstadd_front(&lst, ptr_c);

// 	print_list(lst);
//  printf("%d\n", ft_lstsize(lst));
//  free (lst);
// }
