/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exitcode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 00:05:57 by atursun           #+#    #+#             */
/*   Updated: 2025/03/19 00:05:57 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exit_code(int value)
{
	static int	code = 0;

	if (value == -1)
		return (code);
	code = value;
	return (code);
}

void	exit_status(int status)
{
	if (WIFEXITED(status))
		exit_code(WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		exit_code(128 + WTERMSIG(status));
}

char	*itoa_exit(char **str)
{
	char	*code;
	char	*tmp;

	code = ft_itoa(exit_code(-1));
	tmp = *str;
	*str = ft_strjoin(*str, code);
	return (free(tmp), free(code), *str);
}

void	free_combination(t_shell *shell, t_exec *exec_node)
{
	free_expand(exec_node->argv);
	free_env(shell->env);
	free_shell(shell);
	exit(0);
}
