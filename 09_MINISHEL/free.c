/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:52:35 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/03/21 14:48:38 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_free_array(char **array)
{
	int	j;

	j = 0;
	if (!array)
		return ;
	if (array[j])
	{
		while (array[j])
		{
			free(array[j]);
			j++;
		}
	}
	free(array);
}

void	ft_free_process(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbcmds)
	{
		ft_free_array(data->process[i].cmds);
		ft_free_array(data->process[i].infile);
		ft_free_array(data->process[i].outfile);
		free(data->process[i].flag_outfile);
		ft_free_array(data->process[i].delimiters);
		i++;
	}
	free (data->process);
}

void	ft_free_general_data(t_data *data)
{
	int	i;

	i = -1;
	if (data->env)
	{
		while (data->env[++i])
			free(data->env[i]);
		free(data->env);
	}
	if (data->input)
		free(data->input);
	if (data->path)
		ft_free_array(data->path);
}

void	ft_bad_malloc(t_data *data)
{
	ft_free_general_data(data);
	if (data->process)
		ft_free_process(data);
	if (data->lexer)
		ft_lst_token_clear(&(data->lexer), del);
	ft_putstr_fd("Fatal Error : Bad Malloc\n", 2);
	exit (1);
}

void	ft_free_process_one_cmd(t_data *data)
{
	ft_free_array(data->path);
	ft_lst_token_clear(&(data->lexer), del);
	ft_free_process(data);
	ft_free_array(data->env);
	free(data->valid_path);
}
