/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:45:31 by atursun           #+#    #+#             */
/*   Updated: 2025/04/30 17:45:31 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	add_history_if_valid(char *input)
{
	int		i;

	i = -1;
	while (input[++i])
	{
		if (!ft_isspace(input[i]))
		{
			add_history(input);
			break ;
		}
	}
}

static void	increment_shlvl(t_shell *shell)
{
	t_list	*node;
	t_env	*line;
	char	*new_value;

	node = shell->env;
	while (node)
	{
		line = (t_env *)node->content;
		if (ft_strncmp(line->value, "SHLVL=", 6) == 0)
		{
			new_value = ft_itoa(ft_atoi(line->content) + 1);
			free(line->content);
			line->content = new_value;
		}
		node = node->next;
	}
}

void	init_shell(t_shell *shell)
{
	shell->token_lst = NULL;
	shell->input = NULL;
	shell->trim_input = NULL;
	shell->root = NULL;
	shell->path = NULL;
	shell->env_arr = NULL;
	shell->cmd_path = NULL;
	shell->last_exit_code = 0;
}

static void	start_shell(t_shell *shell)
{
	while (true)
	{
		init_shell(shell);
		handle_signals();
		shell->input = readline(BLUE"atursun"RED"&"GREEN"hakotu"RESET"$ ");
		if (!shell->input)
			(free_shell(shell), free_env(shell->env), exit(0));
		add_history_if_valid(shell->input);
		shell->trim_input = ft_strtrim(shell->input, " ");
		is_exit_cmd(shell, shell->trim_input);
		if (!input_validation(shell->trim_input))
		{
			free_shell(shell);
			continue ;
		}
		tokenize_input(shell, shell->trim_input);
		shell->env_arr = get_environment(shell);
		shell->path = get_path_from_env(shell->env_arr);
		shell->root = tree(shell->token_lst);
		execute_command_tree(shell, shell->root);
		free_shell(shell);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_shell	shell;

	(void)argv;
	if (argc > 1 || !env || !*env)
	{
		if (argc > 1)
			printf(RED"Invalid Input\n"DEFAULT);
		else
			printf(RED"No environment variables found.\n"DEFAULT);
		exit(1);
	}
	create_env_list(&shell, env);
	increment_shlvl(&shell);
	start_shell(&shell);
	free_env(shell.env);
	return (0);
}
