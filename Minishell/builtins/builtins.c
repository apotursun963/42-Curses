/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 23:00:10 by hakotu            #+#    #+#             */
/*   Updated: 2025/04/30 17:58:42 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_builtin(char *command)
{
	int			i;
	const char	*builtins[] = {
		"echo",
		"cd",
		"pwd",
		"export",
		"unset",
		"env",
		"exit",
		NULL
	};

	i = 0;
	while (builtins[i])
	{
		if (!ft_strcmp(command, (char *)builtins[i]))
			return (1);
		i++;
	}
	return (0);
}

int	is_parent_builtin(t_exec *exec_node)
{
	char	*cmd;

	cmd = NULL;
	if (exec_node->argv)
		cmd = exec_node->argv[0];
	if (!cmd)
		return (0);
	if (!ft_strcmp(cmd, "exit"))
		return (1);
	if (!ft_strcmp(cmd, "cd"))
		return (1);
	if (!ft_strcmp(cmd, "export"))
		return (1);
	if (!ft_strcmp(cmd, "unset"))
		return (1);
	return (0);
}

void	exec_parent_builtin(t_shell *shell, t_exec *exec_node)
{
	char	*cmd;

	cmd = exec_node->argv[0];
	if (cmd == NULL)
		return ;
	if (!ft_strcmp(cmd, "exit"))
		builts_exit(shell, exec_node->argv);
	if (!ft_strcmp(cmd, "export"))
		builts_export(shell, exec_node->argv);
	if (!ft_strcmp(cmd, "unset"))
		builts_unset(shell, exec_node->argv);
	if (!ft_strcmp(cmd, "cd"))
		builts_cd(exec_node->argv, shell);
}

void	exec_child_builtin(t_shell *shell, t_exec *exec_node)
{
	char	*cmd;

	cmd = exec_node->argv[0];
	if (cmd == NULL)
		return ;
	if (!ft_strcmp(cmd, "echo"))
		builts_echo(exec_node->argv, shell->env);
	if (!ft_strcmp(cmd, "pwd"))
		builts_pwd();
	if (!ft_strcmp(cmd, "env"))
		builts_env(shell, exec_node, shell->env);
	if (!ft_strcmp(cmd, "export") && !exec_node->argv[1])
		builts_export(shell, exec_node->argv);
}
