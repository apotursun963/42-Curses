NAME = libft.a

FUNCS = $(wildcard characters/*.c file_descriptor/*.c memory/*.c numbers/*.c strings/*.c)

BFUNCS = $(wildcard linked_list/*.c)

OBJECTS = $(FUNCS:.c=.o)
BONUS_OBJECTS = $(BFUNCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
REM = rm -vf
AR = ar -r

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

bonus: $(BONUS_OBJECTS)
	$(AR) $(NAME) $(BONUS_OBJECTS)

%.o: %.c
	$(CC) -c $(CFLAGS) $<

clean:
	$(REM) $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	$(REM) $(NAME)

re: fclean all bonus

.PHONY: all bonus clean fclean re
