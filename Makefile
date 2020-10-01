# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bshang <bshangstudent.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/10 21:13:16 by bshang            #+#    #+#              #
#    Updated: 2020/07/21 13:49:28 by bshang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3D

FLAGS			=	-g -Wall -Werror -Wextra \
					-Lmlx/minilibx_mms -lmlx -framework OpenGL -framework AppKit \
					-Llibft -lft \
					-Imlx/minilibx_mms \
					-Iincludes \
					-Imlx/minilibx_mms \
					-Ilibft

HEADERS			=	./includes/cub_header.h \
					./mlx/minilibx_mms/mlx.h \
					./libft/libft.h \

SRC_M_DIR		=	./parser
SRC_P_DIR		=	./play

LIBFT_DIR		=	./libft
MLX_DIR			=	./mlx/minilibx_mms

SRC_MAP			:=	parser.c		error_proc.c \
					utils_parse.c	utils_parse_map.c	utils_set.c		utils_check.c \
					get_next_line.c	get_next_line_utils.c

SRC_PLAY		:=	proc_events.c	texturize.c			calc_dist_obstacle.c \
					utils_play.c	utils_init.c 		draw_utils.c \
					draw.c			draw_sprites.c		draw_sprites_utils.c \
					draw_plan.c

SRCS			:=	$(addprefix $(SRC_M_DIR)/, $(SRC_MAP)) \
					$(addprefix $(SRC_P_DIR)/, $(SRC_PLAY)) \
					play_short_version/main.c \
					play_short_version/proc_short_version.c

SRCS_BONUS		:=	$(addprefix $(SRC_M_DIR)/, $(SRC_MAP)) \
					$(addprefix $(SRC_P_DIR)/, $(SRC_PLAY)) \
					play_bonus/main_bonus.c \
					play_bonus/proc_bonus.c

SRCS_BONUS_C	:=	$(addprefix $(SRC_M_DIR)/, $(SRC_MAP)) \
					$(addprefix $(SRC_P_DIR)/, $(SRC_PLAY)) \
					play_bonus_c/main_bonus_c.c \
					play_bonus_c/proc_bonus_c.c

.PHONY: all clean fclean re run bonus cabaret

all: $(NAME)

$(NAME): $(SRCS) $(HEADERS)
	@echo $(SRCS)
	@cd $(LIBFT_DIR) && make bonus
	$(MAKE) -C mlx/minilibx_mms
	mv mlx/minilibx_mms/libmlx.dylib .
	@gcc $(FLAGS) -o $(NAME) $(SRCS) libmlx.dylib

bonus: re $(SRCS_BONUS) $(HEADERS)
	@echo $(SRCS_BONUS)
	@cd $(LIBFT_DIR) && make bonus
	$(MAKE) -C mlx/minilibx_mms
	mv mlx/minilibx_mms/libmlx.dylib .
	@gcc $(FLAGS) -o $(NAME) $(SRCS_BONUS) libmlx.dylib

cabaret: re $(SRCS_BONUS_C) $(HEADERS)
	@echo $(SRCS_BONUS_C)
	@cd $(LIBFT_DIR) && make bonus
	$(MAKE) -C mlx/minilibx_mms
	mv mlx/minilibx_mms/libmlx.dylib .
	@gcc $(FLAGS) -o $(NAME) $(SRCS_BONUS_C) libmlx.dylib

run: re
	./$(NAME)

clean:
	@cd $(LIBFT_DIR) && make fclean
	@cd $(MLX_DIR) && make clean

fclean: clean
	rm -rf $(NAME)
	rm -rf libmlx.dylib

re: fclean all
