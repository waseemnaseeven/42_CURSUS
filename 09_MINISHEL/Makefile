# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/15 14:14:09 by wnaseeve          #+#    #+#              #
#    Updated: 2023/03/20 11:44:12 by aaudevar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell

SRCS    = minishell.c\
		  lexer.c\
		  free.c\
		  signal.c\
		  env.c\
		  pwd.c\
		  utils.c\
		  exit.c\
		  exit_utils.c\
		  export.c\
		  export_utils.c\
		  list.c\
		  token.c\
		  token_utils.c\
		  cd_0.c\
		  cd_1.c\
		  clean_lexer.c\
		  lexer_type.c\
		  lexer_utils.c\
		  lexer_exit_code.c\
		  lexer_variables.c\
		  lexer_quote.c\
		  lexer_quote_utils.c\
		  parsing.c\
		  unset.c\
		  parse_commands.c\
		  parse_infile.c\
		  parse_outfile.c\
		  parse_flag.c\
		  parse_here_doc.c\
		  echo.c\
		  path.c\
		  error.c\
		  syntax.c\
		  start_exec.c\
		  exec_1.c\
		  fd_process1.c\
		  here_doc.c\
		  exec_2.c\
		  fd_process2.c\
		  free2.c\
		  exec_pipe.c\

OBJS	= ${SRCS:.c=.o}

HEADER	= includes/minishell.h

INCLUDE = /libft/libft.a

CC		= cc

CFLAGS	= -g3 -Wall -Wextra -Werror

#SANITIZER 	= -ggdb -fsanitize=address -fno-omit-frame-pointer -O1

all:	$(NAME)

$(NAME): $(OBJS) libft/libft.a
	@ printf "%b" "\t    $(_CYAN)[Cleaning] $(_CYAN)[all]$(_STARLIGHT_GREEN)\n";
	@ echo ""
	@ echo "\t\033[34;5mCompiling libft && minishell...\033[0m"
	@ echo ""
	@ $(CC) $(CFLAGS) $(OBJS) libft/libft.a $(SANITIZER) -lreadline -o minishell

%.o: %.c $(HEADER)
		${CC} ${CFLAGS} -I. -c $< -o ${<:.c=.o}

%.o: %.c libft/libft.a
	$(CC) $(CFLAGS) -o $(NAME) -c $< -I $(INCLUDE)

libft/libft.a:
	${MAKE} -C libft

valgrind:
	make && clear && valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all --track-fds=yes --suppressions=supp.supp ./minishell

#valgrind complet : valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all --track-fds=yes --trace-children=yes --suppressions=supp.supp ./minishell

gdb:
	make && clear && gdb -tui ./minishell

norminette:
	norminette *

clean:
	@printf "%b" "\t    $(_PURPLE)[Cleaning] $(_PURPLE)[all]$(_PINK_ORANGE)\n";
	rm -f $(OBJS)
	${MAKE} -C libft clean

fclean: clean
	@printf "%b" "\t    $(_ORANGE)[Cleaning] $(_ORANGE)[all]$(_RED)\n";
	rm -f $(NAME)
	${MAKE} -C libft fclean

re:		fclean all

.PHONY:		all clean fclean re

# -------------- Syntaxing -------------- #

_NO                    =        \033[0m
_BOLD                =        \033[1m
_BLUE                =        \033[34m
_CYAN                =        \033[36m
_RED                =        \033[31m
_PURPLE             =        \033[35m
_PINK_ORANGE        =        \033[38;5;215m
_GREY                 =        \033[38;5;234m
_STARLIGHT_BLUE     =        \033[38;5;158m
_STARLIGHT_GREEN    =        \033[38;5;157m
_DEEP_BLUE            =        \033[38;5;69m
_YELLOW             =        \033[38;5;226m
_ORANGE                =         \033[38;5;209m\e[1m

# -------------- Syntaxing -------------- #
