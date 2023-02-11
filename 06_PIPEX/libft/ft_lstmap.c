/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:59:55 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/11/18 11:52:21 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*tmp;

	ret = 0;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&ret, del);
			return (NULL);
		}
		ft_lstadd_back(&ret, tmp);
		lst = lst->next;
	}
	return (ret);
}

// char	ft_test(unsigned int i, char c)
// {
// 	char d;
// 	i = 1;
// 	d = c + i;
// 	return d;
// }

// static void print_list(t_list *lst)
// {
//     while (lst)
//     {
//         printf("lst = %d\n", *(int *)lst->content);
//         lst = lst->next;
//     }
// }

// int main(void)
// {
//     t_list *new = malloc(sizeof(t_list));
//     new = NULL;
//     int a = 26;
//     int b = 98;
//     int c = 103;
//     void *ptr_a = &a;
//     void *ptr_b = &b;
//     void *ptr_c = &c;
//     ft_lstadd_front(&new, ptr_a);
//     ft_lstadd_front(&new, ptr_b);
//     ft_lstadd_front(&new, ptr_c);
//     ft_lstmap(&new, );

//     print_list(new);
// }
