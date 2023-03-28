/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:21:30 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/11/12 17:01:46 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	const char		*s;
	size_t			i;
	size_t			len;

	s = src;
	i = 0;
	len = ft_strlen(s);
	if (!src)
		return (0);
	if (size == 0)
		return (len);
	if (size != 0)
	{
		while (s[i] && i < size - 1)
		{
			dest[i] = s[i];
			i++;
		}
	}
	dest[i] = '\0';
	return (len);
}
/*
int	main(void)
{
	char src[] = "Hello";
	char dest[] = "aloha";

	printf("%ld\n", ft_strlcpy(dest,src,9));
	printf("%s", dest);
}
*/
