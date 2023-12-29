# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 12:45:55 by amakhrou          #+#    #+#              #
#    Updated: 2023/12/26 02:11:26 by taelkhal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc

CFLAGS = #-Wall -Wextra -Werror -fsanitize=address -g3 

LIBMLX = minilibx-linux/libmlx.a -lXext -lX11 -lm -lbsd

SRCS = ft_split.c read.c main.c utilis1.c init.c utilis.c map_elements.c check_map.c parse.c rgb.c \
        get_next_line/get_next_line.c get_next_line/get_next_line_utils.c ../raycasting/ft_putnbr.c ../raycasting/ft_putstr.c \
		../raycasting/ft_strcmp.c ../raycasting/map_w_h.c ../raycasting/draw.c ../raycasting/castrays.c ../raycasting/init_structs.c \
		../raycasting/mouse_moves.c
		


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBMLX)
	$(CC) $(CFLAGS) $(OBJS) ${LIBMLX} -o $(NAME)

$(LIBMLX):
	@make -C minilibx-linux

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all