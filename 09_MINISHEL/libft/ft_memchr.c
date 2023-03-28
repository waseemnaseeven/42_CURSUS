/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:31:10 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/11/08 17:37:31 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t size)
{
	unsigned const char	*tmp;
	unsigned char		ch;

	tmp = s;
	ch = c;
	while (size--)
	{
		if (*tmp++ == ch)
			return ((void *)(tmp - 1));
	}
	return (NULL);
}
