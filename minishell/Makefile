NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SOURCES = main.c signals.c environment.c variable_expansions.c redirections.c heredoc.c check_input.c path_status.c \
		exitcode.c free.c execute.c tokenize.c error.c asym_bin_tree.c command_args.c
BUILTINS = builtins/echo.c builtins/pwd.c builtins/builtins.c builtins/env.c builtins/exit.c \
		builtins/export/export.c builtins/export/export_utils.c builtins/unset/unset.c builtins/unset/unset_utils.c \
		builtins/cd/cd.c builtins/cd/cd_utils.c

SRCS =  $(SOURCES) $(BUILTINS)
OBJS = $(SRCS:.c=.o)

LIBFT = library_funcs/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) -lreadline

$(LIBFT):
	@make -s -C library_funcs all bonus

clean:
	@make -s -C library_funcs clean
	@rm -f $(OBJS)

fclean: clean
	@make -s -C library_funcs fclean
	@rm -f $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re