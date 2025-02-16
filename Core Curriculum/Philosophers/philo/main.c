/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:44:04 by atursun           #+#    #+#             */
/*   Updated: 2025/02/13 12:44:04 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/* diğer dosyalarda kullanmadığın fonksiyonların başına static koy 
Bu projede, her filozof bir iş parçacığı (thread) olarak oluşturulacak ve 
her bir filozofun kullanacağı çatallar, mutex ile korunacaktır. 
Bu sayede her filozof yalnızca bir çatala aynı anda erişebilir.


KURALLAR
--------
- Bir yuvarlak masa etrafında oturan filozoflar var.
- Ortada büyük bir spagetti tabağı bulunuyor.
- Filozoflar 3 farklı durumdadır: Düşünme, yeme, uyuma.
- Filozoflar yemek yiyebilmek için iki çatal almak zorundadır.
- Masanın üzerinde, filozof sayısı kadar çatal bulunmaktadır.
- Bir filozof, ancak hem sağındaki hem solundaki çatalı aldığında yemek yiyebilir.
- Bir filozof yemek yedikten sonra çatalını bırakıp uyur ve sonra tekrar düşünmeye başlar.
- Bir filozof, belirlenen süre boyunca yemek yiyemezse açlıktan ölür ve simülasyon sona erer.

Proje Adımları
1. Thread ve Mutex kavramlarını güzel bir şekilde öğren ve egzersizler yap
2. Philosopher projesinin ne olduğunu öğren / problemi iyice kavra (Dining Problem)
3. Kodu yaz
*/




void	init_all(t_simulation *simulation, t_philosopher *philos, t_mutex *forks, int num_of_philo)
{
	int i;

	i = -1;
	simulation->philos = philos;
	simulation->forks = forks;
	pthread_mutex_init(&simulation->meal_lock, NULL);
	pthread_mutex_init(&simulation->write_lock, NULL);
	while (++i < num_of_philo)
	{
		pthread_mutex_init(&forks[i], NULL);
		philos[i].id = i + 1;
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		philos[i].start_time = get_current_time();
		philos[i].last_meal = get_current_time();
		philos[i].left_fork = &forks[i];
		if (i == 0)
			philos[i].right_fork = &forks[num_of_philo - 1];
		else
			philos[i].right_fork = &forks[i - 1];
		philos[i].simulation.meal_lock = &simulation->meal_lock;
		philos[i].simulation.write_lock = &simulation->write_lock;
	}
}

int inspect_args(int argc, char **argv)
{
	int i;

	if (ft_atoi(argv[1]) > NUMBER_OF_PHILO)
		return (throw_error_msg(INVALID_PHILOS_NUMBER), 0);
	i = -1;
	while (++i < argc)
	{
		if (ft_atoi(argv[i]) <= 0)
			return (throw_error_msg(ARGS_CANT_NEGATIVE_OR_ZERO), 0);
	}
	return (1);
}

https://github.com/dpetrosy/42-Philosophers
int main(int argc, char **argv)
{
	t_simulation	simulation;
	t_philosopher	philos[NUMBER_OF_PHILO];
	t_mutex			forks[NUMBER_OF_PHILO];

	if (argc != 5 && argc != 6)
		return (throw_error_msg(WRONG_ARGUMENT_COUNT), 0);
	if (inspect_args(argc, argv))
	{
		// bunlar için ayrı bir fonksiyon uygula
		philos->inputs.num_of_philos = ft_atoi(argv[1]);
		philos->inputs.time_to_die = ft_atoi(argv[2]);
		philos->inputs.time_to_eat = ft_atoi(argv[3]);
		philos->inputs.time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			philos->inputs.num_times_to_eat = ft_atoi(argv[5]);
		else
			philos->inputs.num_times_to_eat = -1;
		init_all(&simulation, &philos, &forks, philos->inputs.num_of_philos);
	}
	return (0);
}

/*
		kodu tekrardan yaz 
*/
