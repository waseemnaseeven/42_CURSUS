/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:07:03 by aaudevar          #+#    #+#             */
/*   Updated: 2023/03/21 17:22:59 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_fill_word_quote(char *str, int *i, char **split, int *j)
{
	int	k;

	k = 0;
	ft_copy_split(str, i, split[*j], &k);
	while (str[*i] && str[*i] != '\'')
		ft_copy_split(str, i, split[*j], &k);
	if (str[*i] == '\'')
	{
		ft_copy_split(str, i, split[*j], &k);
		k = 0;
		(*j)++;
	}
}

void	ft_fill_word_double_quote(char *str, int *i, char **split, int *j)
{
	int	k;

	k = 0;
	ft_copy_split(str, i, split[*j], &k);
	while (str[*i] && str[*i] != '"')
		ft_copy_split(str, i, split[*j], &k);
	if (str[*i] == '"')
	{
		ft_copy_split(str, i, split[*j], &k);
		k = 0;
		(*j)++;
	}
}

void	ft_fill_word(char *str, int *i, char **split, int *j)
{
	int	k;

	k = 0;
	ft_copy_split(str, i, split[*j], &k);
	while (str[*i] && str[*i] != '"' && str[*i] != '\'')
		ft_copy_split(str, i, split[*j], &k);
	k = 0;
	(*j)++;
}

char	**ft_make_split(t_data *data, char *str, char **split)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] && str[i] == '\'')
		{
			split[j] = ft_make_word(data, str + i, '\'');
			ft_fill_word_quote(str, &i, split, &j);
		}
		if (str[i] && str[i] == '"')
		{
			split[j] = ft_make_word(data, str + i, '"');
			ft_fill_word_double_quote(str, &i, split, &j);
		}
		if (str[i] && str[i] != '\'' && str[i] != '"')
		{
			split[j] = ft_make_word(data, str + i, 0);
			ft_fill_word(str, &i, split, &j);
		}
	}
	return (split);
}

char	**spl_quote(t_data *data, char *str)
{
	int		size;
	char	**split;

	size = ft_size_split(str);
	split = ft_calloc((size + 1), sizeof(char *));
	if (!split)
		ft_bad_malloc(data);
	split = ft_make_split(data, str, split);
	free(str);
	split[size] = NULL;
	ft_clean_split(data, split);
	return (split);
}
