/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:50:15 by atursun           #+#    #+#             */
/*   Updated: 2025/03/02 16:50:15 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MINISHELL_H
#define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <signal.h>
# include <unistd.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libraries/libft/libft.h"

# define RED    "\033[31m"
# define GREEN  "\033[32m"
# define BLUE   "\033[34m"
# define RESET  "\033[0m"



typedef struct s_shell
{
    int		std_in;
	int		std_out;
	int		f_in;
	int		f_out;
	int		shlvl;
	int		exit_status;
	int		process_level;
	pid_t	pid;
	char	*tmpfile;
	bool	executed;
	bool	is_running;
}   t_shell;

typedef struct s_env_vars
{
    char                *key;
    char                *val;
}   t_env_vars;

typedef struct s_env_lst
{
	t_env_vars           *data;
	struct s_env_lst    *next;
}	t_env_lst;

typedef struct s_quotes
{
	bool	dlbe;
	bool	sgle;
}	t_quotes;


typedef enum e_redirect
{
	EMPTY,
	INPUT_REDIRECT,
	INPUT_DOUBLE_REDIRECT,
	OUTPUT_REDIRECT,
	OUTPUT_DOUBLE_REDIRECT,
}	t_redirect;


bool		error_redirect_check(int redirect_first, int redirect_second);
bool		error_syntax_token(char ch);
char		*trim_whitespace(char *str);
bool    	is_only_whitespace(char *str);
bool		validate_syntax(char *str);
t_env_lst   *convert_envs_to_list(t_env_lst *envs, char **env);


// typedef struct s_tokens
// {
//     char *cmd;
//     char *flg;
// }   t_tokens;

// void    cd(char *input);
// t_tokens tokenize(char *input);
// void    ft_free(char **str);
void    handle_signals();
// void redirections_type(char *input);

# endif