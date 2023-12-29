NAME = cub3D

CC = cc

CFLAGS = -fsanitize=address -g3#-Wall -Wextra -Werror

LIBMLX = minilibx-linux/libmlx.a -lXext -lX11 -lm -lbsd

SRCS = ft_putnbr.c ft_putstr.c ft_split.c ft_strcmp.c \
        get_next_line/get_next_line.c get_next_line/get_next_line_utils.c read_map.c init_structs.c \
		map_w_h.c draw.c castrays.c main.c


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