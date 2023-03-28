/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_quote_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:04:02 by aaudevar          #+#    #+#             */
/*   Updated: 2023/03/21 17:30:07 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char	**ft_clean_split(t_data *data, char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		if (split[i][0] == '\'')
			split[i] = ft_remove_char(data, split[i], '\'');
		else if (split[i][0] == '"')
		{
			split[i] = ft_remove_char(data, split[i], '"');
			split[i] = rep_var_env(data, split[i], data->env);
		}
		i++;
	}
	return (split);
}

char	*ft_make_word(t_data *data, char *str, char c)
{
	int		size;
	char	*split;

	size = 0;
	if (str[size] && c != 0)
	{
		size++;
		while (str[size] && str[size] != c)
			size++;
		if (str[size] == c)
			size++;
	}
	else if (str[size])
	{
		size++;
		while (str[size] && str[size] != '\'' && str[size] != '"')
			size++;
	}
	split = ft_calloc(size + 1, sizeof(char));
	if (!split)
		ft_bad_malloc(data);
	split[size] = '\0';
	return (split);
}

void	ft_count_split(char *str, int *i, int *count, char c)
{
	(*count)++;
	(*i)++;
	while (str[*i] && str[*i] != c)
				(*i)++;
	if (str[*i] && str[*i] == c)
				(*i)++;
}

int	ft_size_split(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] && str[i] == '\'')
			ft_count_split(str, &i, &count, '\'');
		if (str[i] && str[i] == '\"')
			ft_count_split(str, &i, &count, '"');
		if (str[i] && str[i] != '\'' && str[i] != '"')
		{
			count++;
			while (str[i] && str[i] != '"' && str[i] != '\'')
				i++;
		}
		if (!str[i])
			break ;
	}
	return (count);
}

char	*unsplit(char **split)
{
	char	*token;
	int		i;
	char	*temp;

	i = 0;
	if (split[i + 1])
	{
		token = ft_strjoin(split[i], split[i + 1]);
		i += 2;
		if (split[i])
		{
			while (split[i])
			{
				temp = ft_strjoin(token, split[i]);
				free(token);
				token = temp;
				i++;
			}
		}
	}
	else
		token = ft_strdup(split[0]);
	ft_free_array(split);
	return (token);
}
