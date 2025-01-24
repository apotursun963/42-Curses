NAME = libftprintf.a

SRC = ft_printf.c ft_type.c ft_hexa.c ft_nbr.c ft_chrs.c

OBJECTS = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
REM = rm -f
AR = ar -cr

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

clean:
	$(REM) $(OBJECTS)

fclean: clean
	$(REM) $(NAME)

re: fclean all

.PHONY: all clean fclean re