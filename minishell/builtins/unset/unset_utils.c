/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:22:45 by hakotu            #+#    #+#             */
/*   Updated: 2025/04/30 17:59:53 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	remove_first_node(t_shell *shell, t_list *curr)
{
	t_env	*env_var;

	env_var = (t_env *)curr->content;
	shell->env = curr->next;
	free(env_var->value);
	free(env_var->content);
	free(env_var);
	free(curr);
}

void	remove_node(t_list *prev)
{
	t_list	*curr;
	t_env	*env_var;

	if (!prev || !prev->next)
		return ;
	curr = prev->next;
	env_var = (t_env *)curr->content;
	prev->next = curr->next;
	free(env_var->value);
	free(env_var->content);
	free(env_var);
	free(curr);
}

int	check_first_node(t_shell *shell, char *var_name)
{
	t_list	*curr;
	t_env	*env_var;

	if (!shell->env)
		return (0);
	curr = shell->env;
	env_var = (t_env *)curr->content;
	if (ft_strncmp(env_var->value, var_name, ft_strlen(var_name)) == 0)
	{
		remove_first_node(shell, curr);
		return (1);
	}
	return (0);
}
