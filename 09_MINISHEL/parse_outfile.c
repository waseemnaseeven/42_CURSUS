/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_outfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 11:46:03 by aaudevar          #+#    #+#             */
/*   Updated: 2023/03/18 10:08:31 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char	*ft_get_outfile(t_data *data, t_list_tok *lexer, int i, int j)
{
	int		pipe_number;
	char	*outfile;
	int		index;

	index = 0;
	pipe_number = ft_go_to_correct_pipe(&lexer, i);
	while (i == pipe_number && lexer)
	{
		if (get_type(lexer) == PIPE)
			pipe_number++;
		if ((get_type(lexer) == OUTFILE
				|| get_type(lexer) == OUTFILE_APPEND) && index != j)
			index++;
		else if ((get_type(lexer) == OUTFILE
				|| get_type(lexer) == OUTFILE_APPEND) && index == j)
		{
			outfile = ft_dup(data, lexer->token->value);
			index++;
		}	
		if (index > j)
			break ;
		lexer = lexer->next;
	}
	return (outfile);
}

int	ft_outfile_size(t_list_tok *lexer, int i)
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
		if (get_type(lexer) == OUTFILE || get_type(lexer) == OUTFILE_APPEND)
			size++;
		lexer = lexer->next;
	}
	return (size);
}

char	**ft_outfile_array(t_data *data, t_list_tok *lexer, int i)
{
	char	**outfile;
	int		size;
	int		j;

	size = ft_outfile_size(lexer, i);
	outfile = ft_calloc(size + 1, sizeof(char *));
	j = 0;
	if (!outfile)
		ft_bad_malloc(data);
	while (j < size)
	{
		outfile[j] = ft_get_outfile(data, lexer, i, j);
		j++;
	}
	outfile[j] = NULL;
	return (outfile);
}
