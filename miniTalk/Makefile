NAME = minitalk

SERVER = srcs/server
CLIENT = srcs/client
CC = cc
CFLAGS = -Wall -Wextra -Werror
REM = rm -rf


all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): srcs/server.c
	$(CC) $(CFLAGS) srcs/server.c -o srcs/server

$(CLIENT): srcs/client.c
	$(CC) $(CFLAGS) srcs/client.c -o srcs/client

clean:
	$(REM) $(SERVER) $(CLIENT)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
