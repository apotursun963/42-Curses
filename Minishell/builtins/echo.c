/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:40:57 by hakotu            #+#    #+#             */
/*   Updated: 2025/04/12 17:09:12 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	n_flag(char *flag)
{
	int	i;

	i = 0;
	if (ft_strlen(flag) <= 1)
		return (0);
	if (flag[0] != '-')
		return (0);
	while (flag[++i])
	{
		if (flag[i] != 'n')
			return (0);
	}
	return (1);
}

static void	re_remove_quotes(char *str)
{
	size_t	len;
	char	quote;

	if (!str)
		return ;
	len = ft_strlen(str);
	if (len == 0)
		return ;
	if (str[0] == '"' || str[0] == '\'')
	{
		quote = str[0];
		ft_memmove(str, str + 1, len);
		len--;
		if (len > 0 && str[len - 1] == quote)
			str[len - 1] = '\0';
	}
}

static void	print_args(char **args, int i)
{
	int		first;
	char	*temp;

	first = 1;
	while (args[i])
	{
		temp = malloc(1024 * sizeof(char));
		if (!temp)
		{
			perror("malloc");
			return ;
		}
		ft_strlcpy(temp, args[i], 1024);
		temp[1023] = '\0';
		re_remove_quotes(temp);
		if (!first)
			printf(" ");
		printf("%s", temp);
		first = 0;
		i++;
		free(temp);
	}
}

int	builts_echo(char **args, t_list *env)
{
	int		flag;
	int		i;
	char	*home;

	flag = 0;
	i = 1;
	while (args[i] && n_flag(args[i]))
	{
		flag = 1;
		i++;
	}
	if (args[i] && !ft_strcmp(args[i], "~"))
	{
		home = get_env_value(env, "HOME");
		if (home == NULL)
			return (printf("minishell: HOME not set\n\n"), 1);
		printf("%s", home);
		if (!flag)
			printf("\n");
		return (0);
	}
	print_args(args, i);
	if (!flag)
		printf("\n");
	return (0);
}
