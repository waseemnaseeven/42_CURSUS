/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_here_doc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:56:36 by aaudevar          #+#    #+#             */
/*   Updated: 2023/03/18 10:04:20 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	ft_count_here_doc(t_list_tok *lexer, int i)
{
	int	count;
	int	pipe_number;

	count = 0;
	pipe_number = 0;
	while (i != pipe_number && lexer)
	{
		if (get_type(lexer) == PIPE)
			pipe_number++;
		lexer = lexer->next;
	}
	while (i == pipe_number && lexer)
	{
		if (get_type(lexer) == PIPE)
			pipe_number++;
		if (get_type(lexer) == DELIMITER)
			count++;
		lexer = lexer->next;
	}
	return (count);
}

char	*ft_get_delimiter(t_data *data, t_list_tok *lexer, int i, int j)
{
	int		pipe_number;
	char	*delimiter;
	int		index;

	index = 0;
	pipe_number = ft_go_to_correct_pipe(&lexer, i);
	while (i == pipe_number && lexer)
	{
		if (get_type(lexer) == PIPE)
			pipe_number++;
		if ((get_type(lexer) == DELIMITER) && index != j)
			index++;
		else if ((get_type(lexer) == DELIMITER) && index == j)
		{
			delimiter = ft_dup(data, lexer->token->value);
			index++;
		}	
		if (index > j)
			break ;
		lexer = lexer->next;
	}
	return (delimiter);
}

int	ft_delimiter_size(t_list_tok *lexer, int i)
{
	int	size;
	int	pipe_number;

	size = 0;
	pipe_number = 0;
	while (i != pipe_number && lexer)
	{
		if (get_type(lexer) == PIPE)
			pipe_number++;
		lexer = lexer->next;
	}
	while (i == pipe_number && lexer)
	{
		if (get_type(lexer) == PIPE)
			pipe_number++;
		if (get_type(lexer) == DELIMITER)
			size++;
		lexer = lexer->next;
	}
	return (size);
}

char	**ft_delimiter_array(t_data *data, t_list_tok *lexer, int i)
{
	char	**delimiter;
	int		size;
	int		j;

	size = ft_delimiter_size(lexer, i);
	delimiter = ft_calloc(size + 1, sizeof(char *));
	j = 0;
	if (!delimiter)
		ft_bad_malloc(data);
	while (j < size)
	{
		delimiter[j] = ft_get_delimiter(data, lexer, i, j);
		j++;
	}
	delimiter[j] = NULL;
	return (delimiter);
}
