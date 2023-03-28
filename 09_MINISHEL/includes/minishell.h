/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:19:25 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/03/21 18:47:26 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stddef.h>
# include <fcntl.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <errno.h>
# include <readline/history.h>
# include <signal.h>
# include <limits.h>

extern int	g_exit_code;

typedef enum e_type
{
	REDIR_INPUT,
	REDIR_OUTPUT,
	REDIR_HEREDOC,
	REDIR_OUTPUT_APPEND,
	PIPE,
	FLAG,
	QUOTE,
	DOUBLE_QUOTE,
	COMMAND,
	VARIABLE,
	ARGUMENT,
	INFILE,
	OUTFILE,
	DELIMITER,
	OUTFILE_APPEND,
	NONE,
}			t_type;

typedef struct s_token
{
	char		*value;
	t_type		type;
}				t_token;

typedef struct s_list_tok
{
	t_token				*token;
	struct s_list_tok	*next;
	struct s_list_tok	*previous;
}				t_list_tok;

typedef struct s_process
{
	char	**cmds;
	char	**infile;
	char	**outfile;
	int		*flag_outfile;
	int		is_here_doc;
	char	**delimiters;
	int		fd_hd;
	char	*file_hd;
}				t_process;

typedef struct CommonData
{
	char		*input;
	char		**env;
	int			nbcmds;
	char		**path;
	char		*valid_path;
	char		**arr;
	int			return_code;
	int			pipe_fd[2];
	int			fd_infile;
	int			fd_outfile;
	int			saved_stdin;
	int			saved_stdout;
	int			here_docfd;
	int			index;
	int			prev_pipes;
	pid_t		pid[4096];
	t_list_tok	*lexer;
	t_process	*process;

}			t_data;

/* ********** MAIN FUNCTIONS ********** */
void		ft_start_loop(t_data *data);
void		ft_start_loop2(t_data *data);
void		ft_start_loop3(t_data *data);
void		ft_unlink(t_data *data);

/* ********** LEXER FUNCTIONS ********** */
void		ft_initialize(t_data *data);
void		ft_getenv(t_data *data, char *envp[]);

/* ********** PATH FUNCTIONS ********** */
char		**get_cmds_path(t_data *data);
char		*get_valid_path(t_data *data, char *cmd);

/* ********** BUILTINS FUNCTIONS ********** */
void		ft_builtins(t_data *data, t_process process);
// pwd
int			ft_pwd(char *arg);
// env
int			ft_env(t_data *data);
// exit
int			ft_exit(t_data *data, char **cmd);
int			ft_check_long_min(char *cmd);
// export
int			ft_export(t_data *data, char **arr);
int			ft_check_export_arg(char *str);
void		ft_export_arg(t_data *data, char *arg);
int			env_compare(t_data *data, char *arg);
char		**add_line(char **env, char *new);
char		**replace_line(t_data *data, char **env, char *new);
int			ft_check_lvalue(t_data *data, char *arg);
// cd
int			ft_exec_cd(char **input, t_data *data);
void		set_env(char **env, char *tmp, t_data *data);
void		join_pwd(char *pwd, char *curr_path, t_data *data);
int			ft_change_pwd(char *input, char *curr_path, t_data *data);
char		*get_path(char **env, char *path);
// unset
int			ft_unset(t_data *data, char **var);
char		**unset_remove(char **env, char *arg);
char		**ft_refill_env(char **env, char *line);
// echo
void		ft_minus_n(char **arg);
void		ft_echo(char **arg);
int			ft_exec_echo(char **arg);

/* ********** SIGNALS FUNCTIONS ********** */
void		ft_handler(int sig);
void		ft_ignore_signals(void);
void		ft_handle_signals_interactive(int sig);
void		ft_hand_hd(int sig);

/* ********** UTILS FUNCTIONS ********** */
void		print_tab(char *arg);
void		display(char **args);
void		print_lexer(t_list_tok *lexer);
void		display_files(char **args);
void		print_int_array(int *arr);

/* ********** FREE FUNCTIONS ********** */
void		ft_free_general_data(t_data *data);
void		ft_free_process(t_data *data);
void		ft_bad_malloc(t_data *data);
void		ft_free_array(char **array);
void		ft_free_process_one_cmd(t_data *data);
void		ft_free_not_execve(t_data *data);
void		ft_free_infinite_loop(t_data *data);

