/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:50:58 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/03/18 16:51:45 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_free_not_execve(t_data *data)
{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(data->process->cmds[0], 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	g_exit_code = 127;
	restore_fd(data->saved_stdin, data->saved_stdout);
	ft_free_process(data);
	ft_lst_token_clear(&(data->lexer), del);
	ft_free_array(data->path);
	ft_free_array(data->env);
}

void	ft_free_infinite_loop(t_data *data)
{
	ft_free_array(data->path);
	ft_lst_token_clear(&(data->lexer), del);
	ft_free_process(data);
	free(data->input);
}
