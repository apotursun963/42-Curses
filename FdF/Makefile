NAME = fdf

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lm -lbsd -lmlx -lXext -lX11

LIBFT_PATH = ./libs/libft/
MLX_PATH = ./libs/mlx_linux/
LIBFT = $(LIBFT_PATH)libft.a
MLX = $(MLX_PATH)libmlx.a

SRC = srcs/core/main.c srcs/core/free.c srcs/graphics/color.c srcs/graphics/draw.c srcs/core/utils.c \
		srcs/core/init.c srcs/core/keyhandle.c srcs/graphics/projection.c srcs/core/read.c \
		srcs/transformation/rotate.c srcs/transformation/translate.c srcs/transformation/scale.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_PATH) -lft -L$(MLX_PATH) $(MLX_FLAGS) -o $(NAME)

$(MLX):
	@make -C $(MLX_PATH)

$(LIBFT):
	@make -C $(LIBFT_PATH)

clean:
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(MLX_PATH)
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re
