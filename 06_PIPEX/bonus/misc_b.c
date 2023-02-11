/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:57:14 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/02/11 12:06:58 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex_bonus.h"

void	ft_unset_path(t_pipex *args)
{
	int	i;

	i = 0;
	while (i < args->ac - 1)
		i++;
	args->output_fd = open(args->av[i], O_CREAT | O_RDWR | O_TRUNC, 0666);
	free(args->cmds);
	free((void *)args);
	exit (1);
}

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

void	ft_args_in(t_pipex *args, char **argv, int argc)
{
	int	i;

	i = 0;
	args->here_doc_here = -1;
	while (++i < argc)
	{
		if (!ft_strcmp(argv[i], "here_doc"))
		{
			args->here_doc_here = 1;
			break ;
		}
	}
}

int	ft_here_doc(t_pipex *args)
{
	char	*str;

	args->here_docfd = open("tmp.txt", O_RDWR | O_CREAT, 0666);
	if (args->here_docfd < 0)
		ft_error_output(args);
	while (1)
	{
		write(1, "heredoc> ", 9);
		str = get_next_line(0, 0);
		if (!str || !ft_strcmp(str, args->limiter))
			break ;
		ft_putstr_fd(str, args->here_docfd);
		free(str);
	}
	free(str);
	get_next_line(0, 1);
	close(args->here_docfd);
	return (0);
}
