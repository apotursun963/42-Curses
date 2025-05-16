/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:57:26 by hakotu            #+#    #+#             */
/*   Updated: 2025/04/30 17:57:26 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	exit_from_func(t_shell *shell, char **args)
{
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(args[1], 2);
	ft_putendl_fd(": numeric argument required", 2);
	free_shell(shell);
	free_env(shell->env);
}

void	builts_exit(t_shell *shell, char **args)
{
	int	i;

	ft_putendl_fd("exit", 1);
	i = 0;
	if (args[1][0] == '-' || args[1][0] == '+')
		i++;
	while (args[1][i])
	{
		if (!ft_isdigit(args[1][i]))
		{
			exit_from_func(shell, args);
			exit(2);
		}
		i++;
	}
	if (args[2])
	{
		ft_putendl_fd("minishell: exit: too many arguments", 2);
		free_shell(shell);
		free_env(shell->env);
		exit(1);
	}
	exit(ft_atoi(args[1]));
}

void	is_exit_cmd(t_shell *shell, char *input)
{
	if (ft_strcmp(input, "exit") == 0
		|| ft_strcmp(input, "\"exit\"") == 0
		|| ft_strcmp(input, "'exit'") == 0)
	{
		ft_putendl_fd("exit", 1);
		free_shell(shell);
		free_env(shell->env);
		exit(0);
	}
}
