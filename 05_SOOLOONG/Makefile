# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 17:15:09 by wnaseeve          #+#    #+#              #
#    Updated: 2023/01/20 17:49:29 by wnaseeve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRCS    = so_long.c\
		  srcs/utils.c\
		  srcs/utils2.c\
		  srcs/info_map.c\
		  srcs/parsing_map.c\
		  srcs/parsing_map.utils.c\
		  srcs/parsing_map.utils2.c\
		  srcs/pathfinding.c\
		  srcs/pathfinding_utils.c\
		  srcs/creating_map.c\
		  srcs/render_map.c\
		  srcs/render_map_utils.c\
		  srcs/hooks.c\
		  srcs/player.c\
		  srcs/player_utils.c\


OBJS	= ${SRCS:.c=.o}

HEADER	= so_long.h

INCLUDE = /libft/libft.a

CC		= cc

CFLAGS	= -g3 -Wall -Wextra -Werror

MLX		= -I . -Lmlx_linux -lmlx -lXext -lX11

#SANITIZER 	= -ggdb -fsanitize=address -fno-omit-frame-pointer

all:	$(NAME)

$(NAME): $(OBJS) libft/libft.a mlx_linux/libmlx.a
	@ printf "%b" "\t    $(_CYAN)[Cleaning] $(_CYAN)[all]$(_STARLIGHT_GREEN)\n";
#	@ cd libft && make -j libft.a && make clean
#	@ cd mlx_linux && make
	@ echo ""
	@ echo "\t\033[34;5mCompiling libft && so_long...\033[0m"
	@ echo ""
	@ $(CC) $(CFLAGS) $(OBJS) libft/libft.a $(MLX) -o so_long
#	@ && ./so_long map.ber

%.o: %.c $(HEADER)
		${CC} ${CFLAGS} -I. -c $< -o ${<:.c=.o}

%.o: %.c libft/libft.a
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INCLUDE)

libft/libft.a:
	${MAKE} -C libft

mlx_linux/libmlx.a:
	$(MAKE) -C mlx_linux

clean:
	@printf "%b" "\t    $(_PURPLE)[Cleaning] $(_PURPLE)[all]$(_PINK_ORANGE)\n";
	rm -f $(OBJS)
	${MAKE} -C libft clean
	$(MAKE) -C mlx_linux clean

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
