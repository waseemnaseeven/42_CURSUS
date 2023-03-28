/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:20:16 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/03/22 11:24:35 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_start_execution(t_data *data)
{
	int	i;

	if (data->nbcmds == 1)
	{
		saving_stdin_stdout(data);
		ft_exec_one(data);
	}
	else if (data->nbcmds > 1)
	{
		data->prev_pipes = -1;
		i = -1;
		while (++i < data->nbcmds)
			ft_exec_all(data, data->process[i], data->process[i].cmds, i);
		close(data->pipe_fd[0]);
	}
	i = -1;
	while (++i < data->nbcmds)
	{
		if (data->process[i].is_here_doc != 0)
			close(data->process[i].fd_hd);
	}
}
