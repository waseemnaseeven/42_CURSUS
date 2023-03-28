/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:35:03 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/02/04 19:17:20 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(const char *s, char c)
{
	unsigned int	i;
	unsigned int	count_words;

	i = 0;
	count_words = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count_words++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count_words);
}

static void	*ft_freeword(char **word, int k)
{
	while (word[k])
	{
		free(word[k]);
		word[k] = NULL;
		k--;
	}
	free(word);
	word = NULL;
	return (word);
}

static char	**ft_dup(char **new_str, char const *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (start >= ft_strlen(s))
			new_str[j++] = NULL;
		else
		{
			new_str[j++] = ft_substr(s, start, i - start);
			if (new_str[j - 1] == NULL)
				ft_freeword(new_str, j);
		}
	}
	return (new_str);
}

char	**ft_split(char const *s, char c)
{
	char				**new_str;
	size_t				len;

	if ((char *)s == NULL)
		return (NULL);
	len = ft_count(((char *)s), c);
	new_str = malloc(sizeof(char *) * (len + 1));
	if (!new_str)
		return (0);
	new_str = ft_dup(new_str, s, c);
	new_str[len] = NULL;
	return (new_str);
}

// int	main(void)
// {
// 	char **tab;
// 	void *str = "Hello World la mif ";
// 	char c = ' ';
// 	int i = 0;
// 	//printf("%s\n", str);
// 	//printf("%c\n", c);
// 	tab = ft_split((char*)str, c);
// 	while (tab[i])
// 	{
// 		printf("%s\n", tab[i]);
// 		free(tab[i]);
// 		i++;
// 	}
// 	free(tab);
// }
