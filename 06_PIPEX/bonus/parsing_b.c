/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:00:38 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/02/11 12:01:48 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex_bonus.h"

void	get_infile(t_pipex *args)
{
	args->input_fd = 0;
	if (args->here_doc_here == -1)
	{
		args->input_fd = open(args->av[1], O_RDONLY);
		if (args->input_fd < 0)
			ft_error_input(args);
		dup2(args->input_fd, STDIN_FILENO);
		close(args->input_fd);
	}
	else
	{
		args->input_fd = open("tmp.txt", O_RDONLY);
		if (args->input_fd < 0)
			ft_error_input(args);
		dup2(args->input_fd, STDIN_FILENO);
		close(args->input_fd);
	}
}

void	get_outfile(t_pipex *args)
{
	int	i;

	args->output_fd = 0;
	if (args->here_doc_here == -1)
	{
		i = 0;
		while (i < args->ac - 1)
			i++;
		args->output_fd = open(args->av[i], O_WRONLY | O_TRUNC | O_CREAT, 0666);
		if (args->output_fd < 0)
			ft_error_output(args);
		dup2(args->output_fd, STDOUT_FILENO);
		close(args->output_fd);
	}
	else
	{
		i = 0;
		while (i < args->ac - 1)
			i++;
		args->output_fd = open(args->av[i], O_RDWR | O_APPEND | O_CREAT, 0666);
		if (args->output_fd < 0)
			ft_error_output(args);
		dup2(args->output_fd, STDOUT_FILENO);
		close(args->output_fd);
	}
}

void	get_env(t_pipex *args, char *env[])
{
	int	i;

	i = -1;
	args->env = 0;
	while (env[++i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
		{
			args->env = ft_split(env[i], ':');
			if (!args->env)
			{
				free_function(args);
				ft_freetab(args->env, 1);
			}
		}
	}
	if (!args->env)
		ft_unset_path(args);
}

void	ft_malloc_cmds(t_pipex *args, char **argv, int argc)
{
	int	i;

	args->cmds = ft_calloc(sizeof(char *), argc - 2);
	if (!args->cmds)
		ft_freetab(args->cmds, 0);
	if (args->here_doc_here == 1)
	{
		i = -1;
		while (++i < args->nbcmds)
			args->cmds[i] = argv[i + 3];
	}
	else
	{
		i = -1;
		while (++i < args->nbcmds)
			args->cmds[i] = argv[i + 2];
	}
}

void	ft_initialize(t_pipex *args, char *argv[], int argc)
{
	int	i;

	args->av = argv;
	args->ac = argc;
	args->nbcmds = 0;
	args->here_docfd = -1;
	args->prev_pipes = -1;
	if (args->here_doc_here == 1)
	{
		i = 3;
		while (++i < argc)
			args->nbcmds++;
		args->limiter = ft_strjoin(argv[2], "\n");
		ft_here_doc(args);
		free(args->limiter);
	}
	else
	{
		i = 1;
		while (i++ < argc - 2)
			args->nbcmds++;
	}
	ft_malloc_cmds(args, argv, argc);
}
