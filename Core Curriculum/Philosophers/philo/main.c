/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:04:12 by atursun           #+#    #+#             */
/*   Updated: 2025/02/17 17:32:53 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philos(t_simulation *sim, t_philo *philos, t_mutex *forks, char **argv)
{
	int	i;

	i = -1;
	while (++i < ft_atoi(argv[1]))
	{
		philos[i].id = i + 1;
		philos[i].meals_eaten = 0;
		philos[i].philo_count = ft_atoi(argv[1]);
		philos[i].times.die = ft_atoi(argv[2]);
		philos[i].times.eat = ft_atoi(argv[3]);
		philos[i].times.sleep = ft_atoi(argv[4]);
		philos[i].times.last_meal = get_current_time();
		philos[i].times.born_time = get_current_time();
		if (argv[5])
			philos[i].must_eat = ft_atoi(argv[5]);
		else
			philos[i].must_eat = -1;
		philos[i].mutexes.left_fork = &forks[i];
		if (i == 0)
			philos[i].mutexes.right_fork = &forks[philos[i].philo_count - 1];
		else
			philos[i].mutexes.right_fork = &forks[i - 1];
		philos[i].mutexes.write_lock = &sim->write_lock;
		philos[i].mutexes.meal_lock = &sim->meal_lock;
	}
}

static void	init_forks(t_simulation *sim, t_mutex *forks, int count)
{
	int	i;

	i = -1;
	while (++i < count)
		pthread_mutex_init(&forks[i], NULL);
}

static void	init_simulation(t_simulation *sim, t_philo *philos, t_mutex *forks)
{
	sim->forks = forks;
	sim->philos = philos;
	pthread_mutex_init(&sim->write_lock, NULL);
	pthread_mutex_init(&sim->meal_lock, NULL);
}

static int inspect_args(int argc, char **argv)
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

int	main(int argc, char **argv)
{
	t_philo			philos[NUMBER_OF_PHILO];
	t_mutex			forks[NUMBER_OF_PHILO];
	t_simulation	simulation;

	if (inspect_args(argc, argv))
	{
		init_simulation(&simulation, philos, forks);
		init_forks(&simulation, forks, ft_atoi(argv[1]));
		init_philos(&simulation, philos, forks, argv);
		launcher(&simulation, philos[0].philo_count);
		finish_all(&simulation, NULL, philos[0].philo_count, 0);
	}
	return (0);
}
