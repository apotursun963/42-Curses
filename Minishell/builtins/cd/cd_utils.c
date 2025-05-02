/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:29:31 by hakotu            #+#    #+#             */
/*   Updated: 2025/04/17 13:29:31 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*get_env_value(t_list *env, char *key)
{
	t_env	*line;
	int		key_len;

	key_len = ft_strlen(key);
	while (env)
	{
		line = (t_env *)env->content;
		if (ft_strchr(line->value, '='))
		{
			if (!ft_strncmp(line->value, key, key_len)
				&& line->value[key_len] == '=')
				return (line->content);
		}
		else
			if (!ft_strncmp(line->value, key, key_len))
				return (line->content);
		env = env->next;
	}
	return (NULL);
}

bool	is_valid_identifier(char *str)
{
	int	i;

	if (!str || !*str)
		return (false);
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (false);
	i = 1;
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_' && str[i] != '+')
			return (false);
		i++;
	}
	return (true);
}

static void	add_env_var(t_shell *shell, char *key,
			char *value, int is_export)
{
	t_env	*new_env;
	char	*tmp;

	new_env = malloc(sizeof(*new_env));
	if (!new_env)
		return ;
	tmp = ft_strjoin(key, "=");
	new_env->value = tmp;
	if (value)
		new_env->content = ft_strdup(value);
	else
		new_env->content = NULL;
	new_env->is_export = is_export;
	ft_lstadd_back(&shell->env, ft_lstnew(new_env));
}

static void	update_env_var(t_shell *shell, char *key,
			char *value, int is_export)
{
	t_list	*curr;
	t_env	*env_var;
	size_t	key_len;

	curr = shell->env;
	key_len = ft_strlen(key);
	while (curr)
	{
		env_var = curr->content;
		if (ft_strncmp(env_var->value, key, key_len) == 0
			&& env_var->value[key_len] == '=')
		{
			free(env_var->content);
			if (value)
				env_var->content = ft_strdup(value);
			else
				env_var->content = NULL;
			env_var->is_export = is_export;
			return ;
		}
		curr = curr->next;
	}
	add_env_var(shell, key, value, is_export);
}

int	export_var(t_shell *shell, char *arg)
{
	char	*equal;
	char	*key;
	char	*value;

	if (!is_valid_identifier(arg))
	{
		print_invalid_identifier(arg, "export");
		return (1);
	}
	equal = ft_strchr(arg, '=');
	if (!equal)
	{
		update_env_var(shell, arg, NULL, 1);
		return (0);
	}
	key = ft_substr(arg, 0, equal - arg);
	value = ft_strdup(equal + 1);
	update_env_var(shell, key, value, 1);
	free(key);
	free(value);
	return (0);
}
