/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: was <was@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:17:00 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/11/12 17:07:04 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_concatenate(char *s1, char *s2, char *new_str)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		new_str[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		new_str[j++] = s2[i];
		i++;
	}
	new_str[j] = '\0';
	return (new_str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*new_str;
	size_t		size1;
	size_t		size2;

	if ((!s1) || (!s2))
		return (NULL);
	size1 = ft_strlen((char *)s1);
	size2 = ft_strlen((char *)s2);
	new_str = malloc(((size1 + size2) + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	new_str = ft_concatenate((char *)s1, (char *)s2, new_str);
	return (new_str);
}
/*
int main (int ac, char **av)
{
	(void) ac;
	(void) av;
	char *s1 = "iozaehoaiz ";
	char *s2 = "iqghiosqegs";
	char *res = ft_strjoin(s1,s2);
	printf("%s", res);
	free (res);
}
*/
