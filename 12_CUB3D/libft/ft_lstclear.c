/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:59:15 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/11/18 11:52:59 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	tmp = *lst;
	if (!lst)
		return ;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}

// void	print_list(t_list *list)
// {
// 	while (list != NULL)
// 	{
// 		printf("%d\n",*(int *)list->content);
// 		list = list->next;
//         free (list);
// 	}
// }

// static void ft_memdel_range(void *mem)
// {
//     if (mem)
//     {
//         free(mem);
//         mem = NULL;
//     }
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
//     ft_lstclear(&lst, ft_memdel_range);

// 	print_list(lst);
// }
