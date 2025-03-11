/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:28:14 by atursun           #+#    #+#             */
/*   Updated: 2025/03/11 14:28:14 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"

static t_env_vars  *create_vairable(char *line)
{
    int         i;
    int         j;
    t_env_vars  *new_var;

    new_var = (t_env_vars *)malloc(sizeof(t_env_vars));
    if (!new_var)
        exit(1);
    i = 0;
    while (line[i] != '=' && line[i] != '\0')
        i++;
    new_var->key = ft_substr(line, 0, i);
    if (!new_var->key)
        exit(1);
    j = i + 1;
    while (line[j] != '\0' && line[j] != '\n')
        j++;
    new_var->val = ft_substr(line, i + 1, j - i);
    if (!new_var->key)
        exit(1);
    return (new_var);
}

static t_env_lst  *create_env_node(char *line)
{
    t_env_lst  *node;

    node = (t_env_lst *)malloc(sizeof(t_env_lst));
    if (!node)
        exit(1);
    node->data = create_vairable(line);
    node->next = NULL;
    return (node);
}

t_env_lst   *convert_envs_to_list(t_env_lst *envs, char **env)
{
    int         i;
    t_env_lst  *curren_node;

    i = 0;
    if (!env[i])
        return (NULL);
    envs = create_env_node(env[i++]);
    curren_node = envs;
    while (env[i])
    {

        curren_node->next = create_env_node(env[i]);
        curren_node = curren_node->next;
        i++;
    }
    return (envs);
}
