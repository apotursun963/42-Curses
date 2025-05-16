/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:58:12 by atursun           #+#    #+#             */
/*   Updated: 2025/03/31 18:58:12 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_word_token(t_shell *shell, char *input, t_token *new_token
	, int i)
{
	char	quote;
	int		start;

	start = i;
	while (input[i] && !ft_isspace(input[i]) && !ft_ismeta(input, i))
	{
		if (ft_isquote(input[i]))
		{
			quote = input[i++];
			while (input[i] && input[i] != quote)
				i++;
			if (input[i] == quote)
				i++;
		}
		else
			i++;
	}
	new_token->value = ft_substr(input, start, i - start);
	new_token->type = WORD;
	ft_lstadd_back(&shell->token_lst, ft_lstnew(new_token));
	return (i);
}

static int	handle_redir(t_shell *shell, char *input, t_token *new_token, int i)
{
	if (input[i] == '>' && input[i + 1] == '>')
	{
		new_token->value = ft_strndup(&input[i], 2);
		new_token->type = APPEND;
		i += 2;
	}
	else if (input[i] == '<' && input[i + 1] == '<')
	{
		new_token->value = ft_strndup(&input[i], 2);
		new_token->type = HEREDOC;
		i += 2;
	}
	else
	{
		new_token->value = ft_strndup(&input[i], 1);
		if (input[i] == '<')
			new_token->type = INFILE;
		else
			new_token->type = OUTFILE;
		i += 1;
	}
	ft_lstadd_back(&shell->token_lst, ft_lstnew(new_token));
	return (i);
}

static int	handle_pipe(t_shell *shell, char *input, t_token *new_token, int i)
{
	new_token->value = ft_strndup(&input[i], 1);
	new_token->type = PIPE;
	ft_lstadd_back(&shell->token_lst, ft_lstnew(new_token));
	i++;
	return (i);
}

void	tokenize_input(t_shell *shell, char *input)
{
	int		i;
	t_token	*new_token;

	i = 0;
	while (input[i])
	{
		new_token = malloc(sizeof(t_token));
		if (input[i] == '|')
			i = handle_pipe(shell, input, new_token, i);
		else if (input[i] == '>' || input[i] == '<')
			i = handle_redir(shell, input, new_token, i);
		else
			i = handle_word_token(shell, input, new_token, i);
		while (ft_isspace(input[i]))
			i++;
	}
}
