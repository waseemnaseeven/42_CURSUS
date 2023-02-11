/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:35:11 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/02/05 16:13:48 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex_bonus.h"

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
	close(args->prev_pipes);
	close(args->fd[1]);
	close(args->fd[0]);
	free_function(args);
	exit (1);
}
