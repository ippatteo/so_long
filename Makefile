NAME := so_long

CC := gcc

CFLAGS := -Wall -Wextra -Werror -Iheaders/

SOURCE := game_logic/*.c
LIBFT := libft/*.c
PRINTF := printf/*.c
LIBRARY := -Lminilibx -lmlx -framework OpenGL -framework AppKit
MINILIBX := minilibx/

all:
	make -C $(MINILIBX)
	$(CC) $(CFLAGS) $(SOURCE) $(LIBFT) $(PRINTF) -o $(NAME)

clean:

fclean: clean
		make clean -C $(MINILIBX)
		rm -rf $(NAME)

re: fclean all
