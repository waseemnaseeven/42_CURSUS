/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:56:40 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/03/20 11:51:39 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	free_exit(t_data *data)
{
	restore_fd(data->saved_stdin, data->saved_stdout);
	ft_lst_token_clear(&(data->lexer), del);
	ft_free_process(data);
	ft_free_general_data(data);
	return (g_exit_code);
}

long	long	ft_atoll(const char *nptr)
{
	long long		i;
	long long		res;
	long long		sign;

	i = 0;
	res = 0;
	sign = 1;
	if (!nptr)
		return (res);
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if ((nptr[i] == '-') || (nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}

void	ft_error_numeric(t_data *data, char *cmd)
{
	g_exit_code = 2;
	ft_putstr_fd("exit\n", 2);
	ft_putstr_fd("bash: exit: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(" numeric argument required\n", 2);
	exit(free_exit(data));
}

void	ft_only_numeric(t_data *data, char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		while (is_white_space(cmd[i]))
			i++;
		if (cmd[i] == '-' || cmd[i] == '+')
			i++;
		if (cmd[i] && (cmd[i] < '0' || cmd[i] > '9'))
			ft_error_numeric(data, cmd);
		i++;
	}
}

int	ft_exit(t_data *data, char **cmd)
{
	long long	ret;

	if (!cmd[0])
	{
		g_exit_code = 0;
		printf("exit\n");
		exit(free_exit(data));
	}
	ft_only_numeric(data, cmd[0]);
	if (cmd[0][0] == '-')
		if (ft_check_long_min(cmd[0] + 1))
			ft_error_numeric(data, cmd[0]);
	ret = ft_atoll(cmd[0]);
	if (ret > LONG_MAX)
		ft_error_numeric(data, cmd[0]);
	if (cmd[1])
	{
		ft_putstr_fd("exit\n", 2);
		ft_putstr_fd("bash: exit: too many arguments\n", 2);
		g_exit_code = 1;
		return (g_exit_code);
	}
	g_exit_code = ret;
	printf("exit\n");
	exit(free_exit(data));
}
