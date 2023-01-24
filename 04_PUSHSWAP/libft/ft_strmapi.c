/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:28:23 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/11/15 10:28:35 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		len;
	size_t		i;
	char		*res;

	if ((!s) || (!f))
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	i = 0;
	while (len--)
	{
		res[i] = (*f)(i, res[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
/*
char	ft_test(unsigned int i, char c)
{
	char d;
	i = 1;
	d = c + i;
	return d;
}

int main(void)
{
	char str1[] = "abc";
	char* str2;
	str2 = ft_strmapi(str1, *ft_test);
	printf("%s\n", str2);
	free(str2);
}
*/
