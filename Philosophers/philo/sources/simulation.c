/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:10:11 by atursun           #+#    #+#             */
/*   Updated: 2025/02/26 13:17:28 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static bool	is_all_eat(t_philo *philos)
{
	int		ate;
	int		i;

	i = -1;
	ate = 0;
	if (philos[0].must_eat == -1)
		return (false);
	while (++i < philos[0].philo_count)
	{
		pthread_mutex_lock(philos->mutexes.meal_lock);
		if (philos[i].meals_eaten >= philos[i].must_eat)
			ate++;
		pthread_mutex_unlock(philos->mutexes.meal_lock);
	}
	if (ate == philos[0].philo_count)
	{
		pthread_mutex_lock(philos[0].mutexes.dead_lock);
		*philos->dead = 1;
		pthread_mutex_unlock(philos[0].mutexes.dead_lock);
		return (true);
	}
	return (false);
}

static void	philo_routine(t_philo *philo)
{
	pthread_mutex_lock(philo->mutexes.right_fork);
	print_action(philo, " has taken a fork");
	if (philo->philo_count == 1)
	{
		ft_usleep(philo->times.die);
		pthread_mutex_unlock(philo->mutexes.right_fork);
		return ;
	}
	pthread_mutex_lock(philo->mutexes.left_fork);
	print_action(philo, " has taken a fork");
	print_action(philo, " is eating");
	pthread_mutex_lock(philo->mutexes.meal_lock);
	philo->times.last_meal = get_current_time();
	philo->meals_eaten += 1;
	pthread_mutex_unlock(philo->mutexes.meal_lock);
	ft_usleep(philo->times.eat);
	pthread_mutex_unlock(philo->mutexes.left_fork);
	pthread_mutex_unlock(philo->mutexes.right_fork);
	print_action(philo, " is sleeping");
	ft_usleep(philo->times.sleep);
	print_action(philo, " is thinking");
}

static int	is_philo_dead(t_philo *philo, int die)
{
	pthread_mutex_lock(philo->mutexes.meal_lock);
	if (get_current_time() - philo->times.last_meal >= die)
	{
		pthread_mutex_unlock(philo->mutexes.meal_lock);
		return (true);
	}
	pthread_mutex_unlock(philo->mutexes.meal_lock);
	return (false);
}

void	*start_simulation(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (true)
	{
		pthread_mutex_lock(philo->mutexes.dead_lock);
		if (*philo->dead == 1)
			return (pthread_mutex_unlock(philo->mutexes.dead_lock), NULL);
		pthread_mutex_unlock(philo->mutexes.dead_lock);
		philo_routine(philo);
	}
	return (ptr);
}

void	*check_philo_eating_time(void *ptr)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)ptr;
	while (true)
	{
		i = -1;
		while (++i < philos[0].philo_count)
		{
			if (is_philo_dead(&philos[i], philos[i].times.die) == true)
			{
				print_action(&philos[i], RED" died"RESET);
				pthread_mutex_lock(philos[0].mutexes.dead_lock);
				*philos->dead = 1;
				pthread_mutex_unlock(philos[0].mutexes.dead_lock);
				return (NULL);
			}
		}
		if (is_all_eat(philos) == true)
			return (NULL);
	}
	return (NULL);
}
