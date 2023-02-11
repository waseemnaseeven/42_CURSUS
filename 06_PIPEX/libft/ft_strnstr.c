/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:02:50 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/11/09 17:09:36 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *) big);
	if (len > 0)
	{
		while (big[i] && i < len)
		{
			j = 0;
			while (big[i + j] == little[j] && i + j < len)
			{
				j++;
				if (little[j] == '\0')
					return ((char *) &big[i]);
			}
			i++;
		}
	}
	return (0);
}
/*
int main (void)
{
	char str[] = "Hello les gars";
	char to_find[] = NULL;

	printf("%s", ft_strnstr(str, to_find, 14));
	return (0);
}
*/