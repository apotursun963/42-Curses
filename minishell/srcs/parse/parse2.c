/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:15:16 by atursun           #+#    #+#             */
/*   Updated: 2025/03/11 18:15:16 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

/*
Bir string'in yalnızca boşluk karakterlerinden (' ') veya 
tab karakterlerinden ('\t') oluşup oluşmadığını kontrol eder.
Eğer boşluk veya tab var ise true yoks false döner.
*/
bool    is_only_whitespace(char *str)
{
    int i;

    i = 0;
    while (str[i] && (str[i] == ' ' ||  str[i] == '\t'))
        i++;
    return (str[i] == '\0');
}

/*
Bir String'in başındaki ve sonundaki boşluk (' ') veya tab ('\t') 
karakterlerini temizleyerek yeni bir string döndürür.
*/
char    *trim_whitespace(char *str)
{
    int begin;
    int end;
    int size;

    if (!str)
        return (NULL);
    begin = 0;
    end = ft_strlen(str) - 1;
    while (str[begin] && (str[begin] == ' ' || str[begin] == '\t'))
        begin++;
    while (end >= begin && (str[end] == ' ' || str[end] == '\t'))
        end--;
    size = (end - begin) + 1;
    if (size <= 0)
        return (ft_strdup(""));
    return (ft_substr(str, begin, size));
}

bool	error_syntax_token(char ch)
{
	if (ch == '\0')
		write(2, ": these commands are not supported\n", 35);
	else if (ch == '\n')
		write(2, ": syntax error near unexpected token `newline'\n", 47);
	else if (ch == ';')
		write(2, ": syntax error near unexpected token `;'\n", 41);
	else if (ch == '\\')
		write(2, ": syntax error near unexpected token `\\'\n", 41);
	else if (ch == '|')
		write(2, ": syntax error near unexpected token `|'\n", 41);
	return (false);
}

bool	error_redirect_check(int redirect_first, int redirect_second)
{
	if (redirect_first != EMPTY && redirect_second != EMPTY)
	{
		if (redirect_second == OUTPUT_DOUBLE_REDIRECT)
			write(2, ": syntax error near unexpected token `>>'\n", 42);
		else if (redirect_second == OUTPUT_REDIRECT)
			write(2, ": syntax error near unexpected token `>'\n", 41);
		else if (redirect_second == INPUT_REDIRECT)
			write(2, ": syntax error near unexpected token `<'\n", 41);
		else
			write(2, ": syntax error near unexpected token `newline'\n", 47);
		return (false);
	}
	return (true);
}
