NAME = minitalk

CC = cc
CFLAGS = -Wall -Wextra -Werror
SERVER = srcs/server
CLIENT = srcs/client

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): srcs/server.c
	$(CC) $(CFLAGS) srcs/server.c -o srcs/server

$(CLIENT): srcs/client.c
	$(CC) $(CFLAGS) srcs/client.c -o srcs/client

clean:
	rm -rf $(SERVER) $(CLIENT)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
