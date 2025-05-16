/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 13:47:43 by atursun           #+#    #+#             */
/*   Updated: 2025/04/12 13:47:43 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_expand(char **argv)
{
	int	i;

	i = -1;
	while (argv[++i])
		free(argv[i]);
}

void	path_message(t_shell *shell, char **path, char *error_msg)
{
	ft_putstr_fd(path[0], 2);
	ft_putendl_fd(error_msg, 2);
	free_expand(path);
	free_env(shell->env);
	free_shell(shell);
}

int	check_path_status(t_shell *shell, char **path)
{
	struct stat	path_stat;
	char		*error_msg;
	int			code;

	code = 126;
	error_msg = NULL;
	if (!ft_strchr(path[0], '/'))
		return (1);
	ft_bzero(&path_stat, sizeof(path_stat));
	if (stat(path[0], &path_stat) == -1)
	{
		error_msg = ": No such file or directory";
		code = 127;
	}
	else if (S_ISDIR(path_stat.st_mode))
		error_msg = ": Is a directory";
	else if (access(path[0], X_OK) != 0)
		error_msg = ": Permission denied";
	if (error_msg)
		return (path_message(shell, path, error_msg), exit(code), 0);
	return (code);
}
