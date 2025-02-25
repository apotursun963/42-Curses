/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:10:06 by atursun           #+#    #+#             */
/*   Updated: 2025/02/25 18:28:52 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

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

/*
Çatalların her birini mutex ile init ettik. Bunun nedeni, çatalların paylaşılan kaynaklar olması
ve aynı anda yalnızca bir filozof tarafından kullanılabilmesi gerektiğidir.
Filozoflar yemek yemek için iki çatal (fork) almak zorundadır: biri solunda, diğeri sağında.
Ancak bir çatal aynı anda yalnızca bir filozofun elinde olabilir.
Eğer mutex kullanılmazsa, iki filozof aynı çatalı aynı anda alabilir ve sistem hatalı çalışabilir.
*/
static void	init_forks(t_mutex *forks, int philo_num)
{
	int	i;

	i = -1;
	while (++i < philo_num)
		pthread_mutex_init(&forks[i], NULL);
}

static void	init_simulation(t_simulation *sim, t_philo *philos)
{
	sim->dead_falg = 0;
	sim->philos = philos;

	// Filozofların bilgilerni ekrana yazarken çıktının karışmasını önlemek için kullanılır. 
	pthread_mutex_init(&sim->write_lock, NULL);

	// Filozofların son yemek yeme zamanını güvenli bir şekilde güncellemek için kullanılır.
	pthread_mutex_init(&sim->meal_lock, NULL);

	pthread_mutex_init(&sim->dead_lock, NULL);
}
// sdfdfl
static int inspect_args(int argc, char **argv)
{
	int i;

	if (argc != 5 && argc != 6)
		return (0);
	if (ft_atoi(argv[1]) > NUMBER_OF_PHILO)
		return (0);
	i = 0;
	while (++i < argc)
	{
		if (ft_atoi(argv[i]) <= 0)
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_simulation	simulation;
	t_philo			philos[NUMBER_OF_PHILO];
	t_mutex			forks[NUMBER_OF_PHILO];

	if (inspect_args(argc, argv))
	{
		init_simulation(&simulation, philos);
		init_forks(forks, ft_atoi(argv[1]));
		init_philos(&simulation, philos, forks, argv);
		create_threads(&simulation);
		finish_all(&simulation, forks, philos[0].philo_count);
	}
	return (0);
}
