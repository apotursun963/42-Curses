NAME = minishell

SRCS = sources/main.c sources/free.c sources/parse.c

LIBFT = libs/libft/libft.a


all: $(NAME)

$(NAME): $(SRCS) $(LIBFT)
	@cc -Wall -Wextra -Werror $(SRCS) $(LIBFT) -o $(NAME) -lreadline

$(LIBFT):
	@make all -s -C libs/libft

clean:
	@rm -f $(NAME)

fclean: clean
	@rm -f $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re