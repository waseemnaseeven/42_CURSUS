/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:47:18 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/09/25 11:43:37 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	ft_check_builtins_pipe(char **arg)
{
	if (ft_strcmp(arg[0], "cd") == 0
		||ft_strcmp(arg[0], "export") == 0
		||ft_strcmp(arg[0], "unset") == 0
		||ft_strcmp(arg[0], "exit") == 0)
		return (0);
	else
		return (1);
}

int	ft_exec_multiple_cmds(t_data *data, t_process process, char **cmds)
{
	if (cmds[0] == NULL)
	{
		restore_fd(data->saved_stdin, data->saved_stdout);
		return (1);
	}
	if (ft_check_builtins_pipe(cmds) != 1)
	{
		ft_builtins(data, process);
		return (1);
	}
	data->valid_path = get_valid_path(data, cmds[0]);
	if (!data->valid_path && cmds[0][0] != '\0')
	{
		ft_no_valid_path(data, cmds);
		return (1);
	}
	if (execve(data->valid_path, cmds, data->env) == -1)
	{
		ft_free_not_execve(data);
		return (0);
	}
	return (1);
}

void	ft_dup_fd(t_data *data, int index)
{
	if (index != 0)
	{
		dup2(data->prev_pipes, STDIN_FILENO);
		close(data->prev_pipes);
	}
	if (index != data->nbcmds - 1)
		dup2(data->pipe_fd[1], STDOUT_FILENO);
}

void	ft_child_process(t_data *data, t_process process, char **cmds, int i)
{
	int	j;

	j = 0;
	while (j < data->nbcmds)
	{
		if (data->process[j].file_hd)
			free(data->process[j].file_hd);
		j++;
	}
	printf("%d, %d, %d\n", data->prev_pipes, data->pipe_fd[0], data->pipe_fd[1]);
	ft_dup_fd(data, i);
	ft_check_redirection(data, process, 1);
	close(data->pipe_fd[0]);
	close(data->pipe_fd[1]);
	if (ft_exec_multiple_cmds(data, process, cmds) == 1)
		ft_free_process_one_cmd(data);
	exit (g_exit_code);
}

void	ft_exec_all(t_data *data, t_process process, char **cmds, int index)
{
	if (pipe(data->pipe_fd) < 0)
		return ;
	data->pid[index] = fork();
	signal(SIGINT, ft_handle_signals_interactive);
	signal(SIGQUIT, ft_handle_signals_interactive);
	if (process.cmds[0])
		if (!ft_strncmp(process.cmds[0], "./", 2))
			ft_ignore_signals();
	if (data->pid[index] < 0)
		return ;
	if (data->pid[index] == 0)
		ft_child_process(data, process, cmds, index);
	else
	{
		if (data->prev_pipes != -1)
			close(data->prev_pipes);
		data->prev_pipes = data->pipe_fd[0];
		close(data->pipe_fd[1]);
	}
}
