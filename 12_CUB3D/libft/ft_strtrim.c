/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:30:29 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/11/18 11:53:45 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char const s1, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s1)
			return (1);
		i++;
	}
	return (0);
}

static int	get_first_pos(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (is_in_set(s1[i], set) == 1)
		i++;
	return (i);
}

static int	get_last_pos(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (is_in_set(s1[i], set) == 1)
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	char		*trim;
	size_t		s_len;
	size_t		end;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = get_first_pos(s1, set);
	end = get_last_pos(s1, set);
	s_len = ft_strlen(s1);
	if (start == s_len)
	{
		trim = malloc(sizeof(char));
		if (trim == NULL)
			return (NULL);
		trim[0] = '\0';
		return (trim);
	}
	else
		trim = ft_substr(s1, start, (end - start + 1));
	return (trim);
}

// int main (void)
// {
// 	char *str = "  \t \t \n   \n\n\n\t";
// 	char *set = " \n\t";

// 	char *lol = "	Helloworld!Hello";
// 	char *lel = "	Hello";

// 	char *hel = "AAA AAA";
// 	char *po = "AAA";

// 	char *new_str = ft_strtrim(str, set);
// 	char *lal = ft_strtrim(lol,lel);
// 	char *pr = ft_strtrim(hel, po);
// 	printf("%s\n", new_str);
// 	printf("%s\n", lal);
// 	printf("%s\n", pr);
// 	free(new_str);
// 	free(lal);
// 	free(pr);
// }
