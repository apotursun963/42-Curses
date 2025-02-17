/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:44:57 by atursun           #+#    #+#             */
/*   Updated: 2025/02/17 14:18:50 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int		result;
	int		sign;

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

int	throw_error_msg(t_error msg)
{
	if (msg == WRONG_ARGUMENT_COUNT)
		printf("Wrong Argument Count\n");
	else if (msg == INVALID_PHILOS_NUMBER)
		printf("Invalid Philosophers Number\n");
	else if (msg == ARGS_CANT_NEGATIVE_OR_ZERO)
		printf("Arguments Can Not Be Negative Or Zero Value\n");
	return (0);
}

int inspect_args(int argc, char **argv)
{
	int i;

	if (ft_atoi(argv[1]) > NUMBER_OF_PHILO)
		return (throw_error_msg(INVALID_PHILOS_NUMBER), 0);
	i = 0;
	while (++i < argc)
	{
		if (ft_atoi(argv[i]) <= 0)
			return (throw_error_msg(ARGS_CANT_NEGATIVE_OR_ZERO), 0);
	}
	return (1);
}