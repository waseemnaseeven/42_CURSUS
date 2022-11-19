/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:58:18 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/11/18 11:13:05 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	node = *lst;
	if (*lst != NULL)
	{
		while (node->next != NULL)
			node = node->next;
		node->next = new;
	}
	else
		*lst = new;
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

// int main(void)
// {
// 	t_list *list;

// 	list = (t_list *)malloc(sizeof(t_list));
// 	list = NULL;
// 	int a = 1;
// 	int b = 2;
// 	int c = 3;
// 	void *ptr_a = &a;
// 	void *ptr_b = &b;
// 	void *ptr_c = &c;
// 	ft_lstadd_back(&list, ptr_a);
// 	ft_lstadd_back(&list, ptr_b);
// 	ft_lstadd_back(&list, ptr_c);

// 	print_list(list);
//     free(list);
// }
