/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:17:31 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/03/22 11:08:49 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	g_exit_code = 0;

void	ft_start_loop3(t_data *data)
{
	ft_process_heredoc(data);
	ft_start_execution(data);
	ft_wait(data);
	ft_unlink(data);
}

void	ft_start_loop2(t_data *data)
{
	ft_initialize(data);
	ft_parsing(data);
	add_history(data->input);
}

void	ft_unlink(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbcmds)
	{
		if (data->process[i].is_here_doc)
		{
			close(data->process[i].fd_hd);
			unlink(data->process[i].file_hd);
			free(data->process[i].file_hd);
			data->process[i].file_hd = NULL;
		}
		i++;
	}
}

void	ft_start_loop(t_data *data)
{
	int	ret;

	ret = 0;
	while (1)
	{
		signal(SIGINT, ft_handler);
		signal(SIGQUIT, SIG_IGN);
		data->path = get_cmds_path(data);
		data->input = readline("minishell> ");
		if (!data->input)
		{
			ft_free_general_data(data);
			exit (g_exit_code);
		}
		ft_start_loop2(data);
		ret = ft_syntax_error(data);
		if (ret != 2)
			ft_start_loop3(data);
		else
			g_exit_code = ret;
		ft_free_infinite_loop(data);
	}
}

int	main(int ac, char *av[], char *envp[])
{
	t_data	data;

	if (ac != 1 || av[1])
	{
		printf("Error\nPlease, write ./minishell");
		return (0);
	}
	if (!envp || !envp[0])
	{
		ft_putstr_fd("Why do you want to go into a minishell ?", 2);
		ft_putstr_fd("that doesnt have PATH? Huh? Fuck YOU", 2);
		return (0);
	}
	ft_memset(&data, 0, sizeof(t_data));
	ft_getenv(&data, envp);
	ft_start_loop(&data);
}
