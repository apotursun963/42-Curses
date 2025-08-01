NAME = cub3D
NAME_BONUS = cub3D_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -lm -lbsd -lmlx -lXext -lX11

LIBFT_PATH = libs/libft/
MLX_PATH = libs/mlx/
LIBFT = $(LIBFT_PATH)libft.a
MLX = $(MLX_PATH)libmlx.a

SRC = main.c mandatory/parse/read_file.c mandatory/parse/read_texture.c mandatory/render/render.c mandatory/parse/rgb.c mandatory/parse/check_map.c mandatory/free.c \
	mandatory/key_handle.c mandatory/movement.c mandatory/game_loop.c mandatory/parse/read_file_utils.c \
	mandatory/render/render_texture.c mandatory/parse/flood_fill.c mandatory/parse/read_file_line.c mandatory/render/render_utils.c

BONUS_SRC = bonus/key_handle_bonus.c bonus/door/door_bonus.c  bonus/door/door_render_bonus.c \
			bonus/minimap/minimap_bonus.c bonus/wall_collisions_bonus.c bonus/fps_counter.c \
			bonus/minimap/minimap_draw_bonus.c bonus/door/door_play_sprite_bonus.c \
			bonus/door/door_utils_bonus.c bonus/door/door_render_utils_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC:.c=_bonus.o)
OBJ_BONUS_FILE = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_PATH) -lft -L$(MLX_PATH) $(MLX_FLAGS) -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS) $(OBJ_BONUS_FILE) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -D BONUS=1 $(OBJ_BONUS) $(OBJ_BONUS_FILE) -L$(LIBFT_PATH) -lft -L$(MLX_PATH) $(MLX_FLAGS) -o $(NAME_BONUS)

$(MLX):
	@make -C $(MLX_PATH)

$(LIBFT):
	@make -C $(LIBFT_PATH)

bonus:  $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%_bonus.o: %.c
	$(CC) $(CFLAGS) -DBONUS=1 -c $< -o $@

clean:
	@make clean -C $(LIBFT_PATH)
	rm -rf $(OBJ)
	rm -rf $(OBJ_BONUS_FILE)
	rm -rf $(OBJ_BONUS)
	@make clean -C $(MLX_PATH)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)
	@make fclean -C $(LIBFT_PATH)

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re bonus
