/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:46:11 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/02/14 16:21:24 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex_bonus.h"

void	ft_exec(t_pipex *args, int i)
{
	args->arr = ft_split(args->cmds[i], ' ');
	if (args->arr[0] == NULL || ft_isdigit(args->arr[0][0]) == 1)
		write(2, "bash : command not found\n", 25);
	args->path = get_valid_path(args, args->arr[0]);
	if (!args->path)
	{
		ft_freetab(args->arr, 1);
		free_function(args);
		exit (1);
	}
	execve(args->path, args->arr, args->env);
}

void	ft_fd_process(t_pipex *args, int i)
{
	if (i == 0)
		get_infile(args);
	else if (i == args->nbcmds - 1)
		get_outfile(args);
	if (i != 0)
	{
		dup2(args->prev_pipes, STDIN_FILENO);
		close(args->prev_pipes);
	}
	if (i != args->nbcmds - 1)
		dup2(args->fd[1], STDOUT_FILENO);
}

void	ft_wait(t_pipex *args)
{
	int	i;

	i = -1;
	while (++i < args->nbcmds)
		waitpid(args->pid[i], &args->status, 0);
}

void	ft_child_process(t_pipex *args, int i)
{
	ft_fd_process(args, i);
	close(args->fd[1]);
	close(args->fd[0]);
	ft_exec(args, i);
	free(args->path);
	exit (0);
}

void	forking(t_pipex *args)
{
	int	i;

	i = -1;
	while (++i < args->nbcmds)
	{
		if (pipe(args->fd) < 0)
			ft_error();
		args->pid[i] = fork();
		if (args->pid[i] < 0)
			ft_error();
		if (args->pid[i] == 0)
			ft_child_process(args, i);
		else
		{
			close(args->fd[1]);
			if (args->prev_pipes != -1)
				close(args->prev_pipes);
			args->prev_pipes = args->fd[0];
		}
	}
}
