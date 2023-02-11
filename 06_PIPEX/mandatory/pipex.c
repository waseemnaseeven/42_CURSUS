/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:15:26 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/02/08 16:28:54 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

int	main(int argc, char *argv[], char *env[])
{
	t_pipex	*args;

	if (argc != 5)
		exit (0);
	if (!env[0])
		exit (0);
	args = ft_calloc(sizeof(t_pipex), 1);
	if (!args)
		exit (0);
	ft_initialize(args, argv, argc);
	get_env(args, env);
	if (pipe(args->fd) < 0)
		ft_error();
	get_fdin(args);
	get_fdout(args);
	forking(args);
	close(args->fd[1]);
	close(args->fd[0]);
	ft_wait(args);
	free_function(args);
}
