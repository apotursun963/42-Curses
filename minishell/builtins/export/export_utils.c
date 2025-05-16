/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:21:26 by hakotu            #+#    #+#             */
/*   Updated: 2025/04/30 18:00:29 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	write_exports(t_list *list)
{
	t_env	*env;

	while (list)
	{
		env = (t_env *)list->content;
		if (env->is_export)
		{
			if (env->value[0] == '_' && env->value[1] == '=')
			{	
				list = list->next;
				continue ;
			}
			if (env->content)
			{
				if (ft_strchr(env->value, '='))
					printf("declare -x %s\"%s\"\n", env->value, env->content);
				else
					printf("declare -x %s=\"%s\"\n", env->value, env->content);
			}
			else
				printf("declare -x %s\n", env->value);
		}
		list = list->next;
	}
}

t_env	*find_variable(t_list *env, char *arg)
{
	t_env	*env_var;
	int		key_len;
	char	*equal;

	equal = ft_strchr(arg, '=');
	if (equal)
		key_len = equal - arg;
	else
		key_len = ft_strlen(arg);
	while (env)
	{
		env_var = (t_env *)env->content;
		if (!ft_strncmp(env_var->value, arg, key_len)
			&& (env_var->value[key_len] == '\0'
				|| env_var->value[key_len] == '='))
			return (env_var);
		env = env->next;
	}
	return (NULL);
}

void	update_env_list(t_env *env_var, char *arg)
{
	char	*equal;

	equal = ft_strchr(arg, '=');
	if (!equal)
		return ;
	free(env_var->content);
	env_var->content = ft_strdup(equal + 1);
	env_var->is_export = true;
}
