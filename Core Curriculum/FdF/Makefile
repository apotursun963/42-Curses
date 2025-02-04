NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lm -lbsd -lmlx -lXext -lX11
INCLUDES = -I./include

LIBFT_PATH = ./libs/libft/
MLX_PATH = ./mlx_linux/
SRCDIR = ./srcs/
OBJDIR = objs/

SRC = main.c free.c color.c draw.c error.c init_utils.c \
	  init.c keybord.c menu.c project.c read.c \
	  rotate.c transform.c utils.c

OBJ = $(patsubst %.c, $(OBJDIR)/%.o, $(SRC))

LIBFT = $(LIBFT_PATH)libft.a
MLX = $(MLX_PATH)libmlx.a

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_PATH) -lft -L$(MLX_PATH) $(MLX_FLAGS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(MLX):
	@make -C $(MLX_PATH)

$(LIBFT):
	@make -C $(LIBFT_PATH)

clean:
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(MLX_PATH)
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all

install:
	sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev

.PHONY: clean fclean re all install
