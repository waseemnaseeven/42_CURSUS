/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:02:29 by aaudevar          #+#    #+#             */
/*   Updated: 2023/03/04 12:17:53 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char	*ft_dup(t_data *data, const char *s)
{
	char	*dest;
	int		i;

	dest = malloc((ft_strlen((char *)s) + 1) * sizeof(char));
	if (!dest)
		ft_bad_malloc(data);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_cmd_size(t_list_tok *lexer, int i)
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
		if (get_type(lexer) == COMMAND || get_type(lexer) == FLAG
			|| get_type(lexer) == ARGUMENT)
			size++;
		lexer = lexer->next;
	}
	return (size);
}

int	ft_go_to_correct_pipe(t_list_tok **lexer, int i)
{
	int		pipe_number;

	pipe_number = 0;
	while (i != pipe_number && *lexer)
	{
		if (get_type(*lexer) == PIPE)
			pipe_number++;
		(*lexer) = (*lexer)->next;
	}
	return (pipe_number);
}

char	*ft_get_cmd(t_data *data, t_list_tok *lexer, int i, int j)
{
	int		pipe_number;
	char	*cmd;
	int		index;

	index = 0;
	pipe_number = ft_go_to_correct_pipe(&lexer, i);
	while (i == pipe_number && lexer)
	{
		if (get_type(lexer) == PIPE)
			pipe_number++;
		if ((get_type(lexer) == COMMAND || get_type(lexer) == FLAG
				|| get_type(lexer) == ARGUMENT) && index != j)
			index++;
		else if ((get_type(lexer) == COMMAND || get_type(lexer) == FLAG
				|| get_type(lexer) == ARGUMENT) && index == j)
		{
			cmd = ft_dup(data, lexer->token->value);
			index++;
		}	
		if (index > j)
			break ;
		lexer = lexer->next;
	}
	return (cmd);
}

char	**ft_cmds_array(t_data *data, t_list_tok *lexer, int i)
{
	char	**cmds;
	int		size;
	int		j;

	size = ft_cmd_size(lexer, i);
	cmds = ft_calloc(size + 1, sizeof(char *));
	j = 0;
	if (!cmds)
		ft_bad_malloc(data);
	while (j < size)
	{
		cmds[j] = ft_get_cmd(data, lexer, i, j);
		j++;
	}
	cmds[j] = NULL;
	return (cmds);
}
