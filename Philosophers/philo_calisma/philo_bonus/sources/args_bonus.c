/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:43:40 by atursun           #+#    #+#             */
/*   Updated: 2025/02/27 19:43:40 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/philo_bonus.h"

static int	is_digit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

int	inspect_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
		return (0);
	if (ft_atoi(argv[1]) > NUMBER_OF_PHILO)
		return (0);
	while (i < argc)
	{
		if (ft_atoi(argv[i]) <= 0 || !is_digit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}
