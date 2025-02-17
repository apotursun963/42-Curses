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

Problemde, bir grup felsefeci yemek yemek için çatallar (forks) paylaşmak zorundadır. 
Aynı anda yalnızca bir çatalı tutabilirler ve her felsefeci, yemek yemek için iki çatala ihtiyacı vardır.


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
*/

size_t	get_current_time(void)
{
	typedef struct timeval	t_timeval;

	if (gettimeofday(&time, NULL) == -1)
		error_message("[gettimeofday ERROR]\n", 1);
	return (t_timeval.tv_sec * 1000 + t_timeval.tv_usec / 1000);
}
	
void 	print_action(t_philosopher *philo, char *action)
{
	int time;

	pthread_mutex_lock(philo->write_lock);
	time = get_current_time() - philo->start_time;
	printf("[%ld] %d%s\n", time, philo->id, action);
	pthread_mutex_unlock(philo->write_lock);
}

void 	write_philo_routine(t_philosopher *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_action(philo, " has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	print_action(philo, " has taken a fork");
	pthread_mutex_lock(philo->meal_lock);
	print_action(philo, " is eating");
	philo->last_time = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	SleeP(philo->inputs.time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	print_action(philo, " is sleeping");
	SleeP(philo->inputs.time_to_sleep);
	print_action(philo, " is thinking");
}

void 	*start(void *arg)
{
	t_philosopher *philo;

	philo = (t_philosopher *)arg;	// çift id olanlar için bekletme ekle
	pthread_mutex_lock(philo->meal_lock);
	philo->start_time = get_current_time();
	philo->last_time = get_current_time();
	pthread_mutex_unlock(philo->meal_lock);
	while (1)
		write_philo_routine(philo);
	return (NULL);
}


void 	execute_threads(t_simulation *sim, t_philosopher *philos, t_mutex *forks, int num_of_philos)
{
	int	i;

	i = -1;
	while (++i < num_of_philos)
		pthread_create(&sim->philos[i].thread, NULL, start, &sim->philos[i]);
	i = -1;
	while (++i < num_of_philos)
		pthread_detach(sim->philos[i].thread);
}

int main(int argc, char **argv)
{
	t_simulation	simulation;
	t_philosopher	philos[NUMBER_OF_PHILO];
	t_mutex			forks[NUMBER_OF_PHILO];

	if (argc != 5 && argc != 6)
		return (throw_error_msg(WRONG_ARGUMENT_COUNT), 0);
	if (inspect_args(argc, argv))
	{
		init_simulation(&simulation, philos, forks);
		init_forks(forks, ft_atoi(argv[1]));
		init_philos(&simulation, philos, forks, argv);
		execute_threads(&simulation, philos, forks, philos->inputs.num_of_philos);
	}
	return (0);
}
