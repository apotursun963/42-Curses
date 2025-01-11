NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

YELLOW = \033[1;33m
GREEN = \033[1;32m
RESET = \033[0m

SRCS = srcs/main.c srcs/sorting.c srcs/utils.c srcs/utils2.c \
	srcs/actions/push.c srcs/actions/swap.c srcs/actions/rotate.c srcs/actions/reverse_rotate.c

LIBFT = libs/lbft/libft.a
FT_PRINTF = libs/prnt/libftprintf.a

all: $(LIBFT) $(FT_PRINTF) $(NAME)

$(NAME): $(SRCS) $(LIBFT) $(FT_PRINTF)
	@echo "$(YELLOW)Linking...$(RESET)"
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(FT_PRINTF) -o $(NAME)
	@echo "$(GREEN)Build Successful!$(RESET)"

$(LIBFT):
	@echo "$(YELLOW)Building libft...$(RESET)"
	make all bonus -C libs/lbft
	@echo "$(GREEN)libft built Successful!$(RESET)"

$(FT_PRINTF):
	@echo "$(YELLOW)Building ft_printf...$(RESET)"
	make all -C libs/prnt
	@echo "$(GREEN)ft_printf built Successful!$(RESET)"

clean:
	make clean -C libs/lbft
	make clean -C libs/prnt 

fclean: clean
	rm -rf $(LIBFT) $(FT_PRINTF) $(NAME)

re: fclean all

.PHONY: all clean fclean re
