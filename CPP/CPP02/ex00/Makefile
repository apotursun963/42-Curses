# NAME = Fixed
# SRC = main.cpp Fixed.cpp

# all: $(NAME)

# $(NAME): $(SRC)
# 	c++ -Wall -Wextra -Werror -std=c++98 $(SRC) -o $(NAME)

# clean:
# 	@rm -f $(NAME)

# fclean:
# 	@rm -f $(NAME)

# re: fclean all

# .PHONY: all clean fclean re


NAME = Fixed
SRCS = main.cpp Fixed.cpp
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
    cc -Wall -Wextra -Werror $(OBJS) -o $(NAME)

%.o: %.c
    cc -Wall -Wextra -Werror -c $< -o $@

clean:
    rm -rf $(OBJS)

fclean: clean
    rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re