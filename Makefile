# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 13:47:28 by tmoumni           #+#    #+#              #
#    Updated: 2023/10/30 19:17:53 by tmoumni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BOLD = \033[1m
GREEN = \033[1;32m
RED = \033[1;31m
CYAN = \033[1;36m
END = \033[0m

NAME = cub3D
HEADER = cub3D.h

CC = cc
FLAGS = -Wall -Wextra -Werror #-g -fsanitize=address
MFLAGS = -lmlx -framework OpenGL -framework AppKit
I = -I/usr/include -Imlx_linux -O3
L = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

SRCS = cub3D.c draw_rays.c fixAngle.c hzIntersection.c initRay.c map_check.c map.c mlx_params.c\
		init_player.c key_press.c mlx_draws.c mouse_move.c render3DProjectedWalls.c vcIntersection.c\
		gnl/get_next_line.c gnl/get_next_line_utils.c
OBJS_DIR = OBJS_FILES

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
RM = rm -rf

# Key Codes for MacOS
ESC = KEY_ESC=53
W = KEY_W=13
A = KEY_A=0
S = KEY_S=1
D = KEY_D=2
UP = KEY_UP=126
DOWN = KEY_DOWN=125
LEFT = KEY_LEFT=123
RIGHT = KEY_RIGHT=124
R = KEY_R=15
Q = KEY_Q=12

SHELL = /bin/bash
UNAME = $(shell uname -s)
KEYCODES = -D $(ESC) -D $(Q) -D $(R) -D $(W) -D $(A) -D $(S) -D $(D) -D $(UP) -D $(DOWN) -D $(LEFT) -D $(RIGHT)
ifeq ($(UNAME), Linux)
	MFLAGS =  -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
	# Key Codes for Linux
	ESC = KEY_ESC=65307
	W = KEY_W=119
	A = KEY_A=97
	S = KEY_S=115
	D = KEY_D=100
	UP = KEY_UP=65362
	DOWN = KEY_DOWN=65364
	LEFT = KEY_LEFT=65361
	RIGHT = KEY_RIGHT=65363
	R = KEY_R=114
	Q = KEY_Q=113
	KEYCODES =  -D $(ESC) -D $(Q) -D $(R) -D $(W) -D $(A) -D $(S) -D $(D) -D $(UP) -D $(DOWN) -D $(LEFT) -D $(RIGHT)
endif


all: $(NAME)
	@printf "\n$(GREEN)[[ cub3D created successfully! ]]$(END)\n"

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) $(MFLAGS) -o $(NAME)

$(OBJS_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(@D)
	@$(CC) -c $(KEYCODES) $(FLAGS) $< -o $@
	@printf "$(CYAN)Compiling:$(END) $< ...\n"

clean:
	@$(RM) $(OBJS) $(OBJS_DIR)
	@printf "$(RED)$(BOLD)$(NAME) objects files removed.$(END)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(RED)$(BOLD)$(NAME) removed.$(END)\n"

re: fclean all