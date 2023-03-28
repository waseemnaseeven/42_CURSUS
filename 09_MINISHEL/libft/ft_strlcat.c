/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:40:13 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/11/15 13:49:12 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	lsrc;
	size_t	i;
	size_t	ldest;

	if ((src == NULL) || (dest == NULL))
		return (0);
	ldest = ft_strlen((char *)dest);
	lsrc = ft_strlen((char *)src);
	i = 0;
	if (!size)
		return (lsrc);
	while (src[i] != '\0' && ldest + i < (size - 1))
	{
		dest[ldest + i] = src[i];
		i++;
	}
	dest[ldest + i] = '\0';
	if (size < ldest)
		return (lsrc + size);
	return (ldest + lsrc);
}

// int main(void)
// {
// 	char src[50] = "AAAAAAAAA";
// 	char dest[50] = "g";

// 	printf("%ld", ft_strlcat(dest, src, 0));
// }