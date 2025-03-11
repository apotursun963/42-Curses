NAME = minishell

SRCS = srcs/main.c srcs/env_to_lst.c sources/signals.c srcs/parse/parse1.c srcs/parse/parse2.c

LIBFT = libraries/libft/libft.a


all: $(NAME)

$(NAME): $(SRCS) $(LIBFT)
	@cc -Wall -Wextra -Werror $(SRCS) $(LIBFT) -o $(NAME) -lreadline

$(LIBFT):
	@make all -s -C libraries/libft

clean:
	@rm -f $(NAME)

fclean: clean
	@rm -f $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re