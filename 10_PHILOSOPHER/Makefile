# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 10:22:03 by wnaseeve          #+#    #+#              #
#    Updated: 2023/04/21 11:18:18 by wnaseeve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo

SRCS    	= philo.c\
			  philo_errors.c\
			  philo_utils.c\
			  philo_init.c\
			  philo_threads.c\
			  philo_free.c\
			  philo_time.c\
			  philo_dead.c\
			  philo_status.c\

OBJS		= ${SRCS:.c=.o}

HEADER		= philo.h

CC			= cc

CFLAGS		= -g3 -Wall -Wextra -Werror

#SANITIZER 	= -ggdb -fsanitize=thread -fno-omit-frame-pointer -O1

all:	$(NAME)

$(NAME): $(OBJS)
	@ printf "%b" "\t    $(_CYAN)[Cleaning] $(_CYAN)[all]$(_STARLIGHT_GREEN)\n";
	@ echo ""
	@ echo "\t\033[34;5mCompiling philosophers...\033[0m"
	@ echo ""
	@ $(CC) $(CFLAGS) $(OBJS) $(SANITIZER) -pthread -o philo

%.o: %.c $(HEADER)
		${CC} ${CFLAGS} -I. -c $< -o ${<:.c=.o}

valgrind:
	make && clear && valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all --track-fds=yes --suppressions=supp.supp

#valgrind complet : valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all --tool=helgrind --tool=drd ./philo

gdb:
	make && clear && gdb -tui ./philo

norminette:
	norminette *

clean:
	@printf "%b" "\t    $(_PURPLE)[Cleaning] $(_PURPLE)[all]$(_PINK_ORANGE)\n";
	rm -f $(OBJS)

fclean: clean
	@printf "%b" "\t    $(_ORANGE)[Cleaning] $(_ORANGE)[all]$(_RED)\n";
	rm -f $(NAME)

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
