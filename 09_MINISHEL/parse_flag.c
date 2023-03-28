/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 13:46:41 by aaudevar          #+#    #+#             */
/*   Updated: 2023/03/18 10:32:47 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_get_flag_helper(t_list_tok **lexer, int *flag, int j, int *index)
{
	if ((get_type(*lexer) == OUTFILE
			|| get_type(*lexer) == OUTFILE_APPEND) && *index != j)
		(*index)++;
	else if ((get_type(*lexer) == OUTFILE) && *index == j)
	{
		*flag = 1;
		(*index)++;
	}
	else if ((get_type(*lexer) == OUTFILE_APPEND) && *index == j)
	{
		*flag = 2;
		(*index)++;
	}
}

int	ft_get_flag(t_list_tok *lexer, int i, int j)
{
	int		pipe_number;
	int		flag;
	int		index;

	index = 0;
	pipe_number = ft_go_to_correct_pipe(&lexer, i);
	while (i == pipe_number && lexer)
	{
		if (get_type(lexer) == PIPE)
			pipe_number++;
		ft_get_flag_helper(&lexer, &flag, j, &index);
		if (index > j)
			break ;
		lexer = lexer->next;
	}
	return (flag);
}

int	ft_flag_size(t_list_tok *lexer, int i)
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

int	*ft_flag_array(t_data *data, t_list_tok *lexer, int i)
{
	int		*flags;
	int		size;
	int		j;

	size = ft_flag_size(lexer, i);
	flags = ft_calloc(size + 1, sizeof(int));
	j = 0;
	if (!flags)
		ft_bad_malloc(data);
	while (j < size)
	{
		flags[j] = ft_get_flag(lexer, i, j);
		j++;
	}
	flags[j] = 0;
	return (flags);
}
