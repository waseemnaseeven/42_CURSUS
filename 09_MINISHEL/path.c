/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 12:21:02 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/03/18 16:45:24 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char	**get_cmds_path(t_data *data)
{
	char	*path;
	char	**strings;

	path = ft_get_variable(data->env, "PATH");
	strings = NULL;
	if (path)
	{
		strings = ft_split(path, ':');
		if (!strings)
			ft_bad_malloc(data);
	}
	return (strings);
}

char	*get_valid_path(t_data *data, char *cmd)
{
	char	*tmp;
	char	*valid_path;
	int		i;

	if (!cmd)
		return (NULL);
	if (!cmd[0])
		return (NULL);
	if (cmd[0] == '/' || (cmd[0] == '.' && cmd[1] == '/'))
		return (cmd);
	i = -1;
	if (data->path)
	{
		while (data->path[++i])
		{
			tmp = ft_strjoin(data->path[i], "/");
			valid_path = ft_strjoin(tmp, cmd);
			if (tmp)
				free(tmp);
			if (access(valid_path, 0) == 0)
				return (valid_path);
			free(valid_path);
		}
	}
	return (NULL);
}
