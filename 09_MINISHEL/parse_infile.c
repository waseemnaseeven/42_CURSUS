/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_infile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:51:14 by aaudevar          #+#    #+#             */
/*   Updated: 2023/03/18 10:07:38 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char	*ft_get_infile(t_data *data, t_list_tok *lexer, int i, int j)
{
	int		pipe_number;
	char	*infile;
	int		index;

	index = 0;
	pipe_number = ft_go_to_correct_pipe(&lexer, i);
	while (i == pipe_number && lexer)
	{
		if (get_type(lexer) == PIPE)
			pipe_number++;
		if ((get_type(lexer) == INFILE) && index != j)
			index++;
		else if ((get_type(lexer) == INFILE) && index == j)
		{
			infile = ft_dup(data, lexer->token->value);
			index++;
		}	
		if (index > j)
			break ;
		lexer = lexer->next;
	}
	return (infile);
}

int	ft_infile_size(t_list_tok *lexer, int i)
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
		if (get_type(lexer) == INFILE)
			size++;
		lexer = lexer->next;
	}
	return (size);
}

char	**ft_infile_array(t_data *data, t_list_tok *lexer, int i)
{
	char	**infile;
	int		size;
	int		j;

	size = ft_infile_size(lexer, i);
	infile = ft_calloc(size + 1, sizeof(char *));
	j = 0;
	if (!infile)
		ft_bad_malloc(data);
	while (j < size)
	{
		infile[j] = ft_get_infile(data, lexer, i, j);
		j++;
	}
	infile[j] = NULL;
	return (infile);
}
