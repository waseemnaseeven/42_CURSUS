# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 11:38:41 by wnaseeve          #+#    #+#              #
#    Updated: 2023/09/01 15:20:26 by wnaseeve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	convert

SRCS	= 	src/main.cpp \
			src/ScalarConverter.cpp \



HEADER	=	includes/ScalarConverter.hpp \


OBJS	= $(SRCS:src/%.cpp=obj/%.o)

CC		= c++

CFLAGS	= -std=c++98 -Wall -Wextra -Werror

all:	obj $(NAME)

$(NAME): $(OBJS)
	@ $(CC) $(CFLAGS) -o $(NAME) $^

obj:
	@mkdir -p obj

obj/%.o:	src/%.cpp
	${CC} ${CFLAGS} -I. -c $< -o $@

valgrind:
	make && clear && valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(NAME)

clean:
	@printf "%b" "\t    $(_PURPLE)[Cleaning] $(_PURPLE)[all]$(_PINK_ORANGE)\n";
	rm -rf obj

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
