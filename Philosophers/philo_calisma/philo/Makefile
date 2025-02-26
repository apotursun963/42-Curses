NAME = philo

SRCS = sources/main.c sources/simulation.c sources/utils.c

all: $(NAME)

$(NAME): $(SRCS)
	@cc -Wall -Wextra -Werror $(SRCS) -o $(NAME)

clean:
	@rm -f $(NAME)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re