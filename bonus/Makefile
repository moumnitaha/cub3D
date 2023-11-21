# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 13:47:28 by tmoumni           #+#    #+#              #
#    Updated: 2023/11/21 13:40:09 by tmoumni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BOLD = \033[1m
GREEN = \033[1;32m
RED = \033[1;31m
CYAN = \033[1;36m
END = \033[0m

NAME = cub3D_bonus
HEADER = cub3D.h

CC = cc
FLAGS = -Wall -Wextra -Werror
MFLAGS = -lmlx -framework OpenGL -framework AppKit

SRCS = cub3D.c draw_rays.c math.c hzIntersection.c init_ray.c map_check.c mlx_params.c\
		init_player.c key_press.c mlx_draws.c mouse_move.c map_check_2.c\
		vcIntersection.c init_game.c mlx_draws2.c free_mem.c\
    	utils.c ../gnl/get_next_line.c ../gnl/get_next_line_utils.c utils/ft_1.c utils/ft_2.c \
		parse.c u_parse.c utils/ft_3.c u1_parse.c set_textures.c render_walls.c
OBJS_DIR = OBJS_FILES

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
RM = rm -rf

all: $(NAME)
	@printf "\n$(GREEN)[[ $(NAME) created successfully! ]]$(END)\n"

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) $(MFLAGS) -o $(NAME)

$(OBJS_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) -c $< -o $@
	@printf "$(CYAN)Compiling:$(END) $< ...\n"

clean:
	@$(RM) $(OBJS) $(OBJS_DIR) gnl
	@printf "$(RED)$(BOLD)$(NAME) objects files removed.$(END)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(RED)$(BOLD)$(NAME) removed.$(END)\n"

re: fclean all
