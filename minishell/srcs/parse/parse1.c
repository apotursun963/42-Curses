/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:13:36 by atursun           #+#    #+#             */
/*   Updated: 2025/03/11 18:13:36 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

/*
Yani, bu fonksiyon şu anda herhangi bir tırnağın açık olup olmadığını kontrol eder.
*/
bool    update_and_check_quotes(t_quotes *quotes, char chr)
{
    if (chr == '\'' && !quotes->dlbe)
        quotes->sgle = !quotes->sgle;
    else if (chr == '"' && !quotes->sgle)
        quotes->dlbe = !quotes->dlbe;
    return (!quotes->dlbe && !quotes->sgle);
}

int	redirect_type(char *str, int i)
{
	if (str[i] == '<' && str[i + 1] == '<')
		return (INPUT_DOUBLE_REDIRECT);
	if (str[i] == '<')
		return (INPUT_REDIRECT);
	if (str[i] == '>' && str[i + 1] == '>')
		return (OUTPUT_DOUBLE_REDIRECT);
	if (str[i] == '>')
		return (OUTPUT_REDIRECT);
	return (EMPTY);
}

/*
bir string içindeki yönlendirme operatörlerinin (< ve >) doğru şekilde kullanılıp kullanılmadığını kontrol eder.
*/
bool	check_redirect(char *str, int *i)
{
	int	redirect_first;
	int	redirect_second;
	int	j;

	if (str[*i] == '<' || str[*i] == '>')
	{
		redirect_first = redirect_type(str, *i);
		(*i)++;
		if (redirect_first == OUTPUT_DOUBLE_REDIRECT
            || redirect_first == INPUT_DOUBLE_REDIRECT)
			(*i)++;
		j = *i;
		while (is_only_whitespace(str + j))		// -> str[j] aslında 
			j++;
		if (str[j] == '\0' || str[j] == ';')
			return (error_syntax_token('\n'));
		redirect_second = redirect_type(str, j);
		if (!error_redirect_check(redirect_first, redirect_second))
			return (false);
	}
	return (true);
}

/*
bir string içindeki ayırıcı sembollerin (;, |, \) doğru şekilde kullanılıp kullanılmadığını kontrol eder.
*/
bool check_seps(char *str, int *i)
{
    static char *sep_symbols;

    sep_symbols = ";|\\";
	if (ft_strchr(sep_symbols, str[*i]))
	{
		if (*i == 0 || str[*i + 1] == '\0' || ft_strchr(sep_symbols, str[*i + 1]))
			return (error_syntax_token(str[*i]));
		while (is_only_whitespace(str + (*i + 1)))		// aslında -> str[*i + 1]
			(*i)++;
	}
	return (true);
}

/*
gelen string'i belirli bir sözdizimine (syntax) uygun olup olmadığını kontrol eder.
*/
bool    validate_syntax(char *str)
{
    int         i;
    t_quotes    quotes;
    static char *special_chrs;

    quotes.dlbe = false;
    quotes.sgle = false;
    special_chrs = "\\<>|;";
    while (str[i])
    {
        if (update_and_check_quotes(&quotes, str[i])
            && ft_strchr(special_chrs, str[i]))
        {
            if (!check_seps(str, &i) || !check_redirect(str, &i))
                return (false);
        }
        else if (str[i] == '\\' && quotes.dlbe)
            i++;
        if (str[i])
            i++;
    }
    return (true);
}
