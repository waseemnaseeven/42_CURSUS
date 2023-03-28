/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:47:32 by aaudevar          #+#    #+#             */
/*   Updated: 2023/03/21 18:31:04 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	ft_syntax_exit(char *s)
{
	ft_putstr_fd("bash: syntax error near unexpected token ", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("\n", 2);
	return (2);
}

int	ft_syntax_cmds(t_process process)
{
	int	i;

	i = 0;
	while (process.cmds[i])
	{
		if (!ft_strcmp(process.cmds[i], "|"))
			return (ft_syntax_exit("\'|\'"));
		if (!ft_strcmp(process.cmds[i], "<<")
			|| !ft_strcmp(process.cmds[i], "<")
			|| !ft_strcmp(process.cmds[i], ">")
			|| !ft_strcmp(process.cmds[i], ">>"))
			return (ft_syntax_exit("\'newline\'"));
		i++;
	}
	return (0);
}

int	ft_syntax_file(char **files)
{
	int	i;

	i = 0;
	while (files[i])
	{
		if (!ft_strncmp(files[i], "|", 1))
			return (ft_syntax_exit("\'|\'"));
		if (!ft_strncmp(files[i], "<<", 2))
			return (ft_syntax_exit("\'<<\'"));
		if (!ft_strncmp(files[i], ">>", 2))
			return (ft_syntax_exit("\'>>\'"));
		if (!ft_strncmp(files[i], ">", 1))
			return (ft_syntax_exit("\'>\'"));
		if (!ft_strncmp(files[i], "<", 1))
			return (ft_syntax_exit("\'<\'"));
		i++;
	}
	return (0);
}

int	ft_check_syntax(t_process process)
{
	int	ret;

	ret = ft_syntax_cmds(process);
	if (ret == 2)
		return (ret);
	ret = ft_syntax_file(process.infile);
	if (ret == 2)
		return (ret);
	ret = ft_syntax_file(process.outfile);
	if (ret == 2)
		return (ret);
	ret = ft_syntax_file(process.delimiters);
	return (ret);
}

int	ft_syntax_error(t_data *data)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (i < data->nbcmds)
	{
		ret = ft_check_syntax(data->process[i]);
		if (ret == 2)
			return (ret);
		i++;
	}
	i = 0;
	if (data->nbcmds > 1)
	{
		while (i < data->nbcmds)
		{
			ret = ft_check_empty_pipe(data->process[i]);
			if (ret == 2)
				return (ret);
			i++;
		}
	}
	return (ret);
}
