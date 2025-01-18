NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address

YELLOW = \033[1;33m
GREEN = \033[1;32m
RESET = \033[0m

SRCS = sources/main.c sources/sorting.c sources/sorting_utils.c sources/utils.c sources/free.c	sources/error.c \
	sources/actions/actions.c sources/actions/push.c sources/actions/swap.c sources/actions/rotate.c sources/actions/reverse_rotate.c

LIBFT = libraries/libft/libft.a
FT_PRINTF = libraries/ft_printf/libftprintf.a

all: $(LIBFT) $(FT_PRINTF) $(NAME)

$(NAME): $(SRCS) $(LIBFT) $(FT_PRINTF)
	@echo "$(YELLOW)Compiling and Linking..$(RESET)"
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(FT_PRINTF) -o $(NAME)
	@echo "$(GREEN)Push_swap Executable Created!$(RESET)"

$(LIBFT):
	@echo "$(YELLOW)Building libft...$(RESET)"
	@make all bonus -s -C libraries/libft

$(FT_PRINTF):
	@echo "$(YELLOW)Building ft_printf...$(RESET)"
	@make all -s -C libraries/ft_printf

clean:
	@make clean -s -C libraries/libft
	@make clean -s -C libraries/ft_printf 

fclean: clean
	@rm -rf $(LIBFT) $(FT_PRINTF) $(NAME)

re: fclean all

.PHONY: all clean fclean re