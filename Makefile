NAME = so_long

SRC =	src/animations/animations.c  src/animations/move_animation.c \
	src/draw_windows/draw_windows.c src/draw_windows/load_img.c \
	src/enemies/create_enemy.c src/enemies/enemies_moves.c \
	src/game/destroy_game.c src/game/init_game.c src/game/key_hook.c \
	src/map/check_walls.c src/map/create_map.c src/map/file_to_map.c src/map/map_counters.c src/map/map_size.c src/map/valid_map.c src/map/check_extension.c \
	src/lst/sl_lstadd_back.c \
	src/player/collect_exit.c src/player/exit.c src/player/move_directions.c src/player/move_player.c src/player/player_init.c \
	src/so_long.c
	
OBJ = $(SRC:.c=.o)

CC = cc
FLAGS = -Wall -Werror -Wextra
LIBFT_PATH = libft
INC_LIB = -L$(LIBFT_PATH) -lft
LBMLX_PATH = mlx_linux
INC_MLX = -L$(LBMLX_PATH) -lmlx

OS = $(shell uname)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -I$(LBMLX_PATH) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(INC_LIB) $(INC_MLX) -lXext -lX11 -lm -lz -o $(NAME)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
