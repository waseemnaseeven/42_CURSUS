/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:35:19 by aaudevar          #+#    #+#             */
/*   Updated: 2023/03/22 11:52:03 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	ft_numbers_of_commands(t_list_tok *lexer)
{
	int	cmds;

	cmds = 1;
	while (lexer)
	{
		if (get_type(lexer) == PIPE)
			cmds++;
		lexer = lexer->next;
	}
	return (cmds);
}

t_process	*ft_make_process_array(t_data *data)
{
	t_process	*process;
	int			i;

	i = 0;
	process = ft_calloc(data->nbcmds, sizeof(t_process));
	if (!process)
		ft_bad_malloc(data);
	while (i < data->nbcmds)
	{
		process[i].cmds = ft_cmds_array(data, data->lexer, i);
		process[i].infile = ft_infile_array(data, data->lexer, i);
		process[i].outfile = ft_outfile_array(data, data->lexer, i);
		process[i].flag_outfile = ft_flag_array(data, data->lexer, i);
		process[i].is_here_doc = ft_count_here_doc(data->lexer, i);
		process[i].delimiters = ft_delimiter_array(data, data->lexer, i);
		i++;
	}
	return (process);
}

void	ft_parsing(t_data *data)
{
	data->nbcmds = ft_numbers_of_commands(data->lexer);
	data->process = ft_make_process_array(data);
}
