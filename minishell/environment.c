/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:45:11 by atursun           #+#    #+#             */
/*   Updated: 2025/04/30 17:45:11 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_env_list(t_shell *shell, char **env)
{
	int		i;
	t_env	*node;
	int		val_len;
	int		content_len;

	i = -1;
	shell->env = NULL;
	while (env[++i])
	{
		node = malloc(sizeof(t_env));
		val_len = 0;
		while (env[i][val_len] && env[i][val_len] != '=')
			val_len++;
		val_len++;
		content_len = 0;
		while (env[i][content_len])
			content_len++;
		content_len -= val_len;
		node->value = malloc(val_len + 1);
		node->content = malloc(content_len + 1);
		ft_strlcpy(node->value, env[i], val_len + 1);
		ft_strlcpy(node->content, env[i] + val_len, content_len + 1);
		ft_lstadd_back(&shell->env, ft_lstnew(node));
		node->is_export = true;
	}
}

char	**get_environment(t_shell *shell)
{
	t_list	*env_list;
	char	**env_arr;
	t_env	*env;
	char	*tmp;
	int		i;

	i = 0;
	env_list = shell->env;
	env_arr = malloc(sizeof(char *) * (ft_lstsize(env_list) + 1));
	while (env_list)
	{
		env = env_list->content;
		if (!ft_strchr(env->value, '='))
		{
			env_arr[i] = ft_strjoin(env->value, "=");
			tmp = env_arr[i];
			env_arr[i] = ft_strjoin(env_arr[i], env->content);
			free(tmp);
		}
		else
			env_arr[i] = ft_strjoin(env->value, env->content);
		env_list = env_list->next;
		i++;
	}
	return (env_arr[i] = NULL, env_arr);
}

t_list	*get_path_from_env(char **env_arr)
{
	int		i;
	int		j;
	char	**paths;
	t_list	*path_list;

	i = 0;
	j = 0;
	path_list = NULL;
	while (env_arr[i])
	{
		if (ft_strncmp(env_arr[i], "PATH=", 5) == 0)
		{
			paths = ft_split(env_arr[i] + 5, ':');
			while (paths[j])
			{
				ft_lstadd_back(&path_list, ft_lstnew(ft_strdup(paths[j])));
				j++;
			}
			free_split(paths);
			break ;
		}
		i++;
	}
	return (path_list);
}

void	free_env(t_list *env)
{
	t_list	*next;
	t_env	*env_var;

	while (env)
	{
		next = env->next;
		env_var = (t_env *)env->content;
		free(env_var->value);
		free(env_var->content);
		free(env_var);
		free(env);
		env = next;
	}
}

void	free_split(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}
