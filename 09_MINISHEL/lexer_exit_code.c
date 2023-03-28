/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_exit_code.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:37:31 by aaudevar          #+#    #+#             */
/*   Updated: 2023/03/18 10:44:21 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_copy_split(char *str, int *i, char *split, int *k)
{
	split[*k] = str[*i];
	(*i)++;
	(*k)++;
}

char	*ft_copy_exit_code(char *ret, char *exit, int *i, int *size)
{
	(*i)++;
	while (*exit)
	{
		ret[*size] = *exit;
		exit++;
		(*size)++;
	}
	return (ret);
}

char	*ft_copy_word_with_exit_code(char *str, char *ret, char *exit, int i)
{
	int	size;

	size = 0;
	while (str[i])
	{
		if (str[i] && str[i] == '$')
		{
			i++;
			if (str[i] && str[i] == '?')
				ret = ft_copy_exit_code(ret, exit, &i, &size);
		}
		else
		{
			ret[size] = str[i];
			size++;
			i++;
		}
	}
	ret[size] = '\0';
	return (ret);
}

int	ft_size_new_str(char *str, int i, char *exit_code)
{
	int	size;

	size = 0;
	if (!str)
		return (size);
	while (str[i])
	{
		if (str[i] && str[i] == '$')
		{
			i++;
			size++;
			if (str[i] && str[i] == '?')
			{
				size += ft_strlen(exit_code);
				i++;
			}	
		}
		else
		{
			i++;
			size++;
		}
	}
	return (size);
}

char	*replace_exit_code(t_data *data, char *str)
{
	int		i;
	int		size;
	char	*ret;
	char	*exit_code;

	exit_code = ft_itoa(g_exit_code);
	i = 0;
	size = ft_size_new_str(str, i, exit_code);
	ret = ft_calloc(size + 1, sizeof(char));
	if (!ret)
		ft_bad_malloc(data);
	i = 0;
	ret = ft_copy_word_with_exit_code(str, ret, exit_code, i);
	free(str);
	free(exit_code);
	return (ret);
}
