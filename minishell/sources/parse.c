/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:39:52 by atursun           #+#    #+#             */
/*   Updated: 2025/03/08 16:14:04 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"


// bool is_valid_token(char *token, int token_type)
// {
//     int i;
//     char qutoe;
//     int len;

//     i = 0;
//     qutoe = 0;
//     len = ft_strlen(token);
//     if (ft_strncmp(token_type, "cmd", 3) == 0)
//     {
//         while (input[i] && input[i] == ' ')
//             i++;
//     }
        
// }

static char *parse_command(char *input, int *pos)
{
    char *cmd;
    int i;
    int j;
    char quote = 0;
    int start;
    int cmd_len;
    
    i = *pos;
    j = 0;
    while (input[i] && input[i] == ' ')
        i++;
    start = i;
    while (input[i] && input[i] != ' ')
        i++;
    cmd_len = i - start;
    cmd = malloc(cmd_len + 1);
    if (!cmd)
        return (NULL);
    i = start;
    while (i < start + cmd_len)
    {
        if (input[i] == '"' || input[i] == '\'')
        {
            quote = input[i];
            i++;
            while (i < start + cmd_len && input[i] != quote)
                cmd[j++] = input[i++];
            if (i < start + cmd_len && input[i] == quote)
                i++;
        }
        else
            cmd[j++] = input[i++];
    }
    cmd[j] = '\0';
    *pos = i;
    return (cmd);
}

static char *parse_flags(char *input, int *pos)
{
    char *flg;
    int j = 0;
    char quote = 0;
    int i = *pos;
    int start;
    int flg_len;

    while (input[i] && input[i] != ' ')     // cmd atla
        i++;
    while (input[i] && input[i] == ' ')     // Boşlukları atla
        i++;
    start = i;
    flg_len = ft_strlen(input) - start;
    if (flg_len <= 0)
        return (NULL);
    flg = malloc(flg_len + 1);
    if (!flg)
        return (NULL);
    while (input[i])
    {
        if (input[i] == '"' || input[i] == '\'')
        {
            quote = input[i];
            i++;
            while (input[i] && input[i] != quote)
                flg[j++] = input[i++];
            if (input[i] == quote)
                i++;
        }
        else
            flg[j++] = input[i++];
    }
    flg[j] = '\0';
    *pos = i;
    return (flg);
}

t_tokens tokenize(char *input)
{
    t_tokens tokens = {NULL, NULL};
    int position;

    position = 0;
    tokens.cmd = parse_command(input, &position);
    tokens.flg = parse_flags(input, &position);
    return (tokens);
}
