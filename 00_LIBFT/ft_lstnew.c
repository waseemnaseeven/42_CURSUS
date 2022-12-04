/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:20:13 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/11/18 11:39:21 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*m;

	m = malloc(sizeof(t_list));
	if (!m)
		return (NULL);
	m->content = content;
	m->next = NULL;
	return (m);
}

// int main(void)
// {
// 	char *m = "Hello";
// 	t_list *s = ft_lstnew(m);
// 	printf("%s\n", ((char *)(s->content)));
// 	printf("%p", s->next);
// }
