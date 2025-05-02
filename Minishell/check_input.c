/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:45:01 by atursun           #+#    #+#             */
/*   Updated: 2025/04/30 17:45:01 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	check_quotes(char *str)
{
	int		i;
	char	current_quote;

	i = 0;
	current_quote = 0;
	while (str[i])
	{
		if (ft_isquote(str[i]))
		{
			if (current_quote == 0)
				current_quote = str[i];
			else if (str[i] == current_quote)
				current_quote = 0;
		}
		i++;
	}
	return (current_quote == 0);
}

static bool	check_pipes(char *str)
{
	int		i;
	bool	in_single_quote;
	bool	in_double_quote;

	i = 0;
	in_single_quote = false;
	in_double_quote = false;
	if (str[0] == '|' || str[ft_strlen(str) - 1] == '|')
		return (false);
	while (str[i])
	{
		if (str[i] == '\'' && !in_double_quote)
			in_single_quote = !in_single_quote;
		else if (str[i] == '\"' && !in_single_quote)
			in_double_quote = !in_double_quote;
		if (str[i] == '|' && !in_single_quote && !in_double_quote)
		{
			while (ft_isspace(str[++i]))
				;
			if (str[i] == '|')
				return (false);
		}
		i++;
	}
	return (str[i - 1] != '|' || in_single_quote || in_double_quote);
}

static bool	check_redirs(char *str)
{
	int	i;
	int	redir_len;

	i = 0;
	while (str[i])
	{
		if (str[i] && ft_isquote(str[i]))
		{
			i++;
			while (str[i] && !ft_isquote(str[i]))
				i++;
		}
		redir_len = ft_isredir(&str[i]);
		if (redir_len > 0)
		{
			if (!handle_redir_error(str, &i, redir_len))
				return (false);
			if (!str[i])
				return (syntax_error_msg(REDIR_ERROR), false);
			continue ;
		}
		if (str[i])
			i++;
	}
	return (true);
}

bool	input_validation(char *input)
{
	if (input[0] == '\0')
		return (false);
	if (check_pipes(input) == false)
		return (syntax_error_msg(PIPE_ERROR), exit_code(2), false);
	if (check_quotes(input) == false)
		return (syntax_error_msg(QUOTE_ERROR), exit_code(2), false);
	if (check_redirs(input) == false)
		return (exit_code(2), false);
	return (true);
}
