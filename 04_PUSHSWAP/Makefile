# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 17:15:09 by wnaseeve          #+#    #+#              #
#    Updated: 2023/01/02 18:46:35 by wnaseeve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

SRCS    = push_swap.c\
		  display.c\
		  calculprice.c\
		  utils.c\
		  parsing.c\
		  sort.c\
		  moves.c\
		  doublemoves.c\
		  maths.c\
		  median.c\
		  forthemoves.c

OBJS	= ${SRCS:.c=.o}

HEADER	= push_swap.h

INCLUDE = /libft/libft.a

CC		= cc

CFLAGS	= -g3 -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):
	@ cd libft && make -j libft.a && make clean
	@ echo "Compiling libft..."
	@ gcc $(CFLAGS) $(SRCS) libft/libft.a -o push_swap
	@ echo "Compiling push_swap..."
#	@ cp push_swap push_swap_visualizer
#	@ push_swap_visualizer/build/bin/visualizer

%.o: %.c libft/libft.a
	$(CC) $(CFLAGS) -o $(NAME) -c $< -I $(INCLUDE)

libft/libft.a:
	${MAKE} -C libft

clean:
	rm -f $(OBJ)
	${MAKE} -C libft clean
		@printf "%b" "\t    $(_YELLOW)[Cleaning $(_PURPLE)all$(_BOLD)]\n";

fclean: clean
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
