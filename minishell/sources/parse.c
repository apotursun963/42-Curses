/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:39:52 by atursun           #+#    #+#             */
/*   Updated: 2025/03/07 18:17:21 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"



// char *extract_quoted_or_unquoted(char *input, int *index)
// {
//     int i;
//     int start;
//     int len;
//     char *res;
//     char quote;

//     i = *index;
//     while (input[i] == ' ')
//         i++;
//     start = i;
//     if (input[i] == '"' || input[i] == '\'')
//     {
//         i++;
//         quote = input[i];
//         start = i;
//         while (input[i] && input[i] != quote)
//             i++;
//         len = i - start; // Tırnak içindeki uzunluk
//         if (input[i] == quote)
//             i++; // Kapanış tırnağını geç
//     }
//     else
//     {
//         while (input[i] && input[i] != ' ')
//             i++;
//         len = i - start;
//     }
//     res = malloc(len + 1);
//     strncpy(res, input + start, len);
//     res[len] = '\0';
//     *index = i; // Yeni konumu güncelle
//     return (res);
// }

// t_tokens tokenize(char *input)
// {
//     t_tokens tokens = {NULL, NULL};
//     int i;

//     i = 0;
//     tokens.cmd = extract_quoted_or_unquoted(input, &i);
//     if (input[i])
//         tokens.flg = extract_quoted_or_unquoted(input, &i);
//     return (tokens);
// }






static char *parse_command(char *input, int cmd_len)
{
    char *cmd;
    int i = 0, j = 0;
    char quote = 0;

    cmd = malloc(cmd_len + 1);
    if (!cmd)
        return (NULL);
    while (i < cmd_len)
    {
        if (input[i] == '"' || input[i] == '\'')
        {
            quote = input[i];
            i++; 
            while (i < cmd_len && input[i] != quote)
                cmd[j++] = input[i++];
            if (i < cmd_len && input[i] == quote)
                i++;
        }
        else
            cmd[j++] = input[i++];
    }
    cmd[j] = '\0';
    return (cmd);
}

static char *parse_flags(char *input, int start)
{
    char *flg;
    int flg_len = 0;
    int i = start, j = 0;
    char quote = 0;

    while (input[i])
    {
        flg_len++;
        i++;
    }
    if (flg_len <= 0)
        return (NULL);
    flg = malloc(flg_len + 1);
    if (!flg)
        return (NULL);
    i = start;
    while (input[i])
    {
        if (input[i] == '"' || input[i] == '\'')
        {
            quote = input[i];
            i++; // Açılış tırnağını atla
            while (input[i] && input[i] != quote)
                flg[j++] = input[i++];
            if (input[i] == quote)
                i++; // Kapanış tırnağını atla
        }
        else
            flg[j++] = input[i++];
    }
    flg[j] = '\0';
    return (flg);
}

t_tokens tokenize(char *input)
{
    t_tokens tokens = {NULL, NULL};
    int cmd_len;
    int start;
    int i;

    i = 0;
    while (input[i] && input[i] != ' ')
        i++;
    cmd_len = i;
    start = cmd_len;
    tokens.cmd = parse_command(input, cmd_len);
    if (input[start] == ' ')
        start++;
    tokens.flg = parse_flags(input, start);
    return (tokens);
}
