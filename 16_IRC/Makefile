# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 11:38:41 by wnaseeve          #+#    #+#              #
#    Updated: 2023/10/25 11:55:16 by wnaseeve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	ircserv

SRCS	= 	srcs/main.cpp \
			srcs/User.cpp \
			init_server/Server.cpp \
			init_server/clients_actions.cpp \
			execute_commands/actions_commands.cpp \
			execute_commands/unknown.cpp \
			execute_commands/help.cpp \
			execute_commands/pass.cpp \
			execute_commands/nick.cpp \
			execute_commands/user.cpp \
			execute_commands/ping.cpp \
			execute_commands/oper.cpp \
			execute_commands/quit.cpp \
			execute_commands/privmsg.cpp \
			execute_commands/join.cpp \
			execute_commands/part.cpp \
			execute_commands/kick.cpp \
			execute_commands/topic.cpp \
			execute_commands/invite.cpp \
			parsing/parse_args.cpp \
			cleaning/clear_data.cpp \
			utils/print_functions.cpp \
			utils/welcome_msg.cpp \
			utils/int_to_string.cpp \
			utils/find_user_fd.cpp \

HEADER	=	includes/Server.hpp \
			includes/IRC.hpp \
			includes/Colors.hpp \
			includes/User.hpp \
			includes/messages.hpp \
			includes/Channel.hpp \

OBJS	= $(SRCS:src/%.cpp=obj/%.o)

CC		= c++

CFLAGS	= -std=c++98 -Wall -Wextra -Werror -g3

all:	obj $(NAME)

$(NAME): $(OBJS)
	@ $(CC) $(CFLAGS) -o $(NAME) $^

obj:
	@mkdir -p obj

obj/%.o:	src/%.cpp
	${CC} ${CFLAGS} -I. -c $< -o $@

valgrind:
	make && clear && valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all --track-fds=yes ./ircserv 8080 lol

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
