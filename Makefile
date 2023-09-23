NAME := so_long

CC := gcc

CFLAGS := -Wall -Wextra -Werror -Iheaders/

SOURCE := game_logic/*.c
LIBFT := libft/*.c
PRINTF := printf/*.c
LIBRARY := -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MINILIBX := mlx_linux/

all:
	make -C $(MINILIBX)
	$(CC) $(CFLAGS) $(SOURCE) $(LIBFT) $(PRINTF) $(LIBRARY) -o $(NAME)

clean:

fclean: clean
		make clean -C $(MINILIBX)
		rm -rf $(NAME)

re: fclean all
