/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:54:07 by atursun           #+#    #+#             */
/*   Updated: 2024/12/17 14:22:57 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static void	ft_putpid(int number)
{
	char	chr;

	if (number > 9)
		ft_putpid(number / 10);
	chr = (number % 10) + '0';
	write(1, &chr, 1);
}

static int	ft_atoi_2(unsigned char *str)
{
	int	result;
	int	sign;

	sign = 1;
	result = 0;
	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str == '0' || *str == '1')
		result = (result * 2) + (*str++ - '0');
	return (result * sign);
}

static void	take_signal(int signal)
{
	static unsigned char	byte[9];
	static int				bits;
	char					chr;

	if (signal == SIGUSR1)
		byte[bits] = '1';
	else if (signal == SIGUSR2)
		byte[bits] = '0';
	bits++;
	if (bits == 8)
	{
		byte[8] = '\0';
		chr = ft_atoi_2(byte);
		write(1, &chr, 1);
		bits = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	write(1, "Server Process ID: ", 19);
	ft_putpid(pid);
	write(1, "\n", 1);
	while (1)
	{
		signal(SIGUSR1, take_signal);
		signal(SIGUSR2, take_signal);
		pause();
	}
	return (0);
}
