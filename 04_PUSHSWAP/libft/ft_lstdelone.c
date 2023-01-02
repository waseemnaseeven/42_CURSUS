/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:59:25 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/11/18 11:04:35 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	else
	{
		del(lst->content);
		free(lst);
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

// void    freelist(t_list *lst)
// {
//     int i = 0;
//     while (lst[i])
//     {
//         free(lst[i]);
//         i++;
//     }   
// }
//
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
//     ft_lstdelone(ptr_b, &freelist);
// 	ft_lstadd_back(&list, ptr_c);

// 	print_list(list);
// }
