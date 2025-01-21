NAME = push_swap
CHECK = my_checker		# burayı checker olarak değiştir PDF'te öyle diyor

CC = cc
CFLAGS = -Wall -Werror -Wextra

YELLOW = \033[1;33m
GREEN = \033[1;32m
RESET = \033[0m

SRCS = sources/push_swap.c sources/sorting_algo.c sources/sorting_small.c sources/sorting_utils.c sources/utility_funcs.c sources/free_resources.c sources/error_handling.c \
	sources/actions/perform_actions.c sources/actions/push.c sources/actions/swap.c sources/actions/rotate.c sources/actions/reverse_rotate.c

BSRCS = checker/checker.c checker/checker_utils.c checker/get_actions.c sources/utility_funcs.c sources/free_resources.c sources/error_handling.c \
	sources/actions/perform_actions.c sources/actions/push.c sources/actions/swap.c sources/actions/rotate.c sources/actions/reverse_rotate.c

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

bonus: $(LIBFT) $(FT_PRINTF) $(CHECK)

$(CHECK): $(LIBFT) $(FT_PRINTF) $(BSRCS) 
	@echo "$(YELLOW)Compiling and Linking..$(RESET)"
	@$(CC) $(CFLAGS) $(BSRCS) $(LIBFT) $(FT_PRINTF) -o $(CHECK)
	@echo "$(GREEN)checker Executable Created!$(RESET)"

clean:
	@make clean -s -C libraries/libft
	@make clean -s -C libraries/ft_printf

fclean: clean
	@rm -f $(LIBFT) $(FT_PRINTF) $(NAME) $(CHECK)

re: fclean all bonus

.PHONY: all bonus clean fclean re