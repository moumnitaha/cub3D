# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 13:47:28 by tmoumni           #+#    #+#              #
#    Updated: 2023/11/23 13:27:27 by tmoumni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BOLD = \033[1m
GREEN = \033[1;32m
RED = \033[1;31m
CYAN = \033[1;36m
END = \033[0m

NAME = cub3D_bonus
HEADER = cub3D_bonus.h

CC = cc
FLAGS = -Wall -Wextra -Werror
MFLAGS = -lmlx -framework OpenGL -framework AppKit

SRCS = cub3D_bn.c draw_rays_bn.c math_bn.c hzIntersection_bn.c init_ray_bn.c map_check_bn.c mlx_params_bn.c\
		init_player_bn.c key_press_bn.c mlx_draws_bn.c mouse_move_bn.c map_check_2_bn.c\
		vcIntersection_bn.c init_game_bn.c mlx_draws2_bn.c free_mem_bn.c\
    	utils_bn.c ../gnl/get_next_line.c ../gnl/get_next_line_utils.c utils/ft_1.c utils/ft_2.c \
		parse_bn.c u_parse_bn.c utils/ft_3.c u1_parse_bn.c set_textures_bn.c render_walls_bn.c
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
