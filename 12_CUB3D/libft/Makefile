# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 14:41:19 by wnaseeve          #+#    #+#              #
#    Updated: 2023/02/02 14:57:41 by wnaseeve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS    = ft_atoi.c\
	  ft_bzero.c\
	  ft_calloc.c\
	  ft_isalnum.c\
	  ft_isalpha.c\
	  ft_isascii.c\
	  ft_isdigit.c\
	  ft_isprint.c\
	  ft_strlen.c\
	  ft_itoa.c\
	  ft_memset.c\
	  ft_memcpy.c\
	  ft_memmove.c\
	  ft_strlcpy.c\
	  ft_strlcat.c\
	  ft_toupper.c\
	  ft_tolower.c\
	  ft_strchr.c\
	  ft_strrchr.c\
	  ft_strncmp.c\
	  ft_memchr.c\
	  ft_memcmp.c\
	  ft_strnstr.c\
	  ft_strdup.c\
	  ft_substr.c\
	  ft_strjoin.c\
	  ft_strtrim.c\
	  ft_split.c\
	  ft_strmapi.c\
	  ft_putchar_fd.c\
	  ft_putstr_fd.c\
	  ft_putendl_fd.c\
	  ft_putnbr_fd.c\
	  ft_striteri.c\
	  ft_printf_utils1.c\
	  ft_printf_utils2.c\
	  ft_printf.c\
	  get_next_line_utils.c\
	  get_next_line.c\
	  ft_swap.c\
	  ft_freetab.c\
	  ft_atol.c\
	  ft_checkargs.c\
	  ft_putchar.c\
	  ft_putstr.c\
	  ft_putnbr.c\
	  ft_strcpy.c\
	  ft_strcmp.c\


BNS		= ft_lstnew.c\
		  ft_lstadd_front.c\
		  ft_lstsize.c\
		  ft_lstlast.c\
		  ft_lstadd_back.c\
		  ft_lstdelone.c\
		  ft_lstclear.c\
		  ft_lstiter.c\
		  ft_lstmap.c\

OBJS	= ${SRCS:.c=.o}

OBJB	= ${BNS:.c=.o}

INCS	= libft.h

LIB	= ar rcs

CC	= cc

CFLAGS	= -g3 -Wall -Wextra -Werror

all:	$(NAME)

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS} ${OBJB} ${INCS}
		${LIB} ${NAME} ${OBJS} ${OBJB}

bonus:		${OBJS} ${OBJB} ${INCS}
		${LIB} ${NAME} ${OBJS} ${OBJB}

clean:
		rm -f ${OBJS} ${OBJB}

fclean:		clean
		rm  -f ${NAME}

re:		fclean
		@make all

.PHONY:		all clean fclean re .c .o bonus
