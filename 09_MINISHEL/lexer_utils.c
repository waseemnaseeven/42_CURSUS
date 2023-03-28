/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 09:49:00 by aaudevar          #+#    #+#             */
/*   Updated: 2023/03/18 09:54:16 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	ft_char_in_str(char *str, char c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			if (str[i + 1])
			{
				if (str[i + 1] != '?' && str[i + 1] != '\n')
					g_exit_code = 0;
				if (str[i + 1] != '\n')
					return (1);
			}
		}
		i++;
	}
	return (0);
}

int	ft_get_size(char *str, t_data *data, int size, int *i)
{
	int		j;
	int		var_size;
	char	*var;

	j = 0;
	var_size = 0;
	(*i)++;
	while (str[*i] && !is_white_space(str[*i])
		&& str[*i] != '$' && str[*i] != '\'')
	{
		var_size++;
		(*i)++;
	}
	var = ft_calloc(var_size + 1, 1);
	if (!var)
		ft_bad_malloc(data);
	var[var_size] = '\0';
	while (j < var_size)
	{
		var[j] = str[*i - var_size + j];
		j++;
	}
	size += ft_strlen(ft_get_variable(data->env, var));
	free(var);
	return (size);
}

char	*ft_get_word(t_data *data, char *str, int *i)
{
	char	*var;
	int		j;
	int		var_size;

	j = 0;
	var_size = 0;
	(*i)++;
	while (str[*i] && !is_white_space(str[*i])
		&& str[*i] != '$' && str[*i] != '\'')
	{
		var_size++;
		(*i)++;
	}
	var = ft_calloc(var_size + 1, 1);
	if (!var)
		ft_bad_malloc(data);
	var[var_size] = '\0';
	while (j < var_size)
	{
		var[j] = str[*i - var_size + j];
		j++;
	}
	return (var);
}

char	*ft_copy_var(t_data *data, char *str, char **env, char *ret)
{
	int		i;
	int		size;
	char	*var;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] && (str[i] != '$' || (str[i + 1] && str[i + 1] == '?')))
		{
			ret[size] = str[i];
			i++;
			size++;
		}
		else if (str[i] && str[i] == '$')
		{
			var = ft_get_word(data, str, &i);
			ft_join_string(ret, ft_get_variable(env, var));
			size += ft_strlen(ft_get_variable(env, var));
			free(var);
			var = NULL;
		}
	}
	ret[size] = '\0';
	return (ret);
}

char	*rep_var_env(t_data *data, char *str, char **env)
{
	int		size;
	char	*ret;
	int		i;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] && (str[i] != '$' || (str[i + 1] && str[i + 1] == '?')))
		{
			i++;
			size++;
		}
		else if (str[i] && str[i] == '$')
			size += ft_get_size(str, data, size, &i);
	}
	ret = ft_calloc(size + 1, sizeof(char));
	if (!ret)
		ft_bad_malloc(data);
	ret = ft_copy_var(data, str, env, ret);
	free (str);
	return (ret);
}
