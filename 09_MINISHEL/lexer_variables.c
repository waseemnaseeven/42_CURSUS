/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_variables.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:44:40 by aaudevar          #+#    #+#             */
/*   Updated: 2023/03/18 10:44:08 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	ft_size_of_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

t_list_tok	*new_list_with_token(char *value, t_data *data)
{
	t_token		*token;
	t_list_tok	*new;

	token = ft_calloc(1, sizeof(t_token));
	if (!token)
		ft_bad_malloc(data);
	token->type = ARGUMENT;
	token->value = ft_strdup(value);
	if (!token->value)
		ft_bad_malloc(data);
	new = ft_token_list_new(token);
	if (!new)
		ft_bad_malloc(data);
	return (new);
}

void	insert_new_list(t_list_tok **lexer, t_list_tok *new)
{
	t_list_tok	*next;

	if ((*lexer)->next)
	{
		next = (*lexer)->next;
		new->next = (*lexer)->next;
		new->previous = (*lexer);
		(*lexer)->next = new;
		next->previous = new;
	}
	else
		ft_token_list_add_back(lexer, new);
}

void	ft_white_space_helper(t_list_tok **lexer, t_data *data)
{
	char		**split;
	int			size;
	t_list_tok	*new;

	if ((*lexer)->token->value[0] != '\0')
	{
		split = ft_split((*lexer)->token->value, ' ');
		if (!split)
			ft_bad_malloc(data);
		free((*lexer)->token->value);
		(*lexer)->token->value = ft_strdup(split[0]);
		size = ft_size_of_split(split);
		while (size > 1)
		{
			(*lexer)->token->type = ARGUMENT;
			new = new_list_with_token(split[size - 1], data);
			insert_new_list(lexer, new);
			size--;
		}
		ft_free_array(split);
	}
}

t_list_tok	*ft_white_space_in_variables(t_list_tok *lexer, t_data *data)
{
	t_list_tok	*temp;

	temp = lexer;
	while (lexer)
	{
		if (lexer->token->type == VARIABLE)
		{
			lexer->token->type = ARGUMENT;
			if (lexer->token->value[0] != '\0')
				ft_white_space_helper(&lexer, data);
		}
		lexer = lexer->next;
	}
	return (temp);
}
