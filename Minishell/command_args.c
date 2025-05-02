/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:27:29 by atursun           #+#    #+#             */
/*   Updated: 2025/04/02 14:27:29 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*return_cmd_path(t_list *paths, char *cmd)
{
	t_list	*node;
	char	*temp;
	char	*path;

	if (!ft_strcmp(cmd, ".") || !ft_strcmp(cmd, ".."))
		return (ft_strdup(cmd));
	if (cmd[0] == '/' || !ft_strncmp(cmd, "./", 2)
		|| !ft_strncmp(cmd, "../", 3))
	{
		if (access(cmd, F_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	node = paths;
	while (node)
	{
		temp = ft_strjoin((char *)node->content, "/");
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		node = node->next;
	}
	return (NULL);
}

int	count_args(t_list *token_list)
{
	int		counter;
	t_token	*token;

	counter = 0;
	while (token_list)
	{
		token = (t_token *)token_list->content;
		if (token->type == PIPE)
			break ;
		if (token->type == WORD)
			counter++;
		if (token->type == INFILE || token->type == HEREDOC
			|| token->type == OUTFILE || token->type == APPEND)
			token_list = token_list->next;
		token_list = token_list->next;
	}
	return (counter);
}

char	**get_argv(t_list *list)
{
	int		i;
	int		argc;
	char	**argv;
	t_token	*token;

	i = 0;
	argc = count_args(list);
	argv = malloc((argc + 1) * sizeof(char *));
	while (list && i < argc)
	{
		token = (t_token *)list->content;
		if (token->type == PIPE)
			break ;
		if (token->type == WORD)
			argv[i++] = token->value;
		if (token->type == INFILE || token->type == HEREDOC
			|| token->type == OUTFILE || token->type == APPEND)
			list = list->next;
		list = list->next;
	}
	argv[i] = NULL;
	return (argv);
}

t_list	*get_infiles(t_list *tokens, t_list **infiles)
{
	t_token	*token;
	t_inf	*content;

	while (tokens && ((t_token *)tokens->content)->type != PIPE)
	{
		token = (t_token *)tokens->content;
		if (token->type == INFILE || token->type == HEREDOC)
		{
			content = malloc(sizeof(t_inf));
			content->name = NULL;
			content->eof = NULL;
			if (token->type == INFILE)
				content->type = INF;
			else
				content->type = HERE;
			content->eof = \
				ft_strdup(((t_token *)tokens->next->content)->value);
			ft_lstadd_back(infiles, ft_lstnew(content));
			tokens = tokens->next;
		}
		tokens = tokens->next;
	}
	return (tokens);
}

t_list	*get_outfiles(t_list *tokens, t_list **outfiles)
{
	t_token	*token;
	t_outf	*content;

	while (tokens && ((t_token *)tokens->content)->type != PIPE)
	{
		token = (t_token *)tokens->content;
		if (token->type == OUTFILE || token->type == APPEND)
		{
			content = malloc(sizeof(t_outf));
			if (token->type == APPEND)
				content->type = APP;
			else
				content->type = ADD;
			content->name = \
				ft_strdup(((t_token *)tokens->next->content)->value);
			ft_lstadd_back(outfiles, ft_lstnew(content));
			tokens = tokens->next;
		}
		tokens = tokens->next;
	}
	return (tokens);
}
