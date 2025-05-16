/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:09:33 by atursun           #+#    #+#             */
/*   Updated: 2025/04/02 14:09:33 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	redirection_err_msg(t_shell *shell, char **path, char *error_msg)
{
	if (path && path[0])
		ft_putstr_fd(path[0], 2);
	else
		error_msg = "ambiguous redirect";
	ft_putendl_fd(error_msg, 2);
	free(path[0]);
	free_env(shell->env);
	free_shell(shell);
	exit(1);
}

void	redirection_failure(t_shell *shell, char *file, int is_output)
{
	struct stat	file_stat;
	char		*err_msg;

	err_msg = NULL;
	ft_bzero(&file_stat, sizeof(file_stat));
	if (stat(file, &file_stat) == -1)
		err_msg = ": No such file or directory";
	else if (S_ISDIR(file_stat.st_mode))
		err_msg = ": Is a directory";
	else
	{
		if (is_output)
		{
			if (access(file, W_OK) != 0)
				err_msg = ": Permission denied";
		}
		else
		{
			if (access(file, R_OK) != 0)
				err_msg = ": Permission denied";
		}
	}
	redirection_err_msg(shell, &file, err_msg);
}

static void	handle_infiles(t_shell *shell, t_list *infiles)
{
	int		fd;
	t_inf	*inf;
	char	*name;

	while (infiles)
	{
		inf = ((t_inf *)infiles->content);
		name = process_variable_expansion(shell, inf->eof);
		if (inf->type == INF)
			fd = open(name, O_RDONLY);
		else if (inf->type == HERE)
			fd = open(inf->name, O_RDWR, 0644);
		if (fd < 0)
			redirection_failure(shell, name, 0);
		dup2(fd, STDIN_FILENO);
		close(fd);
		free(name);
		infiles = infiles->next;
	}
}

static void	handle_outfiles(t_shell *shell, t_list *outfiles)
{
	int		fd;
	t_outf	*out;
	char	*name;

	while (outfiles)
	{
		out = ((t_outf *)outfiles->content);
		name = process_variable_expansion(shell, out->name);
		if (out->type == APP)
			fd = open(name, O_RDWR | O_CREAT | O_APPEND, 0644);
		else if (out->type == ADD)
			fd = open(name, O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (fd < 0)
			redirection_failure(shell, name, 1);
		dup2(fd, STDOUT_FILENO);
		close(fd);
		free(name);
		outfiles = outfiles->next;
	}
}

void	process_redirections(t_shell *shell, t_exec *exec_node)
{
	t_list	*list;
	t_token	*token;

	list = shell->token_lst;
	while (list)
	{
		token = ((t_token *)list->content);
		if (token->type == INFILE || token->type == HEREDOC)
			handle_infiles(shell, exec_node->infiles);
		if (token->type == OUTFILE || token->type == APPEND)
			handle_outfiles(shell, exec_node->outfiles);
		list = list->next;
	}
}
