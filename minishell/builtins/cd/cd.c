/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:17:04 by hakotu            #+#    #+#             */
/*   Updated: 2025/04/13 21:46:01 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	cd_error(char *path, char *msg)
{
	ft_putstr_fd("minishell: cd: ", 2);
	if (path && *path)
	{
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putendl_fd(msg, 2);
	exit_code(1);
	return (1);
}

static int	cd_chdir(char *path)
{
	int	ret;

	ret = chdir(path);
	if (ret == 0)
		return (0);
	if (errno == EACCES)
		return (cd_error(path, "Permission denied"));
	if (errno == ENOENT)
		return (cd_error(path, "No such file or directory"));
	if (errno == ENOTDIR)
		return (cd_error(path, "Not a directory"));
	if (errno == ENAMETOOLONG)
		return (cd_error(path, "File name too long"));
	return (cd_error(path, strerror(errno)));
}

static char	*cd_get_path(t_shell *shell, char **argv)
{
	char	*path;
	char	*home;

	path = argv[1];
	if (!path)
		return (get_env_value(shell->env, "HOME"));
	if (!ft_strncmp(path, "-", 2))
	{
		path = get_env_value(shell->env, "OLDPWD");
		if (!path)
			return (cd_error(NULL, "OLDPWD not set"), NULL);
		ft_putendl_fd(path, 1);
		return (path);
	}
	if (!ft_strcmp(path, "~"))
	{
		home = get_env_value(shell->env, "HOME");
		if (!home)
			return (cd_error(NULL, "HOME not set"), NULL);
		return (home);
	}
	return (path);
}

static int	cd_update_env(t_shell *shell, char *old_pwd)
{
	char	*pwd;
	char	*pwd_var;
	char	*oldpwd_var;

	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		free(old_pwd);
		cd_error(NULL, "error retrieving current directory");
		return (1);
	}
	pwd_var = ft_strjoin("PWD=", pwd);
	oldpwd_var = ft_strjoin("OLDPWD=", old_pwd);
	export_var(shell, pwd_var);
	export_var(shell, oldpwd_var);
	free(pwd_var);
	free(oldpwd_var);
	free(pwd);
	free(old_pwd);
	return (0);
}

int	builts_cd(char **argv, t_shell *shell)
{
	int		argc;
	char	*path;
	char	*old_pwd;

	argc = 0;
	while (argv[argc])
		argc++;
	if (argc > 2)
		return (cd_error(NULL, "too many arguments"));
	path = cd_get_path(shell, argv);
	if (!path)
		return (1);
	old_pwd = ft_strdup(get_env_value(shell->env, "PWD"));
	if (!old_pwd)
		return (cd_error(NULL, "memory allocation error"));
	if (cd_chdir(path) != 0)
	{
		free(old_pwd);
		return (1);
	}
	return (cd_update_env(shell, old_pwd));
}
