/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:00:29 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/03/21 18:43:43 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	str_is_null_if(char *delimiter)
{
	ft_putstr_fd("-bash: warning: here-document at line", 2);
	ft_putstr_fd(" XX delimited by end-of-file (wanted `", 2);
	ft_putstr_fd(delimiter, 2);
	ft_putstr_fd("')\n", 2);
	g_exit_code = 0;
}

void	ft_here_doc_helper(t_data *data, char *limiter, char *delimiter)
{
	char	*str;

	str = NULL;
	while (1)
	{
		write(1, "> ", 2);
		signal(SIGINT, ft_hand_hd);
		str = get_next_line(0, 0);
		if (g_exit_code == 130)
			break ;
		if (!str)
		{
			str_is_null_if(delimiter);
			break ;
		}
		if (!ft_strcmp(str, limiter))
			break ;
		if (ft_char_in_str(str, '$'))
			str = rep_var_env(data, str, data->env);
		ft_putstr_fd(str, data->here_docfd);
		free(str);
	}
	free(str);
}

char	*ft_tmp_hd(t_data *data, char *delimiter, int index, char *file)
{
	char	*limiter;
	char	*temp;

	temp = ft_itoa(index);
	file = ft_strjoin(delimiter, temp);
	free(temp);
	limiter = ft_strjoin(delimiter, "\n");
	data->here_docfd = open(file, O_RDWR | O_CREAT, 0666);
	if (data->here_docfd < 0)
		return (NULL);
	ft_here_doc_helper(data, limiter, delimiter);
	free(limiter);
	get_next_line(0, 1);
	close(data->here_docfd);
	return (file);
}

int	ft_process_fdhd(t_data *data, t_process process, int index)
{
	int		fd;
	int		i;
	char	*file;

	i = 0;
	fd = 0;
	while (i < process.is_here_doc)
	{
		file = NULL;
		file = ft_tmp_hd(data, process.delimiters[i], index, file);
		if (i < process.is_here_doc - 1)
		{
			unlink(file);
			free(file);
			file = NULL;
		}
		i++;
	}
	fd = open_file(data, 3, file, 1);
	data->process[index].file_hd = ft_strdup(file);
	free (file);
	return (fd);
}

void	ft_process_heredoc(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbcmds)
	{
		if (data->process[i].is_here_doc == 0)
		{
			data->process[i].fd_hd = 0;
			data->process[i].file_hd = NULL;
		}
		else
			data->process[i].fd_hd = ft_process_fdhd(data, data->process[i], i);
		i++;
	}
}
