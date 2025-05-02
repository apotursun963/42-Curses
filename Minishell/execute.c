/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:23:12 by atursun           #+#    #+#             */
/*   Updated: 2025/03/18 15:23:12 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	run_pipe_child(t_shell *shell, t_pipe *pipe_node, int *pipefd
	, bool is_left)
{
	if (is_left)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		exec_tree(shell, pipe_node->left);
	}
	else
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		exec_tree(shell, pipe_node->right);
	}
	exit(0);
}

static void	exec_pipe(t_shell *shell, t_pipe *pipe_node)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	if (pipe(pipefd) == -1)
	{
		perror("pipe failed");
		exit(1);
	}
	pid1 = fork();
	if (pid1 == 0)
		run_pipe_child(shell, pipe_node, pipefd, true);
	pid2 = fork();
	if (pid2 == 0)
		run_pipe_child(shell, pipe_node, pipefd, false);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
	free_env(shell->env);
	free_shell(shell);
	exit_status(status);
	exit(exit_code(-1));
}

void	exec_node(t_shell *shell, t_exec *exec_node)
{
	process_redirections(shell, exec_node);
	exec_node->argv = expand_variable(shell, exec_node->argv);
	if (!exec_node->argv || !exec_node->argv[0])
		free_combination(shell, exec_node);
	check_path_status(shell, exec_node->argv);
	if (is_builtin(exec_node->argv[0]))
	{
		exec_child_builtin(shell, exec_node);
		free_combination(shell, exec_node);
	}
	shell->cmd_path = return_cmd_path(shell->path, exec_node->argv[0]);
	if (!shell->cmd_path)
		cmd_error(shell, exec_node, "command not found");
	if (execve(shell->cmd_path, exec_node->argv, shell->env_arr) == -1)
	{
		free_env(shell->env);
		free_expand(exec_node->argv);
		exec_failure(shell, shell->cmd_path, "command not found", 127);
	}
	free_expand(exec_node->argv);
}

void	exec_tree(t_shell *shell, void *root)
{
	if (((t_node *)root)->type == N_PIPE)
		exec_pipe(shell, root);
	if (((t_node *)root)->type == N_EXEC)
		exec_node(shell, root);
}

void	execute_command_tree(t_shell *shell, void *root)
{
	t_exec	*exec;
	int		status;

	exec = (t_exec *)root;
	set_cmd_signals();
	handle_heredoc(shell, root);
	if (exit_code(-1) == 130 && shell->last_exit_code == 1)
	{
		shell->last_exit_code = 0;
		return ;
	}
	if (((t_node *)root)->type == N_EXEC && is_parent_builtin(exec))
	{
		exec->argv = expand_variable(shell, exec->argv);
		exec_parent_builtin(shell, exec);
		free_expand(exec->argv);
		return ;
	}
	status = 0;
	if (fork() == 0)
		exec_tree(shell, root);
	waitpid(-1, &status, 0);
	exit_status(status);
}
