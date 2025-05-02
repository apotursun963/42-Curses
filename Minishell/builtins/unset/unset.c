/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:22:45 by hakotu            #+#    #+#             */
/*   Updated: 2025/04/30 17:59:07 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:22:45 by hakotu            #+#    #+#             */
/*   Updated: 2025/04/30 17:51:46 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static t_list	*find_prev_node(t_list *lst, char *var_name)
{
	t_list	*curr;
	t_env	*env_var;

	if (!lst || !lst->next)
		return (NULL);
	curr = lst;
	while (curr->next)
	{
		env_var = (t_env *)curr->next->content;
		if (ft_strncmp(env_var->value, var_name, ft_strlen(var_name)) == 0)
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}

static void	remove_env_var(t_shell *shell, char *var_name)
{
	t_list	*prev;

	if (check_first_node(shell, var_name))
		return ;
	prev = find_prev_node(shell->env, var_name);
	if (prev)
		remove_node(prev);
}

void	print_invalid_identifier(char *arg, char *cmd)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": `", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	exit_code(1);
}

void	builts_unset(t_shell *shell, char **args)
{
	int	i;
	int	exit_status;

	if (!args || !args[1])
		return ;
	i = 1;
	exit_status = 0;
	while (args[i])
	{
		if (!is_valid_identifier(args[i]))
		{
			print_invalid_identifier(args[i], "unset");
			exit_status = 1;
		}
		else
			remove_env_var(shell, args[i]);
		i++;
	}
	exit_code(exit_status);
}
