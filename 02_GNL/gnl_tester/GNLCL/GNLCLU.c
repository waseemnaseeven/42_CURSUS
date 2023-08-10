/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GNLCLU.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:44:25 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/11/25 15:11:38 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GNLCL.h"



size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

/*
	return un pointeur sur le dernier élément de la liste
*/
// t_list	*ft_lstlast(t_list *stash)
// {
// 	t_list	*node;

// 	node = stash;
// 	if (node == NULL)
// 		return (NULL);
// 	while (node->next != NULL)
// 		node = node->next;
// 	return (node);
// }

char	*ft_strdup(char *s)
{
	char			*dest;
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = ft_strlen(s);
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
	{
		free(dest);
		return (NULL);
	}
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
