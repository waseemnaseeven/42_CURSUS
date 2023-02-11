/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:07:21 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/01/08 17:02:43 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	dest = malloc((ft_strlen((char *)s) + 1) * sizeof(char));
	if (!dest)
	{
		free(dest);
		return (NULL);
	}
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int	main(void)
{
	char *src = "salut les gars";
	char *dd = "yo test";

	printf("%s", ft_strdup(dd));
	printf("%s", ft_strdup(src));
}
*/
