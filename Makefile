# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/06 11:35:24 by toadzima          #+#    #+#              #
#    Updated: 2024/07/07 18:37:10 by fvastena         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#          ----------========== (     VARS     ) ==========----------

NAME		= cub3D
CFLAGS		= -Wall -Wextra -Werror -O3 -fsanitize=address -g
RMF			= rm -f
RMD			= rm -rf
HDDIR		= -Iinc/
LIB			= -Llibft -lft
LIB_INC		= -Ilibft

# MLX_MACOS_DIR = ./minilibx
# MLX_MACOS_FLAGS = -Lminilibx -lmlx -framework OpenGL -framework AppKit
# MLX_INC = -Iminilibx

# Linux VARS
MLX_LINUX_DIR = ./mlx_linux
MLX_LINUX_FLAGS = -Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz 
MLX_INC = -Imlx_linux

#          ----------========== (     SRCS     ) ==========----------

SRC_DIR = src/

SRC	=		apply_raycasting.c \
			events.c \
			free_all.c \
			free_utils.c \
			ft_errors.c \
			game.c \
			init_all.c \
			init_player.c \
			lib_adapted.c \
			main.c \
			moves.c \
			parsing_checker_utils.c \
			parsing_checker.c \
			parsing_textures.c \
			parsing_utils.c \
			parsing.c \
			raycasting.c \
			render.c \
			rotations.c \
			textures_file.c \
			textures_imgs.c \
			validate_move.c 

VPATH = $(shell find $(SRC_DIR) -type d)

#          ----------========== (     OBJS     ) ==========----------

OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

#           ----------========== (    RULES    ) ==========----------

all:		$(NAME)

# $(NAME): $(OBJ_DIR) $(OBJ)
# 	@$(MAKE) -j -C libft --no-print-directory
# 	@$(MAKE) -j -C minilibx --silent
# 	@$(CC) $(CFLAGS) $(OBJ) $(LIB) $(MLX_MACOS_FLAGS) -o $@
# 	@printf "\n$(GREEN)$(NAME) created!$(DEFAULT)\n"	

# $(OBJ_DIR)%.o:%.c
# 	@$(CC) $(CFLAGS) $(MLX_INC) $(HDDIR) $(LIB_INC) -c $< -o $@
# 	@printf "$(GREEN).$(DEFAULT)"

# Linux Compilation #
$(NAME): $(OBJ_DIR) $(OBJ)
	@$(MAKE) -j -C libft --no-print-directory
	@$(MAKE) -j -C mlx_linux --silent
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) $(MLX_LINUX_FLAGS) -o $@
	@printf "\n$(GREEN)$(NAME) created!$(DEFAULT)\n"	

$(OBJ_DIR)%.o:%.c
	@$(CC) $(CFLAGS) $(MLX_INC) $(HDDIR) $(LIB_INC) -c $< -o $@
	@printf "$(GREEN).$(DEFAULT)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
			@$(MAKE) -C libft clean --silent
			@$(RMD) $(OBJ_DIR)
			@printf "$(YELLOW)object files ($(NAME)) cleaned!$(DEFAULT)\n"

fclean:		clean
			@$(RMF) libft/libft.a
			@$(MAKE) -C mlx_linux clean --silent
			@$(RMD) $(NAME)
			@printf "$(RED)executable cleaned!$(DEFAULT)\n"


re:			fclean all

.PHONY:		all clean fclean re

#           ----------========== (    COLORS    ) ==========----------
RED = \033[1;31m
GREEN = \033[1;32m
GREEN_BG = \033[1;42m
YELLOW = \033[1;33m
DEFAULT = \033[0m