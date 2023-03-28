/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:58:03 by aaudevar          #+#    #+#             */
/*   Updated: 2023/03/21 17:39:11 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char	*ft_get_variable(char **env, char *var)
{
	char	*variable_with_equal;

	if (!env || !env[0] || !var || !var[0])
		return (NULL);
	variable_with_equal = ft_strjoin(var, "=");
	while (*env && ft_strncmp(*env, variable_with_equal, ft_strlen(var) + 1))
		env++;
	free(variable_with_equal);
	if (!*env)
		return (NULL);
	return (*env + ft_strlen(var) + 1);
}

char	*ft_join_string(char *ret, char *s)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	if (!s)
		return (ret);
	if (!ret[0])
	{
		while (s[++i])
		{
			ret[j] = s[i];
			j++;
		}
		ret[j] = '\0';
	}
	else
	{
		while (ret[j])
			j++;
		while (s[++i])
			ret[j + i] = s[i];
		ret[j + i] = '\0';
	}
	return (ret);
}

char	*ft_copy_without_char(char *str, char c, char *ret)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i + count])
	{
		if (str[i + count] != c)
		{
			ret[i] = str[i + count];
			i++;
		}
		else
			count++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_remove_char(t_data *data, char *str, char c)
{
	char	*ret;
	int		i;
	int		count;

	i = -1;
	count = 0;
	if (!str)
		return (NULL);
	while (str[++i])
		if (str[i] == c)
			count++;
	ret = ft_calloc(i - count + 1, sizeof(char));
	if (!ret)
		ft_bad_malloc(data);
	ret = ft_copy_without_char(str, c, ret);
	free (str);
	return (ret);
}

t_list_tok	*ft_clean_quote(t_data *data, t_list_tok *lexer, char **env)
{
	t_list_tok	*temp;

	temp = lexer;
	while (lexer)
	{
		if (lexer->token->type == QUOTE || lexer->token->type == DOUBLE_QUOTE)
			lexer->token->value = unsplit(spl_quote(data, lexer->token->value));
		if (lexer->token->type == VARIABLE)
		{
			lexer->token->value = rep_var_env(data, lexer->token->value, env);
			lexer->token->value = replace_exit_code(data, lexer->token->value);
		}
		if (lexer->token->type == QUOTE || lexer->token->type == DOUBLE_QUOTE)
			lexer->token->type = ARGUMENT;
		lexer = lexer->next;
	}
	return (temp);
}
