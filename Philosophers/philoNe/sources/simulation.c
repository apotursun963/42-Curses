/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:10:11 by atursun           #+#    #+#             */
/*   Updated: 2025/02/25 18:25:26 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static bool	is_all_eat(t_philo *philos)
{
	int		ate;
	int		i;

	i = -1;
	ate = 0;
	if (philos[0].must_eat == -1)	// Eğer -1 ise, yemek yeme zorunluluğu yoktur, dolayısıyla false döner.
		return (false);
	while (++i < philos[0].philo_count)
	{
		pthread_mutex_lock(philos->mutexes.meal_lock);
		if (philos[i].meals_eaten >= philos[i].must_eat)	// Filozof yeterince yemek yemişse
			ate++;
		pthread_mutex_unlock(philos->mutexes.meal_lock);
	}
	if (ate == philos[0].philo_count)		// Bütün filozoflar 'must_eat' kadar yemek yemişse
	{
		pthread_mutex_lock(philos[0].mutexes.dead_lock);
		*philos->dead = 1;
		pthread_mutex_unlock(philos[0].mutexes.dead_lock);
		return (true);		// Hepsi yemek yedi
	}
	return (false);		// Henüz tüm filozoflar yemek yememiştir
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

static void	*start_simulation(void *ptr)
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

static void	*check_philo_eating_time(void *ptr)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)ptr;
	while (true)
	{
		i = -1;
		while (++i < philos[0].philo_count)
		{
			pthread_mutex_lock(philos->mutexes.meal_lock);
			if (get_current_time() - philos[i].times.last_meal 
				>= philos[i].times.die)		// Eğer filozof uzun süre yemek yememişse
			{
				pthread_mutex_unlock(philos->mutexes.meal_lock);
				print_action(&philos[i], RED" died"RESET);
				pthread_mutex_lock(philos[0].mutexes.dead_lock);
				*philos->dead = 1;
				pthread_mutex_unlock(philos[0].mutexes.dead_lock);	// bunu yazmadığımda filozof öldükten sonra program bitmiyordu
				return (NULL);
			}
			pthread_mutex_unlock(philos->mutexes.meal_lock);
		}
		if (is_all_eat(philos) == true)		// Tüm filozoflar yemeklerini yedi mi kontrol edilir
			return (NULL);
	}
	return (NULL);
}

void	create_threads(t_simulation *sim)
{
	t_thread	observer_id;
	int			i;

	i = -1;
	pthread_create(&observer_id, NULL, &check_philo_eating_time, sim->philos);
	while (++i < sim->philos[0].philo_count)
		pthread_create(&sim->philos[i].thread_id, NULL,
			&start_simulation, &sim->philos[i]);
	i = -1;
	pthread_join(observer_id, NULL);
	while (++i < sim->philos[0].philo_count)
		pthread_join(sim->philos[i].thread_id, NULL);
}
