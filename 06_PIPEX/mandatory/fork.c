/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:24:48 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/02/08 16:25:43 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

int	ft_special_character(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if ((str[i] >= 'A' && str[i] <= 'Z')
			|| (str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= '0' && str[i] <= '9'))
			return (1);
	}
	return (0);
}

/*
	on redirige l'entrée du fd vers la sortie standard
	puis, on ferme la sortie du fd
*/

void	fork_one(t_pipex *args)
{
	char	**arr;

	dup2(args->fd[1], STDOUT_FILENO);
	close(args->fd[0]);
	close(args->fd[1]);
	arr = ft_split(args->cmds[0], ' ');
	if (arr[0] == NULL || ft_isdigit(arr[0][0]) == 1)
		write(2, "bash : command not found\n", 25);
	args->path = get_valid_path(args, arr[0]);
	if (!args->path)
	{
		close(args->fd[1]);
		ft_freetab(arr, 1);
		free_function(args);
		exit (1);
	}
	execve(args->path, arr, NULL);
}

/*
	on redirige sortie du fd vers l'entrée standard
	puis, on ferme l'entrée du fd
*/

void	fork_two(t_pipex *args)
{
	char	**arr;

	dup2(args->fd[0], STDIN_FILENO);
	close(args->fd[1]);
	close(args->fd[0]);
	arr = ft_split(args->cmds[1], ' ');
	if (arr[0] == NULL || ft_isdigit(arr[0][0]) == 1)
		write(2, "bash : command not found\n", 25);
	args->path = get_valid_path(args, arr[0]);
	if (!args->path)
	{
		close(args->fd[0]);
		ft_freetab(arr, 1);
		free_function(args);
		exit (1);
	}
	execve(args->path, arr, NULL);
}

void	ft_wait(t_pipex *args)
{
	int	i;

	waitpid(args->pid1, &i, 0);
	waitpid(args->pid2, &i, 0);
}

void	forking(t_pipex *args)
{
	args->pid1 = fork();
	if (args->pid1 == 0)
		fork_one(args);
	args->pid2 = fork();
	if (args->pid2 == 0)
		fork_two(args);
}
