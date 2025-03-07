/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:39:52 by atursun           #+#    #+#             */
/*   Updated: 2025/03/07 17:39:46 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"

static char    *parse_command(char *input, int cmd_len)
{
    char *cmd;

    cmd = malloc(cmd_len + 1);
    if (!cmd)
        return (NULL);
    ft_memcpy(cmd, input, cmd_len);
    cmd[cmd_len] = '\0';
    return (cmd);
}

static char *parse_flags(char *input, int start)
{
    char *flg;
    int flg_len;
    int i;

    i = start;
    flg_len = 0;
    while (input[i++])
        flg_len++;
    if (flg_len <= 0)
        return (NULL);
    flg = malloc(flg_len + 1);
    if (!flg)
        return NULL;
    ft_memcpy(flg, input + start, flg_len);
    flg[flg_len] = '\0';
    return (flg);
}

char    *is_there_quotation_mark(char *input)
{
    int i;
    int j;
    char *res;
    char quote;

    i = 0;
    j = 0;
    res = malloc(ft_strlen(input) + 1);
    while (input[i])
    {
        if (input[i] == '"' || input[i] == '\'')
        {
            if (quote == 0)
                quote = input[i];
            i++;    // Tırnağı atla
            while (input[i] && input[i] != quote)   // Tırnak içini kopyala
                res[j++] = input[i++];
            if (input[i] == quote)                  // Kapanış tırnağını atla
            {
                quote = 0;
                i++;
            }
        }
        else
            res[j++] = input[i++];
    }
    if (quote != 0)
        return (NULL);
    res[j] = '\0';
    return (res);
}

t_tokens tokenize(char *input)
{
    t_tokens tokens = {NULL, NULL};
    int cmd_len;
    int start;
    int i;
    char *opt_input;

    opt_input = is_there_quotation_mark(input);
    if (opt_input == NULL)
        return (tokens);       
    i = 0;
    while (opt_input[i] && opt_input[i] != ' ')
        i++;
    cmd_len = i;
    start = cmd_len;
    tokens.cmd = parse_command(opt_input, cmd_len);
    if (opt_input[start] == ' ')
        start++;
    tokens.flg = parse_flags(opt_input, start);
    return (tokens);
}
