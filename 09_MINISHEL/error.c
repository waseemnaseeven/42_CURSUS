/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:50:10 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/03/18 16:50:19 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_perror(void)
{
	perror("Error");
	printf("errno is %d\n", errno);
}

void	ft_no_valid_path(t_data *data, char **cmds)
{
	ft_putstr_fd(cmds[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	close(data->prev_pipes);
	restore_fd(data->saved_stdin, data->saved_stdout);
	g_exit_code = 127;
}
