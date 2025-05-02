/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:12:15 by hakotu            #+#    #+#             */
/*   Updated: 2025/04/30 17:59:33 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static char	*get_var_name(char *arg)
{
	int		len;
	char	*name;
	char	*equal;

	equal = ft_strchr(arg, '=');
	if (equal)
		len = equal - arg;
	else
		len = ft_strlen(arg);
	name = malloc(len + 1);
	if (!name)
		return (NULL);
	ft_strlcpy(name, arg, len + 1);
	return (name);
}

static void	add_new_env(t_list **env, char *arg)
{
	t_env	*new;
	char	*equal;

	new = malloc(sizeof(t_env));
	if (!new)
		return ;
	equal = ft_strchr(arg, '=');
	if (equal)
	{
		new->value = get_var_name(arg);
		new->content = ft_strdup(equal + 1);
	}
	else
	{
		new->value = ft_strdup(arg);
		new->content = NULL;
	}
	new->is_export = true;
	ft_lstadd_back(env, ft_lstnew(new));
}

void	builts_export(t_shell *shell, char **args)
{
	int		i;
	t_env	*found;
	char	*key;

	if (!args[1])
		return (write_exports(shell->env));
	i = 1;
	while (args[i])
	{
		key = get_var_name(args[i]);
		if (!is_valid_identifier(key))
		{
			ft_putstr_fd("bash: export: `", STDERR_FILENO);
			ft_putstr_fd(args[i], STDERR_FILENO);
			ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
			exit_code(1);
		}
		found = find_variable(shell->env, args[i]);
		if (found)
			update_env_list(found, args[i]);
		else
			add_new_env(&shell->env, args[i]);
		free(key);
		i++;
	}
}
