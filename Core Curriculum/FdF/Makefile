NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lm -lbsd -lmlx -lXext -lX11
INCLUDES = -I./include

LIBFT_PATH = ./libs/libft/
MLX_PATH = ./libs/mlx_linux/
SRCDIR = ./srcs/

SRC = $(SRCDIR)main.c $(SRCDIR)/core/free.c $(SRCDIR)/graphics/color.c $(SRCDIR)/graphics/draw.c $(SRCDIR)/core/utils.c $(SRCDIR)/core/init.c \
		$(SRCDIR)/core/keyhandle.c $(SRCDIR)/graphics/projection.c $(SRCDIR)/io/read.c \
		$(SRCDIR)/transformation/rotate.c $(SRCDIR)/transformation/translate.c $(SRCDIR)/transformation/scale.c

OBJ = $(SRC:.c=.o)

LIBFT = $(LIBFT_PATH)libft.a
MLX = $(MLX_PATH)libmlx.a

RM = rm -rf

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
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re