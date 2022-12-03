# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 14:41:19 by wnaseeve          #+#    #+#              #
#    Updated: 2022/12/03 09:15:28 by wnaseeve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS    = ft_printf.c\
		  ft_printf_utils1.c\
	  	  ft_printf_utils2.c\

OBJS	= ${SRCS:.c=.o}

INCS	= ft_printf.h

LIB		= ar rcs

CC		= cc

CFLAGS	= -g3 -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
		@printf "%b" "[$(_STARLIGHT_BLUE)Compiling $(@)$(_PINK_ORANGE) $(@)$(_DEEP_BLUE)]\n";

all:	$(NAME)

$(NAME):	${OBJS} ${INCS}
		${LIB} ${NAME} ${OBJS}

clean:
		rm -f ${OBJS}
		@printf "%b" "\t    $(_YELLOW)[Cleaning $(_PURPLE)all$(_BOLD)]\n";

fclean:		clean
		rm  -f ${NAME}

re:		fclean 
		@make all

.PHONY:		all clean fclean re .c .o

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