NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCS = sources/main.c sources/simulation.c sources/timing.c sources/utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re