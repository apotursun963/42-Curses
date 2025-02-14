NAME = philo

SRCS = sources/main.c sources/utils.c 

CC = cc
CFLAGS = -Wall -Wextra -Werror

$(NAME):
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean:
	@rm -rf $(NAME)

fclean:
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re