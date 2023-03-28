/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:40:08 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/03/16 11:43:45 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	ft_check_export_arg(char *str)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	if (str[i] != '_' && ft_isalpha(str[i]) == 0)
	{
		ft_putstr_fd("export: `", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("' : not a valid identifier\n", 2);
		return (1);
	}
	i++;
	while (str[i] && str[i] != '=')
	{
		if (str[i] != '_' && ft_isalnum(str[i]) == 0)
		{
			ft_putstr_fd("export: `", 2);
			ft_putstr_fd(str, 2);
			ft_putstr_fd("' : not a valid identifier\n", 2);
			return (1);
		}
		i++;
	}
	return (ret);
}

char	**add_line(char **env, char *new)
{
	int		i;
	char	**new_line;

	i = 0;
	while (env[i])
		i++;
	new_line = malloc(sizeof(char *) * (i + 2));
	if (!new_line)
		return (NULL);
	i = 0;
	while (env[i])
	{
		new_line[i] = ft_strdup(env[i]);
		i++;
	}
	new_line[i] = ft_strdup(new);
	i++;
	new_line[i] = NULL;
	ft_freetab(env, 1);
	return (new_line);
}

int	env_compare(t_data *data, char *arg)
{
	int		i;

	i = 0;
	while (data->env[i])
	{
		if (ft_strcmp(arg, data->env[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_export_arg(t_data *data, char *arg)
{
	if (env_compare(data, arg) != 0)
	{
		if (ft_strchr(arg, '=') != 0)
		{
			if (ft_check_lvalue(data, arg))
			{
				data->env = replace_line(data, data->env, arg);
				if (!data->env)
					ft_bad_malloc(data);
			}
			else
			{
				data->env = add_line(data->env, arg);
				if (!data->env)
					ft_bad_malloc(data);
			}
		}
	}
}

int	ft_export(t_data *data, char **arr)
{
	int		i;
	int		exit;

	i = 1;
	exit = 0;
	while (arr[i])
	{
		if (ft_check_export_arg(arr[i]) == 1)
			exit = 1;
		else
			ft_export_arg(data, arr[i]);
		i++;
	}
	return (exit);
}
