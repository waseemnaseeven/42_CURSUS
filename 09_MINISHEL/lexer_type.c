/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 09:48:37 by aaudevar          #+#    #+#             */
/*   Updated: 2023/03/18 10:03:59 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

t_type	get_type(t_list_tok *lexer)
{
	if (lexer)
		return (lexer->token->type);
	return (NONE);
}

t_list_tok	*ft_change_redirection(t_data *data)
{
	t_list_tok	*temp;

	temp = data->lexer;
	while (data->lexer)
	{
		if (get_type(data->lexer) == REDIR_OUTPUT)
			if (data->lexer->next)
				data->lexer->next->token->type = OUTFILE;
		if (get_type(data->lexer) == REDIR_HEREDOC)
			if (data->lexer->next)
				data->lexer->next->token->type = DELIMITER;
		if (get_type(data->lexer) == REDIR_INPUT)
			if (data->lexer->next)
				data->lexer->next->token->type = INFILE;
		if (get_type(data->lexer) == REDIR_OUTPUT_APPEND)
			if (data->lexer->next)
				data->lexer->next->token->type = OUTFILE_APPEND;
		data->lexer = data->lexer->next;
	}
	return (temp);
}

t_list_tok	*ft_change_argument_type(t_data *data)
{
	t_list_tok	*temp;

	temp = data->lexer;
	while (data->lexer)
	{
		if (get_type(data->lexer) == FLAG)
			if (data->lexer->previous)
				if (data->lexer->previous->token->type == ARGUMENT)
				data->lexer->previous->token->type = COMMAND;
		if (get_type(data->lexer) == REDIR_INPUT)
			if (data->lexer->previous)
				if (data->lexer->previous->token->type == ARGUMENT)
					data->lexer->previous->token->type = COMMAND;
		if (get_type(data->lexer) == ARGUMENT)
			if (!data->lexer->previous)
					data->lexer->token->type = COMMAND;
		if (get_type(data->lexer) == ARGUMENT)
			if (data->lexer->previous)
				if (data->lexer->previous->token->type == PIPE)
					data->lexer->token->type = COMMAND;
		data->lexer = data->lexer->next;
	}
	return (temp);
}
