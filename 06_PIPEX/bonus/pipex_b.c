/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:23:43 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/02/05 16:14:05 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex_bonus.h"

int	main(int argc, char *argv[], char *env[])
{
	t_pipex	*args;

	if (argc < 5)
		exit(1);
	if (!env[0])
		return (0);
	args = ft_calloc(sizeof(t_pipex), 1);
	if (!args)
		exit(0);
	ft_args_in(args, argv, argc);
	ft_initialize(args, argv, argc);
	get_env(args, env);
	forking(args);
	close(args->fd[0]);
	if (args->here_doc_here != -1)
		unlink("tmp.txt");
	free_function(args);
}
