/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:03:42 by atursun           #+#    #+#             */
/*   Updated: 2025/04/13 12:27:24 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	sig_main(int signo)
{
	if (signo == SIGINT)
	{
		write(2, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		exit_code(130);
	}
	else
	{
		write(2, "Quit (core dumped)\n", 19);
		rl_replace_line("", 0);
		rl_on_new_line();
	}
}

void	handle_signals(void)
{
	signal(SIGINT, sig_main);
	signal(SIGQUIT, SIG_IGN);
}

void	sigint_sig(int sig)
{
	(void)sig;
	write(2, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
}

void	set_cmd_signals(void)
{
	signal(SIGINT, sigint_sig);
	signal(SIGQUIT, sig_main);
}
