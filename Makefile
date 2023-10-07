NAME := so_long

CC := gcc

CFLAGS := -Wall -Wextra -Werror -g

SOURCE := game_logic/*.c
LIBFT := libft
PRINTF := printf/*.c
LIBRARY := -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MINILIBX := mlx_linux/

all:
	make -C $(LIBFT)
	make -C $(MINILIBX)
	$(CC) $(CFLAGS) $(SOURCE) $(PRINTF) $(LIBFT)/libft.a -L/$(LIBFT)  $(LIBRARY) -o $(NAME)

clean: fclean

fclean: clean
		make re -C $(MINILIBX)
		make clean -C $(LIBFT)
		rm -rf $(NAME)

re: fclean all
