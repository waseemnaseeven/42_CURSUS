# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 19:04:49 by aaudevar          #+#    #+#              #
#    Updated: 2022/11/20 19:04:49 by aaudevar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC			=	-I ./includes -I ./libft -I ./mlx

LIB			=	-L ./libft -lft -L ./mlx -lmlx -lXext -lX11 -lm -lbsd

SRC			= 	src/check_element.c \
				src/check_texture.c \
				src/free.c \
				src/main.c \
				src/parse_map.c \
				src/parse_map_utils.c \
				src/parse_element.c \
				src/utils.c \
				src/init_window.c\
				src/render_map.c\
				src/render_map_2.c\
				src/render_map_utils.c\
				src/render_map_utils_2.c\
				src/hooks.c\
				src/hooks_utils.c\
				src/hooks_utils2.c\
				src/parsing.c \

MLX			=	mlx/Makefile.gen

BONUS		= 	bonus/check_element_bonus.c \
				bonus/check_texture_bonus.c \
				bonus/free_bonus.c \
				bonus/main_bonus.c \
				bonus/parse_map_bonus.c \
				bonus/parse_map_utils_bonus.c \
				bonus/parse_element_bonus.c \
				bonus/utils_bonus.c \
				bonus/init_window_bonus.c\
				bonus/render_map_bonus.c\
				bonus/render_map_2_bonus.c\
				bonus/render_map_utils_bonus.c\
				bonus/render_map_utils_2_bonus.c\
				bonus/hooks_bonus.c\
				bonus/hooks_utils_bonus.c\
				bonus/hooks_utils2_bonus.c\
				bonus/parsing_bonus.c \
				bonus/minimap_bonus.c \
				bonus/parse_bots_bonus.c \
				#bonus/render_sprites_bonus.c \

OBJ			=	$(patsubst src%, obj%, $(SRC:.c=.o))

OBJ_BONUS	=	$(patsubst bonus%, obj_bonus%, $(BONUS:.c=.o))

NAME = cub3D
BONUS_NAME = cub3D_bonus
LFT = libft/libft.a
CC = cc
RM = rm -f
CFLAGS = -g3 -Wall -Wextra -Werror

SANITIZER 	= -ggdb -fsanitize=address -fno-omit-frame-pointer -O1

all: $(MLX) $(LFT) obj $(NAME)

${NAME}: ${OBJ}
	$(CC) $(CFLAGS) -lm -o $@ $^ $(LIB)

bonus: $(MLX) $(LFT) obj_bonus ${BONUS_NAME}

${BONUS_NAME}: ${OBJ_BONUS}
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

$(MLX):
			@echo " [ .. ] | Compiling minilibx.."
			@make -s -C mlx
			@echo " [ OK ] | Minilibx ready!"

$(LFT):
			@echo " [ .. ] | Compiling libft.."
			@make -s -C libft
			@echo " [ OK ] | Libft ready!"

obj:
	@mkdir -p obj

obj_bonus:
	@mkdir -p obj_bonus

obj/%.o:	src/%.c
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

obj_bonus/%.o:	bonus/%.c
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

valgrind:
	make && clear && valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./cub3D maps/map.cub

gdb:
	make bonus && clear && gdb -tui --args ./cub3D_bonus maps/starwars.cub

jedi:
	make bonus && clear && ./cub3D_bonus maps/starwars.cub

norminette:
	norminette src bonus

clean:
			@make -s $@ -C libft
			@rm -rf $(OBJ) $(OBJ_BONUS) obj obj_bonus
			@echo "object files removed."

fclean:		clean
			@make -s $@ -C libft
			@rm -rf $(NAME) cub3D_bonus
			@echo "binary file removed."

re : fclean all

.PHONY : all clean fclean re
