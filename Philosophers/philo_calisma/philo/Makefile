NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = src/main.c src/utils.c src/simulation.c

OBJS = $(SRCS:.c=.o)

all: $(OBJS) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re