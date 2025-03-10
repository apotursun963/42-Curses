/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:05:42 by atursun           #+#    #+#             */
/*   Updated: 2025/03/10 15:39:10 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"

// < (Input Redirection - Girdi Yönlendirme):












void redirections_type(char *input)
{
    int i;
    int start;
    int cmd_len;
    char *filename;
    char *cmd;

    i = 0;
    while (input[i] && input[i] == ' ')
        i++;
    start = i;
    while (input[i] && input[i] != ' ')
        i++;
    cmd_len = i - start;
    cmd = malloc(cmd_len + 1);
}