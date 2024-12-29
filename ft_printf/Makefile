NAME = libftprintf.a

SRC = $(addprefix src/, ft_printf.c ft_type.c ft_hexa.c ft_nbr.c ft_chrs.c)

OBJECTS = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
REM = rm -vf
AR = ar -r

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

clean:
	$(REM) $(OBJECTS)

fclean: clean
	$(REM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
