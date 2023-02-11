/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:46:44 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/02/08 16:23:23 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

void	get_fdin(t_pipex *args)
{
	args->input_fd = open(args->av[1], O_RDONLY);
	if (args->input_fd < 0)
		ft_error_input(args);
	dup2(args->input_fd, STDIN_FILENO);
	close(args->input_fd);
}

void	get_fdout(t_pipex *args)
{
	int	i;

	i = 0;
	while (i < args->ac - 1)
		i++;
	args->output_fd = open(args->av[i], O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (args->output_fd < 0)
		ft_error_output(args);
	dup2(args->output_fd, STDOUT_FILENO);
	close(args->output_fd);
}

char	*get_valid_path(t_pipex *args, char *cmd)
{
	char	*tmp;
	char	*valid_path;
	int		i;

	if (!cmd)
		return (NULL);
	if (ft_special_character(cmd) == 0)
		return (NULL);
	i = -1;
	while (args->env[++i])
	{
		tmp = ft_strjoin(args->env[i], "/");
		valid_path = ft_strjoin(tmp, cmd);
		if (tmp)
			free(tmp);
		if (access(valid_path, 0) == 0)
			return (valid_path);
		free(valid_path);
	}
	return (NULL);
}

void	get_env(t_pipex *args, char *env[])
{
	int	i;

	i = -1;
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

void	ft_initialize(t_pipex *args, char *argv[], int argc)
{
	int	i;

	args->av = argv;
	args->ac = argc;
	args->input_fd = 0;
	args->output_fd = 0;
	args->outfile_index = 0;
	args->nbcmds = 0;
	i = 1;
	while (i++ < argc - 2)
		args->nbcmds++;
	args->cmds = ft_calloc(sizeof(char *), argc - 2);
	if (!args->cmds)
		ft_freetab(args->cmds, 0);
	i = -1;
	while (++i < args->nbcmds)
		args->cmds[i] = argv[i + 2];
}
