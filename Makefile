# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/19 01:55:57 by nivicius          #+#    #+#              #
#    Updated: 2024/08/19 01:56:00 by nivicius         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#******************************************************************************#
#                                 CONFIGURATION                                #
#******************************************************************************#

NAME = fractol

LIBFT = lib/libft/libft.a

SHELL := /bin/bash
COUNT := 0

BLACK        = \033[0;30m
RED          = \033[0;31m
GREEN        = \033[0;32m
YELLOW       = \033[0;33m
BLUE         = \033[0;34m
MAGENTA      = \033[0;35m
CYAN         = \033[0;36m
WHITE        = \033[0;37m
RESET        = \033[0m

MFLAGS = -ldl -lglfw -pthread -lm -g3
CFLAGS = -Wall -Wextra -Werror -g3

#******************************************************************************#
#                                   FILES                                      #
#******************************************************************************#
SRC_DIR = src/
OBJ_DIR = obj/

CFILES = $(SRC_DIR)main.c \
         $(SRC_DIR)validations/avac.c

OBJ = $(CFILES:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

INCLUDES = -I./ -I./lib/libft -I.lib/MLX42/include/MLX42
LINCLUDES = -L./lib/libft -lft
MLX = MLX42/build/libmlx42.a
       
all : $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "$(GREEN)Compiling $< into $@\n$(RESET)"

$(MLX): 
	@cd MLX42 && cmake -B build -DDEBUG=1
	@cd MLX42 && cmake --build build -j4

$(NAME): $(MLX) $(OBJ)
	@$(MAKE) -sC ./lib/libft
	@$(CC) $(OBJ) $(INCLUDES) $(LIBFT) $(MLX) $(LINCLUDES) $(CFLAGS) $(MFLAGS) -o $(NAME)
	@printf "\n$(MAGENTA)Fractol compiled\n$(RESET)"

clean :
	@make clean -sC lib/libft/
	@rm -rf lib/MLX42/build
	@rm -rf $(OBJ_DIR)
	@printf "$(RED)Deleted objects$(RESET)\n"

fclean : clean
	@make clean -sC lib/libft/
	@rm -rf $(NAME)
	@printf "$(RED)Libft is deleted$(RESET)\n"

re : fclean all

.PHONY: clean fclean re all bonus
