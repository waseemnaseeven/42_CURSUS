/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 11:32:21 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/03/20 13:57:36 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_minus_n(char **arg)
{
	int	i;

	i = 1;
	while (arg[i] && arg[i][0] == '-' && arg[i][1] == 'n')
	{
		if (arg[i][1] != 'n')
			i++;
		i++;
	}
	if (!arg[i])
		return ;
	while (arg[i])
	{
		ft_putstr_fd(arg[i], 1);
		if (arg[i + 1] != NULL)
			write(1, " ", 1);
		i++;
	}
}

void	ft_echo(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		ft_putstr_fd(arg[i], 1);
		if (arg[i + 1] != NULL)
			write(1, " ", 1);
		i++;
	}
	ft_putstr_fd("\n", 1);
}

int	ft_check_minus_n(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-')
		i++;
	while (arg[i])
	{
		if (arg[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_exec_echo(char **arg)
{
	if (!arg[0])
	{
		printf("\n");
		return (0);
	}
	if (ft_check_minus_n(arg[0]) == 1)
		ft_minus_n(arg);
	else
		ft_echo(arg);
	return (0);
}
