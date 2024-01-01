# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 12:45:55 by amakhrou          #+#    #+#              #
#    Updated: 2024/01/01 15:45:43 by taelkhal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc

CFLAGS = -Wall -Wextra -Werror -I headers/ #-fsanitize=address -g3

SRCS = parse/ft_split.c parse/read.c main.c parse/utilis1.c parse/init.c parse/utilis.c parse/map_elements.c parse/check_map.c \
		parse/parse.c parse/rgb.c parse/get_next_line/get_next_line.c parse/get_next_line/get_next_line_utils.c \
		raycasting/get_coordinate.c raycasting/draw.c raycasting/castrays.c raycasting/init_structs.c \
		raycasting/mouse_moves.c raycasting/keys.c raycasting/moves.c raycasting/castrays2.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all