/* ********* LIST FUNCTIONS ********* */
t_list_tok	*ft_token_list_new(t_token *token);
void		ft_token_list_add_back(t_list_tok **lst, t_list_tok *new);
void		ft_lst_token_clear(t_list_tok **lst, void (*del)(t_token *token));
void		del(t_token *token);

/* ******** TOKEN FUNCTIONS ******** */
t_token		*ft_create_token(t_data *data);
int			is_sep(char c);
int			is_white_space(char c);
void		ft_token_copy_quote(t_data *data, char **temp, int *j, char c);
int			ft_is_quote(char c, char quote);
int			is_redirection(char c);

/* ******** CLEAN LEXER FUNCTIONS ******** */
t_list_tok	*ft_clean_quote(t_data *data, t_list_tok *lexer, char **env);
char		*ft_get_variable(char **env, char *var);
char		*ft_join_string(char *ret, char *s);
void		ft_clean_lexer(t_data *data);
char		*ft_remove_char(t_data *data, char *str, char c);

/* ******** LEXER UTILS FUNCTIONS ******** */
char		*rep_var_env(t_data *data, char *str, char **env);
int			ft_char_in_str(char *str, char c);
t_list_tok	*ft_white_space_in_variables(t_list_tok *lexer, t_data *data);

/* ******* LEXER_TYPE FUNCTIONS ******* */
t_type		get_type(t_list_tok *lexer);
t_list_tok	*ft_change_argument_type(t_data *data);
t_list_tok	*ft_change_redirection(t_data *data);

/* ******* LEXER_EXIT_CODE FUNCTIONS ******* */
char		*replace_exit_code(t_data *data, char *str);
void		ft_copy_split(char *str, int *i, char *split, int *k);

/* ******* LEXER_QUOTE FUNCTIONS ******* */
char		**spl_quote(t_data *data, char *str);
char		*unsplit(char **split);
int			ft_size_split(char *str);
char		*ft_make_word(t_data *data, char *str, char c);
char		**ft_clean_split(t_data *data, char **split);

/* ******* PARSING FUNCTIONS ******* */
void		ft_parsing(t_data	*data);
char		**ft_cmds_array(t_data *data, t_list_tok *lexer, int i);
int			ft_go_to_correct_pipe(t_list_tok **lexer, int i);
char		*ft_dup(t_data *data, const char *s);
char		**ft_infile_array(t_data *data, t_list_tok *lexer, int i);
char		**ft_outfile_array(t_data *data, t_list_tok *lexer, int i);
int			*ft_flag_array(t_data *data, t_list_tok *lexer, int i);
int			ft_count_here_doc(t_list_tok *lexer, int i);
char		**ft_delimiter_array(t_data *data, t_list_tok *lexer, int i);

/* ******* EXECUTION FUNCTIONS ******* */
void		ft_start_execution(t_data *data);
int			ft_exec(t_data *data, t_process process);
int			ft_exec_multiple_cmds(t_data *data, t_process process, char **cmds);
void		ft_exec_one(t_data *data);
void		ft_exec_one_cmd(t_data *data, t_process process);
void		ft_exec_all(t_data *data,
				t_process process, char **cmds, int index);
int			ft_check_builtins_pipe(char **arg);
int			ft_check_builtins(char **arg);
int			cmd_is_null_if(t_data *data, t_process process);
void		ft_wait(t_data *data);

/* ******* FD FUNCTIONS ******* */
int			ft_check_redirection(t_data *data, t_process process, int quit);
void		bad_fd_in_openfile(t_data *data, char *file, int quit);
void		restore_fd(int saved_stdin, int saved_stdout);
int			open_file(t_data *data, int flag, char *file, int quit);
void		rebuilt_stdin_stdout(t_data *data);
void		saving_stdin_stdout(t_data *data);

/* ******* HERE_DOC FUNCTIONS ******* */
char		*ft_tmp_hd(t_data *data, char *delimiter,
				int index, char *file);
void		ft_process_heredoc(t_data *data);
void		str_is_null_if(char *delimiter);

/* ******* ERROR FUNCTIONS ******* */
void		ft_perror(void);
void		ft_no_valid_path(t_data *data, char **cmds);

/* ******* SYNTAX FUNCTIONS ******* */
int			ft_syntax_error(t_data *data);
int			ft_check_empty_pipe(t_process process);
int			ft_syntax_exit(char *s);

#endif
