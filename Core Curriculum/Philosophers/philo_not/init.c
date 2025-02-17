/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:37:41 by atursun           #+#    #+#             */
/*   Updated: 2025/02/17 14:37:59 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void 	init_simulation(t_simulation *sim, t_philosopher *philos, t_mutex *forks)
{
	sim->philos = philos;
	sim->forks = forks;
	pthread_mutex_init(&sim->write_lock, NULL);
	pthread_mutex_init(&sim->meal_lock, NULL);
}

void 	init_forks(t_mutex *forks, int num_of_philo)
{
	int	i;

	i = -1;
	while (++i < num_of_philo)
		pthread_mutex_init(&forks[i], NULL);
}

void 	init_philos(t_simulation *sim, t_philosopher *philos, t_mutex *forks, char **argv)
{
	int	i;

	i = -1;
	while (++i < ft_atoi(argv[1]))
	{
		philos[i].id = i + 1;
		philos[i].meals_eaten = 0;
		// philos[i].start_time = get_current_time();
		// philos[i].last_time = get_current_time();
		philos[i].inputs.num_of_philos = ft_atoi(argv[1]);
		philos[i].inputs.time_to_die = ft_atoi(argv[2]);
		philos[i].inputs.time_to_eat = ft_atoi(argv[3]);
		philos[i].inputs.time_to_sleep = ft_atoi(argv[4]);
		if (argv[5])
			philos[i].inputs.num_times_to_eat = ft_atoi(argv[5]);
		else
			philos[i].inputs.num_times_to_eat = -1;
		philos[i].left_fork = &forks[i];
		// felsefeciler soldan sağa doğru sıralanıyor ve çatallarını bu sıraya göre paylaşıyorlar.
		if (i == 0)			// İlk filozofun sağ çatalı son filozofun sol çatalı olmalıdır. 
			philos[i].right_fork = &forks[philos[i].inputs.num_of_philos - 1];
		else				// kendisinden önceki felsefecinin sol çatalı olacaktır.
			philos[i].right_fork = &forks[i - 1];
		philos[i].write_lock = &sim->write_lock;
		philos[i].meal_lock = &sim->meal_lock;
	}
}
