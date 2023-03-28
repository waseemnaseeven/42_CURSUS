/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:04:46 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/03/22 11:52:27 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_set_lexer_helper(t_data *data)
{
	if (data->lexer->token->type == QUOTE
		|| data->lexer->token->type == DOUBLE_QUOTE)
			;
	else if (!ft_strcmp(data->lexer->token->value, ">"))
		data->lexer->token->type = REDIR_OUTPUT;
	else if (!ft_strcmp(data->lexer->token->value, "<"))
		data->lexer->token->type = REDIR_INPUT;
	else if (!ft_strcmp(data->lexer->token->value, "<<"))
		data->lexer->token->type = REDIR_HEREDOC;
	else if (!ft_strcmp(data->lexer->token->value, ">>"))
		data->lexer->token->type = REDIR_OUTPUT_APPEND;
	else if (!ft_strcmp(data->lexer->token->value, "|"))
		data->lexer->token->type = PIPE;
	else if (data->lexer->token->value[0] == '-')
		data->lexer->token->type = FLAG;
	else if (data->lexer->token->value[0] == '\'')
		data->lexer->token->type = QUOTE;
	else if (data->lexer->token->value[0] == '"')
		data->lexer->token->type = DOUBLE_QUOTE;
	else if (ft_char_in_str(data->lexer->token->value, '$'))
		data->lexer->token->type = VARIABLE;
}

t_list_tok	*ft_set_lexer_type(t_data *data)
{
	t_list_tok	*temp;

	temp = data->lexer;
	while (data->lexer)
	{
		ft_set_lexer_helper(data);
		data->lexer = data->lexer->next;
	}
	return (temp);
}

t_list_tok	*ft_change_syntax(t_list_tok *lexer)
{
	t_list_tok	*temp;

	temp = lexer;
	while (lexer)
	{
		if (get_type(lexer) == REDIR_INPUT
			|| get_type(lexer) == REDIR_OUTPUT
			|| get_type(lexer) == REDIR_HEREDOC
			|| get_type(lexer) == REDIR_OUTPUT_APPEND)
			if (lexer->next && get_type(lexer->next) != INFILE
				&& get_type(lexer->next) != OUTFILE
				&& get_type(lexer->next) != OUTFILE_APPEND
				&& get_type(lexer->next) != DELIMITER)
				lexer->next->token->type = ARGUMENT;
		if (get_type(lexer) == PIPE || get_type(lexer) == REDIR_INPUT
			|| get_type(lexer) == REDIR_OUTPUT
			|| get_type(lexer) == REDIR_HEREDOC
			|| get_type(lexer) == REDIR_OUTPUT_APPEND)
			if (!(lexer->next))
				lexer->token->type = ARGUMENT;
		lexer = lexer->next;
	}
	return (temp);
}

void	ft_clean_lexer(t_data *data)
{
	data->lexer = ft_clean_quote(data, data->lexer, data->env);
	data->lexer = ft_white_space_in_variables(data->lexer, data);
	data->lexer = ft_change_redirection(data);
	data->lexer = ft_change_argument_type(data);
	data->lexer = ft_change_syntax(data->lexer);
}

void	ft_initialize(t_data *data)
{
	t_token		*token;
	t_token		*next;
	t_list_tok	*temp;

	data->index = 0;
	token = ft_create_token(data);
	data->lexer = ft_token_list_new(token);
	if (data->input[data->index])
	{
		while (data->input[data->index])
		{
			next = ft_create_token(data);
			temp = ft_token_list_new(next);
			if (!temp)
				ft_bad_malloc(data);
			ft_token_list_add_back(&(data->lexer), temp);
		}
	}
	data->index = 0;
	data->lexer = ft_set_lexer_type(data);
	ft_clean_lexer(data);
}
