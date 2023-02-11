/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:16:31 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/02/08 16:32:59 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

void	ft_error_input(t_pipex *args)
{
	perror("Error");
	close(args->fd[0]);
	close(args->fd[1]);
	free_function(args);
	exit (1);
}

void	ft_error_output(t_pipex *args)
{
	perror("Error");
	close(args->fd[0]);
	close(args->fd[1]);
	free_function(args);
	exit (1);
}

void	ft_error(void)
{
	perror("Error");
	exit(1);
}

void	free_function(t_pipex *args)
{
	int	i;

	free(args->cmds);
	i = -1;
	while (args->env[++i])
		free(args->env[i]);
	free(args->env);
	free((void *)args);
}

void	ft_unset_path(t_pipex *args)
{
	int	i;

	i = 0;
	while (i < args->ac - 1)
		i++;
	args->output_fd = open(args->av[i], O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (args->output_fd < 0)
		ft_error_output(args);
	free(args->cmds);
	free((void *)args);
	exit (1);
}
