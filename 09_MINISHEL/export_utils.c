/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:28:15 by aaudevar          #+#    #+#             */
/*   Updated: 2023/03/16 11:42:19 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char	*ft_lvalue(t_data *data, char *arg)
{
	int		i;
	char	*temp;

	i = 0;
	while (arg[i] && arg[i] != '=')
		i++;
	temp = ft_calloc(i + 1, sizeof(char));
	if (!temp)
		ft_bad_malloc(data);
	i = 0;
	while (arg[i] && arg[i] != '=')
	{
		temp[i] = arg[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

int	ft_check_lvalue(t_data *data, char *arg)
{
	int		i;
	char	*temp;
	char	*temp2;

	i = 0;
	temp = ft_lvalue(data, arg);
	temp2 = ft_strjoin(temp, "=");
	if (!temp2)
	{
		free(temp);
		ft_bad_malloc(data);
	}
	free(temp);
	while (data->env[i])
	{
		if (ft_strncmp(temp2, data->env[i], ft_strlen(temp2)) == 0)
		{
			free(temp2);
			return (1);
		}
		i++;
	}
	free (temp2);
	return (0);
}

char	**replace_line(t_data *data, char **env, char *new)
{
	char	*temp;
	int		i;

	i = 0;
	temp = ft_lvalue(data, new);
	while (env[i])
	{
		if (ft_strncmp(temp, env[i], ft_strlen(temp)) == 0)
		{
			free(env[i]);
			env[i] = ft_strdup(new);
		}
		i++;
	}
	free(temp);
	return (env);
}
