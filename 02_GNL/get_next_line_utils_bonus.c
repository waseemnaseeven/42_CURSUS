/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:43:12 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/12/01 12:55:45 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new_str;
	int		i;
	size_t	size;

	if (s1)
		size = ft_strlen(s1);
	if (s2)
		size = ft_strlen (s1) + ft_strlen(s2);
	new_str = malloc(sizeof(char) * (size + 1));
	if (!new_str)
		return (NULL);
	size = 0;
	while (s1 && s1[size])
	{
		new_str[size] = s1[size];
		size++;
	}
	i = -1;
	while (s2 && s2[++i])
		new_str[size++] = s2[i];
	new_str[size] = '\0';
	free((char *)s1);
	return (new_str);
}

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
