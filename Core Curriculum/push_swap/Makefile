NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra

YELLOW = \033[1;33m
GREEN = \033[1;32m
RESET = \033[0m

SRCS = sources/push_swap.c sources/sorting_algo.c sources/sorting_small.c sources/sorting_utils.c sources/utility_funcs.c sources/free_resources.c sources/error_management.c \
	sources/actions/perform_actions.c sources/actions/push.c sources/actions/swap.c sources/actions/rotate.c sources/actions/reverse_rotate.c
LIBFT = libraries/libft/libft.a
FT_PRINTF = libraries/printf/libftprintf.a

all: $(NAME)

$(NAME): $(SRCS) $(LIBFT) $(FT_PRINTF)
	@echo "$(YELLOW)Compiling and Linking..$(RESET)"
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(FT_PRINTF) -o $(NAME)
	@echo "$(GREEN)Push_swap Executable Created!$(RESET)"

$(LIBFT):
	@echo "$(YELLOW)Building libft...$(RESET)"
	@make all bonus -s -C libraries/libft

$(FT_PRINTF):
	@echo "$(YELLOW)Building printf...$(RESET)"
	@make all -s -C libraries/printf

clean:
	@make clean -s -C libraries/libft
	@make clean -s -C libraries/printf

fclean: clean
	@rm -f $(LIBFT) $(FT_PRINTF) $(NAME) $(CHECK)

re: fclean all

.PHONY: all clean fclean re