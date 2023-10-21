# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 13:47:28 by tmoumni           #+#    #+#              #
#    Updated: 2023/10/21 13:52:43 by tmoumni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
HEADER = cub3D.h

CC = cc
FLAGS = -Wall -Wextra -Werror

SRCS = cub3D.c
OBJS_DIR = OBJS_FILES
BUILTINS_OBJS_DIR = $(OBJS_DIR)/builtins

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
RM = rm -f

all: $(NAME)
	@echo "Compilation done"

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@echo "Objects deleted"

fclean: clean
	$(RM) $(NAME)
	@echo "Executable deleted"

re: fclean all