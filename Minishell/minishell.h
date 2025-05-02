/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:45:38 by atursun           #+#    #+#             */
/*   Updated: 2025/04/30 17:45:38 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <stdbool.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <errno.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "library_funcs/libft.h"

# define SYNTAX_ERROR "minishell: syntax error"
# define SYNTAX_QUOTE "`quote unclosed'"
# define QUOTE_ERROR "`quote' error"
# define PIPE_ERROR "near unexpected token `|'"
# define REDIR_ERROR "near unexpected token `newline'"

# define DEFAULT "\033[0;39m"
# define RED    "\033[31m"
# define GREEN  "\033[32m"
# define BLUE   "\033[34m"
# define RESET  "\033[0m"

typedef struct s_shell
{
	t_list		*token_lst;
	char		*input;
	char		*trim_input;
	void		*root;
	t_list		*path;
	t_list		*env;
	char		**env_arr;
	char		*cmd_path;
	int			last_exit_code;
}				t_shell;

typedef struct s_env
{
	char	*value;
	char	*content;
	bool	is_export;
}			t_env;

typedef enum s_token_type
{
	WORD,
	PIPE,
	APPEND,
	OUTFILE,
	INFILE,
	HEREDOC,
}	t_token_type;

typedef struct s_token
{
	char			*value;
	t_token_type	type;
}	t_token;

typedef enum e_node_type
{
	N_PIPE,
	N_EXEC,
}				t_node_type;

typedef struct s_node
{
	t_node_type	type;
}				t_node;

typedef struct s_pipe
{
	t_node			type;
	struct s_exec	*left;
	struct s_exec	*right;
}				t_pipe;

typedef struct s_exec
{
	t_node		type;
	char		**argv;
	t_list		*infiles;
	t_list		*outfiles;
}				t_exec;

typedef enum e_inf_t
{
	INF,
	HERE,
}				t_inf_t;

typedef struct s_inf
{
	t_inf_t	type;
	char	*eof;
	char	*name;
}				t_inf;

typedef enum e_outf_t
{
	APP,
	ADD,
}				t_outf_t;

typedef struct s_outf
{
	t_outf_t	type;
	char		*name;
}				t_outf;

void	cmd_error(t_shell *shell, t_exec *exec_node, char *msg);
void	handle_signals(void);
char	*itoa_exit(char **str);
int		exit_code(int value);
bool	syntax_error_msg(char *str);
bool	input_validation(char *input);
bool	handle_redir_error(char *str, int *i, int redir_len);
void	tokenize_input(t_shell *shell, char *input);
void	free_shell(t_shell *shell);
void	free_env(t_list *env);
void	free_split(char **arr);
void	free_expand(char **argv);
void	*tree(t_list *token_list);
void	exec_node(t_shell *shell, t_exec *exec_node);
void	exec_tree(t_shell *shell, void *root);
void	exit_status(int status);
char	**expand_variable(t_shell *shell, char **argv);
char	*process_variable_expansion(t_shell *shell, char *input);
void	exec_failure(t_shell *shell, char *cmd, char *error_msg, int code);
char	**get_environment(t_shell *shell);
void	create_env_list(t_shell *shell, char **env);
void	process_redirections(t_shell *shell, t_exec *exec_node);
void	handle_heredoc(t_shell *shell, void *root);
void	set_cmd_signals(void);
void	execute_command_tree(t_shell *shell, void *root);
int		is_builtin(char *command);
int		is_parent_builtin(t_exec *exec_node);
void	exec_parent_builtin(t_shell *shell, t_exec *exec_node);
void	exec_child_builtin(t_shell *shell, t_exec *exec_node);
char	*get_env_value(t_list *envp, char *key);
t_list	*get_path_from_env(char **env_arr);
int		check_path_status(t_shell *shell, char **path);
void	path_message(t_shell *shell, char **path, char *error_msg);
t_list	*get_outfiles(t_list *tokens, t_list **outfiles);
t_list	*get_infiles(t_list *tokens, t_list **infiles);
char	**get_argv(t_list *list);
int		count_args(t_list *token_list);
void	init_shell(t_shell *shell);
void	is_exit_cmd(t_shell *shell, char *input);
void	builts_pwd(void);
int		builts_echo(char **args, t_list *env);
void	builts_env(t_shell *shell, t_exec *exec_node, t_list *list);
void	builts_exit(t_shell *shell, char **args);
int		builts_cd(char **argv, t_shell *shell);
void	builts_unset(t_shell *shell, char **args);
void	builts_export(t_shell *shell, char **args);
void	remove_node(t_list *prev);
void	remove_first_node(t_shell *shell, t_list *curr);
int		check_first_node(t_shell *shell, char *var_name);
void	write_exports(t_list *list);
t_env	*find_variable(t_list *env, char *arg);
void	update_env_list(t_env *env_var, char *arg);
int		export_var(t_shell *shell, char *arg);
bool	is_valid_identifier(char *str);
void	print_invalid_identifier(char *arg, char *cmd);
void	builts_unset(t_shell *shell, char **args);
void	redirection_failure(t_shell *shell, char *file, int is_output);
char	*return_cmd_path(t_list *paths, char *cmd);
void	free_combination(t_shell *shell, t_exec *exec_node);

#endif