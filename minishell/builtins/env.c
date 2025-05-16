/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:16:57 by hakotu            #+#    #+#             */
/*   Updated: 2025/04/30 17:58:08 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cmd_error(t_shell *shell, t_exec *exec_node, char *msg)
{
	char	*cmd;

	cmd = exec_node->argv[0];
	write(2, cmd, ft_strlen(cmd));
	write(2, ": ", 2);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	free_expand(exec_node->argv);
	free_env(shell->env);
	free_shell(shell);
	exit(127);
}

void	builts_env(t_shell *shell, t_exec *exec_node, t_list *list)
{
	t_env	*env;
	char	*key;

	key = get_env_value(shell->env, "PATH");
	if (key == NULL)
		cmd_error(shell, exec_node, "command not found");
	while (list)
	{
		env = (t_env *)list->content;
		if (env->content)
		{
			if (ft_strchr(env->value, '='))
				printf("%s%s\n", env->value, env->content);
			else
				printf("%s=%s\n", env->value, env->content);
		}
		list = list->next;
	}
}
