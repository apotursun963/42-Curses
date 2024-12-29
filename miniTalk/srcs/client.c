/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:54:00 by atursun           #+#    #+#             */
/*   Updated: 2024/12/17 14:18:54 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"
#include <stdlib.h>

static int	ft_strlen(char *str)
{
	int	counter;

	counter = 0;
	while (*str++)
		counter++;
	return (counter);
}

static unsigned char	*get_binary(int chr)
{
	unsigned char	*binary;
	int				idx;

	idx = 7;
	binary = malloc(9);
	while (idx >= 0)
	{
		binary[idx] = (chr % 2) + '0';
		chr /= 2;
		idx--;
	}
	binary[8] = '\0';
	return (binary);
}

static int	ft_atoi_10(char *str)
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
	while (*str >= '0' && *str <= '9')
		result = (result * 10) + (*str++ - '0');
	return (result * sign);
}

static void	send_signal(pid_t process_id, char *message)
{
	unsigned char		*binary_str;
	int					len;
	int					i;

	len = ft_strlen(message);
	message[len] = '\n';
	message[len + 1] = '\0';
	while (*message)
	{
		i = 0;
		binary_str = get_binary((unsigned char)*message);
		while (i < 8)
		{
			if (binary_str[i] == '1')
				kill(process_id, SIGUSR1);
			else
				kill(process_id, SIGUSR2);
			usleep(200);
			i++;
		}
		free(binary_str);
		message++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	process_id;
	char	*message;

	if (argc != 3)
	{
		write(1, "The number of arguments must be 3\n", 34);
		exit(0);
	}
	message = argv[2];
	process_id = ft_atoi_10(argv[1]);
	send_signal(process_id, message);
	write(1, "\033[1;32mMessage Received!👌\n", 29);
	return (0);
}
