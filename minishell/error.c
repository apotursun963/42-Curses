/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:45:16 by atursun           #+#    #+#             */
/*   Updated: 2025/04/30 17:45:16 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	syntax_error_msg(char *str)
{
	static bool	message_printed;

	message_printed = false;
	if (!message_printed)
	{
		ft_putendl_fd(SYNTAX_ERROR, 2);
		if (str)
			ft_putendl_fd(str, 2);
		message_printed = true;
	}
	else
		message_printed = false;
	return (true);
}

bool	handle_redir_error(char *str, int *i, int redir_len)
{
	char	*error_msg;

	if (str[*i + 1] == '|')
		return (syntax_error_msg("near unexpected token `|'"), false);
	*i += redir_len;
	while (str[*i] && ft_isspace(str[*i]))
		(*i)++;
	if (ft_isredir(&str[*i]))
	{
		if (str[*i] == '>' && str[*i + 1] == '>')
			error_msg = "near unexpected token `>>'";
		else if (str[*i] == '<')
			error_msg = "near unexpected token `<'";
		else
			error_msg = "near unexpected token `>'";
		syntax_error_msg(error_msg);
		return (false);
	}
	return (true);
}

void	exec_failure(t_shell *shell, char *cmd, char *error_msg, int code)
{
	if (cmd == NULL)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(error_msg, 2);
		ft_putstr_fd("\n", 2);
		free_shell(shell);
		exit(code);
	}
	if (ft_strncmp(cmd, ".", 1) == 0)
		error_msg = "bash: .: filename argument required\n\
.: usage: . filename [arguments]";
	else if (access(cmd, F_OK) == 0 && access(cmd, X_OK) == -1)
	{
		error_msg = ": Permission denied";
		code = 126;
	}
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putendl_fd(error_msg, 2);
	free_shell(shell);
	exit(code);
}
