/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:16:23 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/02/08 16:37:07 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include <stddef.h>
# include <fcntl.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	char	**cmds;
	char	**env;
	char	**av;
	int		ac;
	int		nbcmds;
	int		fd[2];
	int		input_fd;
	int		output_fd;
	pid_t	pid[4096];
	char	*path;
	int		pipes_count;
	int		here_doc_here;
	int		here_docfd;
	int		status;
	char	*limiter;
	int		prev_pipes;
	char	**arr;

}	t_pipex;

/* ***** Misc functions ******/
void	ft_unset_path(t_pipex *args);
int		ft_special_character(char *str);
char	*get_valid_path(t_pipex *args, char *cmd);
void	ft_args_in(t_pipex *args, char **argv, int argc);
int		ft_here_doc(t_pipex *args);

/* ***** Fork functions ******/
void	ft_exec(t_pipex *args, int i);
void	ft_fd_process(t_pipex *args, int i);
void	ft_child_process(t_pipex *args, int i);
void	ft_wait(t_pipex *args);
void	forking(t_pipex *args);

/* ***** Parsing functions ******/
void	get_infile(t_pipex *args);
void	get_outfile(t_pipex *args);
void	get_env(t_pipex *args, char *env[]);
void	ft_initialize(t_pipex *args, char *argv[], int argc);

/* ***** Utils functions ******/
void	free_function(t_pipex *args);
void	ft_error(void);
void	ft_error_input(t_pipex *args);
void	ft_error_output(t_pipex *args);

#endif
