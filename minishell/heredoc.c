/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:45:25 by atursun           #+#    #+#             */
/*   Updated: 2025/04/30 17:45:25 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	heredoc_signal(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_IGN);
}

char	*remove_quotes(char *input)
{
	size_t	len;
	char	*result;
	size_t	i;

	if (!input)
		return (NULL);
	len = ft_strlen(input);
	if (len >= 2 && ((input[0] == '"' && input[len - 1] == '"')
			|| (input[0] == '\'' && input[len - 1] == '\'')))
	{
		result = malloc(len - 1);
		if (!result)
			return (NULL);
		i = 0;
		while (i < len - 2)
		{
			result[i] = input[i + 1];
			i++;
		}
		result[i] = '\0';
		return (result);
	}
	return (ft_strdup(input));
}

static void	execute_heredoc_child(t_shell *shell, t_inf *inf, int fd)
{
	char	*delim;
	bool	quoted;
	char	*line;
	char	*expanded;

	delim = remove_quotes(inf->eof);
	quoted = (inf->eof[0] == '"' || inf->eof[0] == '\'');
	while (true)
	{
		line = readline("heredoc> ");
		if (!line || !ft_strcmp(line, delim))
		{
			free(line);
			break ;
		}
		if (quoted)
			ft_putendl_fd(line, fd);
		else
		{
			expanded = process_variable_expansion(shell, line);
			(ft_putendl_fd(expanded, fd), free(expanded));
		}
		free(line);
	}
	(free(delim), close(fd), free_env(shell->env), free_shell(shell), exit(0));
}

static void	process_heredoc(t_shell *shell, t_inf *inf, int fd)
{
	int		status;
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork failed");
		close(fd);
		return ;
	}
	if (pid == 0)
	{
		heredoc_signal();
		execute_heredoc_child(shell, inf, fd);
	}
	close(fd);
	waitpid(pid, &status, 0);
	exit_status(status);
	if (exit_code(-1) == 130)
	{
		shell->last_exit_code++;
		return ;
	}
}

void	handle_heredoc(t_shell *shell, void *root)
{
	static int	id = 1;
	t_list		*infiles;
	int			fd;
	char		*num;

	if (((t_node *)root)->type == N_PIPE)
	{
		handle_heredoc(shell, ((t_pipe *)root)->left);
		handle_heredoc(shell, ((t_pipe *)root)->right);
		return ;
	}
	infiles = ((t_exec *)root)->infiles;
	while (infiles)
	{
		if (((t_inf *)infiles->content)->type == HERE)
		{
			num = ft_itoa(id++);
			((t_inf *)infiles->content)->name = ft_strjoin("heredoc_", num);
			free(num);
			fd = open(((t_inf *)infiles->content)->name \
				, O_RDWR | O_CREAT | O_TRUNC, 0600);
			process_heredoc(shell, (t_inf *)infiles->content, fd);
		}
		infiles = infiles->next;
	}
}
