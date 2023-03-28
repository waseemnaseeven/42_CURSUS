/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:38:32 by aaudevar          #+#    #+#             */
/*   Updated: 2023/03/18 09:53:22 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_token_size(t_data *data, t_token *token, int *j)
{
	if (data->input[data->index + *j] == '\'')
	{
		if (token->type == ARGUMENT)
			token->type = QUOTE;
		(*j)++;
		while (data->input[data->index + *j]
			&& data->input[data->index + *j] != '\'')
			(*j)++;
		if (data->input[data->index + *j] == '\'')
			(*j)++;
	}
	else if (data->input[data->index + *j] == '"')
	{
		if (token->type == ARGUMENT)
			token->type = DOUBLE_QUOTE;
		(*j)++;
		while (data->input[data->index + *j]
			&& data->input[data->index + *j] != '"')
			(*j)++;
		if (data->input[data->index + *j] == '"')
			(*j)++;
	}
	else
		(*j)++;
}

void	ft_token_copy(t_data *data, char **temp, int *j)
{
	if (data->input[data->index + *j] == '\'')
		ft_token_copy_quote(data, temp, j, '\'');
	else if (data->input[data->index + *j] == '"')
		ft_token_copy_quote(data, temp, j, '"');
	else
	{
		(*temp)[*j] = data->input[data->index + *j];
		(*j)++;
	}
}

void	ft_copy_into_token(t_data *data, char **temp, int *j)
{
	if (data->input[data->index + *j] == '|'
		|| is_redirection(data->input[data->index + *j]))
	{
		(*temp)[*j] = data->input[data->index + *j];
		(*j)++;
		if (data->input[data->index + *j] == '<'
			|| data->input[data->index + *j] == '>')
		{
			if (is_redirection(data->input[data->index + *j]))
			{
				(*temp)[*j] = data->input[data->index + *j];
				(*j)++;
			}		
		}
	}
	else
	{
		while (data->input[data->index + *j]
			&& (!is_sep(data->input[data->index + *j])))
			ft_token_copy(data, temp, j);
	}
}

void	ft_classic_token(t_data *data, t_token *token, char **temp)
{
	int	j;

	j = 0;
	token->type = ARGUMENT;
	if (data->input[data->index + j] == '|'
		|| is_redirection(data->input[data->index + j]))
	{
		j++;
		if (is_redirection(data->input[data->index + j]))
			j++;
	}
	else
	{
		while (data->input[data->index + j]
			&& !is_sep(data->input[data->index + j]))
			ft_token_size(data, token, &j);
	}
	*temp = ft_calloc(j + 1, sizeof(char));
	if (!(*temp))
		ft_bad_malloc(data);
	j = 0;
	ft_copy_into_token(data, temp, &j);
	(*temp)[j] = '\0';
	data->index = data->index + j;
}

t_token	*ft_create_token(t_data *data)
{
	char	*temp;
	t_token	*token;

	temp = NULL;
	token = ft_calloc(1, sizeof(t_token));
	if (!token)
		ft_bad_malloc(data);
	while (data->input[data->index] && is_white_space(data->input[data->index]))
		data->index++;
	ft_classic_token(data, token, &temp);
	while (data->input[data->index] && is_white_space(data->input[data->index]))
		data->index++;
	token->value = temp;
	return (token);
}
