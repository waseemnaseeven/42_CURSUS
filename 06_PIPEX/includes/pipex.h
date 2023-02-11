/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:16:23 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/02/08 16:28:50 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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
	int		nbcmds;
	char	**env;
	char	**av;
	int		ac;
	int		fd[2];
	int		input_fd;
	int		output_fd;
	int		outfile_index;
	pid_t	pid1;
	pid_t	pid2;
	char	*path;

}	t_pipex;

/* ***** Fork functions ******/
int		ft_special_character(char *str);
void	fork_one(t_pipex *args);
void	fork_two(t_pipex *args);
void	ft_wait(t_pipex *args);
void	forking(t_pipex *args);

/* ***** Parsing functions ******/
void	get_fdin(t_pipex *args);
void	get_fdout(t_pipex *args);
char	*get_valid_path(t_pipex *args, char *cmd);
void	get_env(t_pipex *args, char *env[]);
void	ft_initialize(t_pipex *args, char *argv[], int argc);

/* ***** Utils functions ******/
void	ft_error(void);
void	free_function(t_pipex *args);
int		ft_special_character(char *str);
void	ft_error_input(t_pipex *args);
void	ft_error_output(t_pipex *args);
void	ft_unset_path(t_pipex *args);

#endif
