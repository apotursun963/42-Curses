/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:27:38 by atursun           #+#    #+#             */
/*   Updated: 2025/03/09 12:39:24 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"

void take_signal(int signal)
{
    if (signal == SIGINT)
    {
        write(1, "\n", 1);          // Yeni satır yaz
        rl_on_new_line();           // readline'ı yeni satıra geçir
        rl_replace_line("", 0);     // Girdiyi temizle
        rl_redisplay();             // Yeni prompt'u göster
    }
}

void handle_signals()
{
    signal(SIGINT, take_signal);      // ctrl + c
    signal(SIGQUIT, SIG_IGN);         // ctrl + '
}
