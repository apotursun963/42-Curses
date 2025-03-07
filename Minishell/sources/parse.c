/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:39:52 by atursun           #+#    #+#             */
/*   Updated: 2025/03/07 13:04:25 by atursun          ###   ########.fr       */
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
        return NULL;
    flg = malloc(flg_len + 1);
    if (!flg)
        return NULL;
    ft_memcpy(flg, input + start, flg_len);
    flg[flg_len] = '\0';
    return (flg);
}

t_tokens tokenize(char *input)  // tek ve çift tırnaklarıda kontrol et yani ekle
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
    if (!tokens.cmd)
        return tokens;
    if (input[start] == ' ')
        start++;
    tokens.flg = parse_flags(input, start);
    return (tokens);
}
