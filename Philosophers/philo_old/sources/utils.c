/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:03:53 by atursun           #+#    #+#             */
/*   Updated: 2025/02/23 23:30:58 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	throw_error_msg(t_error msg)
{
	if (msg == WRONG_ARGUMENT_COUNT)
		printf("Wrong Argument Count\n");
	else if (msg == INVALID_PHILOS_NUMBER)
		printf("Invalid Philosophers Number\n");
	else if (msg == ARGS_MUST_BE_DIGITS)
		printf("Arguments Must Be Only Digits\n");
	return (0);
}

/*
Bu fonksiyon, filozof simülasyonu sona erdiğinde kullanılan mutex kilitlerini 
temizler ve serbest bırakır.
*/
void	finish_all(t_simulation *sim, int num_of_philo)
{
	while (--num_of_philo >= 0)
		pthread_mutex_destroy(&sim->forks[num_of_philo]);
	pthread_mutex_destroy(&sim->write_lock);
	pthread_mutex_destroy(&sim->meal_lock);
}

void	print_action(t_philo *philo, char *action)
{
	int	time;

	pthread_mutex_lock(philo->mutexes.write_lock);
	time = get_current_time() - philo->times.born_time;		// filozofun kaç milisaniyedir yaşadığını belirlemek için kullanılır.
	printf(GREEN"[%d]"RESET" %d%s\n", time, philo->id, action);
	pthread_mutex_unlock(philo->mutexes.write_lock);
}

int	ft_atoi(char *str)
{
	int		result;
	int			sign;

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
