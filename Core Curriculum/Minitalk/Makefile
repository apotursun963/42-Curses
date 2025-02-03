NAME = minitalk

SERVER = server
CLIENT = client
CC = cc
CFLAGS = -Wall -Wextra -Werror
REM = rm -rf


all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): server.c
	$(CC) $(CFLAGS) server.c -o server

$(CLIENT): client.c
	$(CC) $(CFLAGS) client.c -o client

clean:
	$(REM) $(SERVER) $(CLIENT)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
