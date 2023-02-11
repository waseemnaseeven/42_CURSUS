/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:59:44 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/11/18 11:47:18 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*node;

	node = lst;
	if (node == NULL)
		return (NULL);
	while (node->next != NULL)
		node = node->next;
	return (node);
}

// void	print_list(t_list *list)
// {
// 	while (list != NULL)
// 	{
// 		printf("%d\n", *(int *)list->content);
// 		list = list->next;
// 	}
// }

// int main() 
// {
//   t_list *head;
//   int a = 6;
//   int b = 6;
//   int c = 7;
//   void* ptr = &a;
//   void* pt = &b;
//   void* p = &c;
//   head = (t_list *)malloc(sizeof(t_list));
//   head = ft_lstnew(ptr);
//   head->next = ft_lstnew(pt);
//   head->next->next = ft_lstnew(p);
//   //display(head);
//   print_list(ft_lstlast(head));
//   return 0;
// }
