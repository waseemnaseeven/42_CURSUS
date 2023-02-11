# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/15 14:14:09 by wnaseeve          #+#    #+#              #
#    Updated: 2023/02/11 12:13:43 by wnaseeve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

SRCS    = mandatory/pipex.c\
		  mandatory/utils.c\
		  mandatory/parsing.c\
		  mandatory/fork.c\

SRCS_BONUS    = bonus/pipex_b.c\
				bonus/utils_b.c\
				bonus/parsing_b.c\
				bonus/misc_b.c\
				bonus/fork_b.c\

OBJS	= ${SRCS:.c=.o}

OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

HEADER	= includes/pipex.h

HEADER_BONUS	= includes/pipex_bonus.h

INCLUDE = /libft/libft.a

CC		= cc

CFLAGS	= -g3 -Wall -Wextra -Werror

#SANITIZER 	= -ggdb -fsanitize=address -fno-omit-frame-pointer

all:	$(NAME)

$(NAME): $(OBJS) libft/libft.a
	@ printf "%b" "\t    $(_CYAN)[Cleaning] $(_CYAN)[all]$(_STARLIGHT_GREEN)\n";
	@ echo ""
	@ echo "\t\033[34;5mCompiling libft && pipex...\033[0m"
	@ echo ""
	@ $(CC) $(CFLAGS) $(OBJS) libft/libft.a $(SANITIZER) -o pipex

%.o: %.c $(HEADER) $(HEADER_BONUS)
		${CC} ${CFLAGS} -I. -c $< -o ${<:.c=.o}

%.o: %.c libft/libft.a
	$(CC) $(CFLAGS) -o $(NAME) -c $< -I $(INCLUDE)

bonus:	$(OBJS_BONUS) libft/libft.a
	@ printf "%b" "\t    $(_CYAN)[Cleaning] $(_CYAN)[all]$(_STARLIGHT_GREEN)\n";
	@ echo ""
	@ echo "\t\033[34;5mCompiling libft && pipex_bonus...\033[0m"
	@ echo ""
	@ $(CC) $(CFLAGS) $(OBJS_BONUS) libft/libft.a $(SANITIZER) -o pipex_b

libft/libft.a:
	${MAKE} -C libft

valgrind:
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all --track-fds=yes

norminette:
	norminette *

clean:
	@printf "%b" "\t    $(_PURPLE)[Cleaning] $(_PURPLE)[all]$(_PINK_ORANGE)\n";
	rm -f $(OBJS) $(OBJS_BONUS)
	${MAKE} -C libft clean

fclean: clean
	@printf "%b" "\t    $(_ORANGE)[Cleaning] $(_ORANGE)[all]$(_RED)\n";
	rm -f $(NAME) pipex_b
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
