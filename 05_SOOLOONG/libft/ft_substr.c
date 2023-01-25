/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:29:18 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/11/15 10:29:42 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	lsrc;
	char			*dest;

	if (!s)
		return (NULL);
	lsrc = ft_strlen(s);
	if (lsrc < start)
	{
		dest = malloc(sizeof(char));
		dest[0] = '\0';
		return (dest);
	}
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// int main()
// {
//     char src[] = "Bonjour";

//     int start = 3;
//     int len = 12;
//     char *dest = ft_substr(src, start, len);
//     printf("%s\n", dest);
// 	free (dest);

// 	return 0;
// }
