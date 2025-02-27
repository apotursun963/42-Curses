/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:43:43 by atursun           #+#    #+#             */
/*   Updated: 2025/02/27 19:43:43 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/philo_bonus.h"

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
		philos[i].must_eat = -1;
		if (argv[5])
			philos[i].must_eat = ft_atoi(argv[5]);
		philos[i].mutexes.left_fork = &forks[i];
		philos[i].mutexes.right_fork = &forks[philos[i].philo_count - 1];	// İlk filozof, son filozofun sol çatalını alır.
		if (i != 0)		// Diğer filozoflar, önceki filozofun sol çatalını alır.
			philos[i].mutexes.right_fork = &forks[i - 1];
		philos[i].dead = &sim->dead_falg;
		philos[i].mutexes.write_lock = &sim->write_lock;
		philos[i].mutexes.meal_lock = &sim->meal_lock;
		philos[i].mutexes.dead_lock = &sim->dead_lock;
	}
}

static void	init_semaphores();







int	main(int argc, char **argv)
{
	t_simulation	simulation;
	t_philo			philos[NUMBER_OF_PHILO];
	t_mutex			forks[NUMBER_OF_PHILO];         // mutexler kullanılmayacak

	if (inspect_args(argc, argv))
	{
		init_semaphores(&simulation, philos, forks, ft_atoi(argv[1]));
		init_philos(&simulation, philos, forks, argv);
		create_threads(&simulation);
		destroy_semaphores(&simulation, forks, philos[0].philo_count);
	}
	return (0);
}
