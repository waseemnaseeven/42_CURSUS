/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_process1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:46:18 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/03/17 15:57:32 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	restore_fd(int saved_stdin, int saved_stdout)
{
	dup2(saved_stdin, 0);
	close(saved_stdin);
	dup2(saved_stdout, 1);
	close(saved_stdout);
}

void	bad_fd_in_openfile(t_data *data, char *file, int quit)
{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(file, 2);
	if (errno == 13)
	{
		restore_fd(data->saved_stdin, data->saved_stdout);
		ft_putstr_fd(": Permission denied\n", 2);
		g_exit_code = 1;
	}
	else if (access(file, F_OK) == 0)
	{
		restore_fd(data->saved_stdin, data->saved_stdout);
		ft_putstr_fd(": Is a directory\n", 2);
		g_exit_code = 1;
	}
	else if (access(file, F_OK) != 0)
	{
		ft_putstr_fd(": No such file or directory\n", 2);
		g_exit_code = 1;
	}
	if (quit == 0)
		exit (1);
}

int	open_file(t_data *data, int flag, char *file, int quit)
{
	int	fd;

	fd = 0;
	if (flag == 2)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (flag == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (flag == 3)
		fd = open(file, O_RDONLY, 0777);
	if (fd == -1)
		bad_fd_in_openfile(data, file, quit);
	return (fd);
}

void	saving_stdin_stdout(t_data *data)
{
	data->saved_stdin = dup(0);
	data->saved_stdout = dup(1);
	if (data->saved_stdin == -1 || data->saved_stdout == -1)
	{
		perror("dup");
		exit(1);
	}
}
