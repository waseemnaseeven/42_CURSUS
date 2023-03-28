/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_0.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:08:25 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/03/20 17:21:58 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	ft_if_null_input(char *curr_path, t_data *data)
{
	char	*home_path;

	home_path = get_path(data->env, "HOME") + 5;
	if ((home_path -5) == NULL)
	{
		ft_putstr_fd("cd: HOME not set\n", 2);
		return (1);
	}
	if (chdir(home_path) == 0)
	{
		join_pwd("OLDPWD=", curr_path, data);
		getcwd(home_path, sizeof(home_path));
		join_pwd("PWD=", home_path, data);
		return (0);
	}
	return (0);
}

int	ft_exec_cd(char **input, t_data *data)
{
	int		exit;
	char	curr_path[4096];

	exit = 0;
	if (!getcwd(curr_path, sizeof(curr_path)))
		return (exit);
	if (input[0] == NULL)
	{
		exit = ft_if_null_input(curr_path, data);
		return (exit);
	}
	if (input[0][0] == '\0')
		return (exit);
	if (input[1])
	{
		ft_putstr_fd("bash: cd: ", 2);
		ft_putstr_fd("too many arguments\n", 2);
		return (exit = 1);
	}
	if (input[0][0] != '/')
		exit = ft_change_pwd(input[0], curr_path, data);
	else
		exit = ft_change_pwd(input[0], curr_path, data);
	return (exit);
}
