/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:33:25 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/03/22 11:38:03 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	cmd_is_null_if(t_data *data, t_process process)
{
	if (process.cmds[0])
	{
		if (process.cmds[0][0] == '\0')
		{
			restore_fd(data->saved_stdin, data->saved_stdout);
			ft_free_process_one_cmd(data);
			exit(g_exit_code);
		}
	}
	if (process.cmds[0] == NULL)
	{
		restore_fd(data->saved_stdin, data->saved_stdout);
		if (process.file_hd)
			free(process.file_hd);
		return (1);
	}
	return (0);
}

int	ft_exec(t_data *data, t_process process)
{
	if (cmd_is_null_if(data, process) == 1)
		return (1);
	data->valid_path = get_valid_path(data, process.cmds[0]);
	if (!data->valid_path && process.cmds[0][0] != '\0')
	{
		ft_no_valid_path(data, process.cmds);
		return (1);
	}
	if (execve(data->valid_path, process.cmds, data->env) == -1)
	{
		ft_free_not_execve(data);
		return (0);
	}
	return (1);
}

void	ft_exec_one_cmd(t_data *data, t_process process)
{
	int	i;

	i = -1;
	while (++i < data->nbcmds)
	{
		data->pid[i] = fork();
		signal(SIGINT, ft_handle_signals_interactive);
		signal(SIGQUIT, ft_handle_signals_interactive);
		if (process.cmds[0])
			if (!ft_strncmp(process.cmds[0], "./", 2))
				ft_ignore_signals();
		if (data->pid[i] < 0)
			return ;
		if (data->pid[i] == 0)
		{
			if (ft_exec(data, process) == 1)
				ft_free_process_one_cmd(data);
			exit (g_exit_code);
		}
	}
}

void	ft_exec_one(t_data *data)
{
	if (ft_check_redirection(data, data->process[0], 1) == 1)
	{
		g_exit_code = 1;
		return ;
	}
	if (ft_check_builtins(data->process[0].cmds) != 1)
	{
		ft_builtins(data, data->process[0]);
		rebuilt_stdin_stdout(data);
	}
	else
	{
		ft_exec_one_cmd(data, data->process[0]);
		rebuilt_stdin_stdout(data);
	}
}
