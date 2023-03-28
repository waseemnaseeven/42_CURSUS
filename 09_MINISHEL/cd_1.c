/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:29:10 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/03/20 16:56:57 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	set_env(char **env, char *tmp, t_data *data)
{
	int		i;
	char	**arg;

	i = 0;
	arg = NULL;
	arg = ft_split(tmp, '=');
	i = env_compare(data, arg[i]);
	if (env[i] == NULL)
	{
		data->env = add_line(env, tmp);
		ft_freetab(arg, 1);
		return ;
	}
	free(env[i]);
	tmp = ft_strdup(tmp);
	env[i] = tmp;
	ft_freetab(arg, 1);
}

void	join_pwd(char *pwd, char *curr_path, t_data *data)
{
	char	*tmp;

	tmp = ft_strjoin(pwd, curr_path);
	set_env(data->env, tmp, data);
	free(tmp);
}

char	*get_path(char **env, char *path)
{
	int		i;
	char	**path_send;

	i = 0;
	while (env[i])
	{
		path_send = ft_split(env[i], '=');
		if (ft_strcmp(path_send[0], path) == 0)
		{
			ft_freetab(path_send, 1);
			break ;
		}
		else
			i++;
		ft_freetab(path_send, 1);
	}
	if (env[i] == NULL)
		return (NULL);
	return (env[i]);
}

int	ft_change_pwd(char *input, char *curr_path, t_data *data)
{
	if (chdir(input) == 0)
	{
		join_pwd("OLDPWD=", curr_path, data);
		getcwd(curr_path, sizeof(curr_path));
		join_pwd("PWD=", curr_path, data);
		return (0);
	}
	else
	{
		ft_putstr_fd("bash: cd: ", 2);
		ft_putstr_fd(input, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return (1);
	}
}
