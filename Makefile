# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 13:47:28 by tmoumni           #+#    #+#              #
#    Updated: 2023/10/25 13:36:47 by tmoumni          ###   ########.fr        #
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
FLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
MFLAGS = -lmlx -framework OpenGL -framework AppKit

SRCS = cub3D.c gnl/get_next_line.c gnl/get_next_line_utils.c
OBJS_DIR = OBJS_FILES

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
RM = rm -rf

all: $(NAME)
	@echo "\n$(GREEN)[[ cub3D created successfully! ]]$(END)\n"

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) $(MFLAGS) -o $(NAME)

$(OBJS_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "$(CYAN)Compiling:$(END)" $< "..."

clean:
	@$(RM) $(OBJS) $(OBJS_DIR)
	@echo "$(RED)$(BOLD)$(NAME) objects files removed.$(END)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)$(BOLD)$(NAME) removed.$(END)"

re: fclean all