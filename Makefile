# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sizitout <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 14:41:35 by sizitout          #+#    #+#              #
#    Updated: 2024/02/21 07:41:46 by sizitout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	so_long.c\
				check_map.c \
				read_map.c \
				utils.c \
				check_parsing.c \
				base.c \
				check_walls.c \
				check_mlx.c \
				stock_mlx.c \
				move.c \
				move_one.c \
				pathfinding.c \
				

OBJS		= ${SRCS:.c=.o}
NAME		= so_long
CC			= cc -g3 -Wall -Wextra -Werror

INCLUDES = -I. -I/usr/include -Imlx -Ilibft

MLX_LIB = mlx/libmlx_Linux.a
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
LIBFT = libft/libft.a

all: ${NAME}

$(NAME): $(OBJS) $(MLX_LIB) $(LIBFT)
	$(CC) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(LIBFT)

$(MLX_LIB):
	make -C mlx

$(LIBFT):
	make -C libft

%.o: %.c so_long.h
	$(CC) -o $@ -c $< $(INCLUDES)

clean:
	rm -f ${OBJS}
	make -C mlx clean
	make -C libft clean

fclean:		clean
	rm -f ${NAME}
	make -C mlx clean
	make -C libft fclean

re:			fclean all

.PHONY:		all clean fclean re