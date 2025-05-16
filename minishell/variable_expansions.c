/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_expansions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:04:43 by atursun           #+#    #+#             */
/*   Updated: 2025/04/02 14:04:43 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	expand_single_quote_content(char **str, char *input, int i)
{
	int		start;
	char	*tmp;
	char	*subs;

	start = ++i;
	while (input[i] && input[i] != '\'')
		i++;
	subs = ft_substr(input, start, i - start);
	tmp = *str;
	*str = ft_strjoin(*str, subs);
	return (free(tmp), free(subs), (i + 1));
}

static int	expand_env_var(t_shell *shell, char **str, char *input, int i)
{
	int		start;
	char	*key;
	char	*val;
	char	*tmp;

	start = ++i;
	if (!(ft_isalnum(input[i]) || input[i] == '_' || input[i] == '?'))
		return (*str = ft_strjoinchr(*str, '$'), start);
	if (input[i] == '?')
	{
		*str = itoa_exit(str);
		return (i + 1);
	}
	while (input[i] && (ft_isalnum(input[i]) || input[i] == '_'))
		i++;
	key = ft_substr(input, start, i - start);
	val = get_env_value(shell->env, key);
	free(key);
	if (val)
	{
		tmp = *str;
		*str = ft_strjoin(*str, val);
		free(tmp);
	}
	return (i);
}

static int	expand(t_shell *shell, char **str, char *input, int i)
{
	while (input[i] && !ft_isspace(input[i]))
	{
		if (input[i] == '$')
			i = expand_env_var(shell, str, input, i);
		else if (input[i] == '\'')
			i = expand_single_quote_content(str, input, i);
		else if (input[i] == '"')
		{
			i++;
			while (input[i] && input[i] != '"')
			{
				if (input[i] == '$')
					i = expand_env_var(shell, str, input, i);
				else
					*str = ft_strjoinchr(*str, input[i++]);
			}
			if (input[i] == '"')
				i++;
		}
		else
			*str = ft_strjoinchr(*str, input[i++]);
	}
	return (i);
}

char	*process_variable_expansion(t_shell *shell, char *input)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strdup("");
	while (input[i])
	{
		if (input[i] == '$' || ft_isquote(input[i]))
			i = expand(shell, &str, input, i);
		else
			str = ft_strjoinchr(str, input[i++]);
	}
	if (!*str && input[0] == '$')
		return (free(str), NULL);
	return (str);
}

char	**expand_variable(t_shell *shell, char **argv)
{
	char	**new_argv;
	char	*expand;
	int		i;
	int		j;

	i = 0;
	while (argv && argv[i])
		i++;
	new_argv = malloc((i + 1) * sizeof(char *));
	if (!new_argv)
		return (NULL);
	i = 0;
	j = 0;
	while (argv && argv[i])
	{
		expand = process_variable_expansion(shell, argv[i]);
		if (expand)
			new_argv[j++] = expand;
		i++;
	}
	new_argv[j] = NULL;
	return (free(argv), new_argv);
}
