/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:31:56 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/03/21 18:33:46 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_wait(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nbcmds)
	{
		if (waitpid(data->pid[i], &g_exit_code, 0) == -1)
			return ;
		if (WIFEXITED(g_exit_code))
			g_exit_code = WEXITSTATUS(g_exit_code);
		if (WIFSIGNALED(g_exit_code))
		{
			g_exit_code = WTERMSIG(g_exit_code);
			if (g_exit_code != 131)
				g_exit_code += 128;
			if (g_exit_code == 129)
				g_exit_code = 1;
		}
	}
}

void	ft_builtins(t_data *data, t_process process)
{
	if (!ft_strcmp(process.cmds[0], "env"))
		g_exit_code = ft_env(data);
	else if (!ft_strcmp(process.cmds[0], "pwd"))
		g_exit_code = ft_pwd(NULL);
	else if (!ft_strcmp(process.cmds[0], "exit"))
		g_exit_code = ft_exit(data, data->process[0].cmds + 1);
	else if (!ft_strcmp(process.cmds[0], "export"))
		g_exit_code = ft_export(data, data->process[0].cmds);
	else if (!ft_strcmp(process.cmds[0], "unset"))
		g_exit_code = ft_unset(data, data->process[0].cmds);
	else if (!ft_strcmp(process.cmds[0], "cd"))
		g_exit_code = ft_exec_cd(data->process[0].cmds + 1, data);
	else if (!ft_strcmp(process.cmds[0], "echo"))
		g_exit_code = ft_exec_echo(data->process[0].cmds + 1);
}

int	ft_check_builtins(char **arg)
{
	if (ft_strcmp(arg[0], "echo") == 0
		||ft_strcmp(arg[0], "cd") == 0
		||ft_strcmp(arg[0], "pwd") == 0
		||ft_strcmp(arg[0], "export") == 0
		||ft_strcmp(arg[0], "unset") == 0
		||ft_strcmp(arg[0], "env") == 0
		||ft_strcmp(arg[0], "exit") == 0)
		return (0);
	else
		return (1);
}

void	rebuilt_stdin_stdout(t_data *data)
{
	if (dup2(data->saved_stdin, STDIN_FILENO) == -1)
	{
		perror("dup2");
		exit(1);
	}
	close(data->saved_stdin);
	if (dup2(data->saved_stdout, STDOUT_FILENO) == -1)
	{
		perror("dup2");
		exit(1);
	}
	close(data->saved_stdout);
}
