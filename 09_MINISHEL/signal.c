/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:04:18 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/03/21 18:36:30 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_handler(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

/*  Signal inside a child process*/
void	ft_handle_signals_interactive(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		signal(SIGINT, ft_handle_signals_interactive);
	}
	else if (sig == SIGQUIT)
	{
		printf("Quit\n");
		g_exit_code = 131;
	}
}

void	ft_hand_hd(int sig)
{
	if (sig == SIGINT)
	{
		g_exit_code = 130;
	}
}

void	ft_ignore_signals(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

int	ft_check_empty_pipe(t_process process)
{
	if (!process.cmds[0] && !process.infile[0]
		&& !process.outfile[0] && !process.delimiters[0])
		return (ft_syntax_exit("\'|\'"));
	return (g_exit_code);
}
