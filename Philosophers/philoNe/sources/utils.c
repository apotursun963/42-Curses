/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:10:27 by atursun           #+#    #+#             */
/*   Updated: 2025/02/25 18:25:29 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

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

void	finish_all(t_simulation *sim, t_mutex *forks, int num_of_philo)
{
	while (--num_of_philo >= 0)
		pthread_mutex_destroy(&forks[num_of_philo]);
	pthread_mutex_destroy(&sim->write_lock);
	pthread_mutex_destroy(&sim->meal_lock);
	pthread_mutex_destroy(&sim->dead_lock);
}

void	ft_usleep(int mls)
{
	int	start;

	start = get_current_time();
	while ((get_current_time() - start) < mls)
		usleep(500);
}

int	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_action(t_philo *philo, char *action)
{
	int	time;

	pthread_mutex_lock(philo->mutexes.write_lock);
	time = get_current_time() - philo->times.born_time;		// filozofun kaç milisaniyedir yaşadığını belirlemek için kullanılır.
	pthread_mutex_lock(philo->mutexes.dead_lock);
	if (*philo->dead != 1)		// eğer ölmemişse
		printf(GREEN"[%d]"RESET" %d%s\n", time, philo->id, action);
	pthread_mutex_unlock(philo->mutexes.dead_lock);
	pthread_mutex_unlock(philo->mutexes.write_lock);
}
