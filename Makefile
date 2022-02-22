# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 12:04:48 by dbenkhar          #+#    #+#              #
#    Updated: 2022/02/22 16:57:55 by dbenkhar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= so_long

SRC=	main.c\
		check_map.c\
		store_map.c\
		sl_init.c\
		sl_loadtex.c\
		sl_buildmap.c\
		draw_utils.c

LIBDIR= ./libft
LIBFT= libft/libft.a
MLXDIR= ./minilibx
MLX= minilibx/libmlx.a

GNL= gnl/*.c

CC= gcc
FLAGS= -Wall -Werror -Wextra -g3

OS := $(shell uname)

CFLAGS_LINUX= $(FLAGS) $(MLX) -lXext -lX11 -lm -lz

CFLAGS_MACOS= $(FLAGS) $(MLX) -L/usr/X11/lib -lXext -lX11 -lm -lz

ifeq ($(OS), Darwin)
CFLAGS= $(CFLAGS_MACOS)
else
CFLAGS= $(CFLAGS_LINUX)
endif

all: $(NAME)

$(NAME):
	@make -C $(LIBDIR)
	@make -C $(MLXDIR)
	$(CC) $(SRC) $(GNL) $(LIBFT) $(CFLAGS) -o $(NAME)

test:
	@make -C $(LIBDIR)
	@make -C $(MLXDIR)
	$(CC) test.c init_types.c $(GNL) $(LIBFT) $(CFLAGS) -o test

clean:
	@make clean -C $(LIBDIR)

fclean:
	@make fclean -C $(LIBDIR)
	@make clean -C $(MLXDIR)
	@rm -rf *.dSYM
	@rm -f $(NAME)
	@rm -f test

re: fclean all

.PHONY: clean fclean
