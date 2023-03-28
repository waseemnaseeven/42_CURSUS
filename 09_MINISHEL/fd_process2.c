/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_process2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:47:30 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/03/22 11:40:08 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_process_infile(t_data *data, t_process process, int quit, int index)
{
	while (process.infile[index])
	{
		if (process.infile[index + 1] != NULL)
			close(data->fd_infile);
		data->fd_infile = open_file(data, 3, process.infile[index], quit);
		index++;
	}
}

void	ft_process_outfile(t_data *data, t_process process, int quit, int index)
{
	while (process.outfile[index])
	{
		if (index > 0)
			close(data->fd_outfile);
		if (process.flag_outfile[index] == 2)
			data->fd_outfile = open_file(data, 2, process.outfile[index], quit);
		if (process.flag_outfile[index] == 1)
			data->fd_outfile = open_file(data, 1, process.outfile[index], quit);
		index++;
	}
}

void	ft_dup2_fdfile(int fd, int flag)
{
	if (dup2(fd, flag) == -1)
	{
		perror("dup2");
		exit(1);
	}
	close(fd);
}

void	ft_dup2_here_doc(int fd, int flag)
{
	if (dup2(fd, flag) == -1)
	{
		perror("dup2");
		exit(1);
	}
	close(fd);
}

int	ft_check_redirection(t_data *data, t_process process, int quit)
{
	int	i;

	i = 0;
	data->fd_infile = 0;
	data->fd_outfile = 0;
	if (process.infile[i] != NULL)
		ft_process_infile(data, process, quit, i);
	if (process.outfile[i] != NULL)
		ft_process_outfile(data, process, quit, i);
	if (data->fd_infile == -1 || data->fd_outfile == -1)
		return (1);
	if (data->fd_infile)
		ft_dup2_fdfile(data->fd_infile, STDIN_FILENO);
	if (data->fd_outfile)
		ft_dup2_fdfile(data->fd_outfile, STDOUT_FILENO);
	if (process.is_here_doc != 0)
		ft_dup2_here_doc(process.fd_hd, STDIN_FILENO);
	return (0);
}
