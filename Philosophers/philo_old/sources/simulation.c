/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:04:00 by atursun           #+#    #+#             */
/*   Updated: 2025/02/25 15:39:52 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// Bu fonksiyon, her filozofun belirli bir sayıda yemek yiyip yemediğini kontrol eder.
// Eğer, Tüm filozoflar yemek yemişse, true döner. yoksa false
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
			++ate;
		pthread_mutex_unlock(philos->mutexes.meal_lock);
	}
	if (ate == philos[0].philo_count)		// Bütün filozoflar 'must_eat' kadar yemek yemişse
	{
		pthread_mutex_lock(philos->mutexes.write_lock);
		return (true);		// Hepsi yemek yedi
	}
	return (false);		// Henüz tüm filozoflar yemek yememiştir
}

// Bu fonksiyon her filozofun yemek yeme, uyuma ve düşünme döngüsünü simüle eder.
/*
İlk olarak sol ve sağ çatallar alınır (left_fork ve right_fork).
Filozof yemek yer (bu esnada last_meal zamanı güncellenir ve yemek sayısı artırılır).
Yemek bittikten sonra, çatallar serbest bırakılır ve filozof uyur.
Son olarak, filozof düşünür.
*/
static void	philo_routine(t_philo *philo)
{
	pthread_mutex_lock(philo->mutexes.left_fork);
	print_action(philo, " has taken a fork");
	pthread_mutex_lock(philo->mutexes.right_fork);
	print_action(philo, " has taken a fork");
	pthread_mutex_lock(philo->mutexes.meal_lock);
	print_action(philo, " is eating");
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

// Bu fonksiyon, filozofları izler ve herhangi bir filozofun çok uzun süre yemek yiyip yemediğini kontrol eder.
// Her filozof için "last_meal" zamanı kontrol edilir.
// Eğer bir filozof belirli bir süreyi aşarak yemek yememişse, filozofun ölmesi gerektiği kabul edilir ve "died" mesajı yazdırılır.
// Tüm filozoflar belirli bir yemek sayısına ulaşmışsa, gözlemci durur.
/*
"get_current_time() - philos[i].times.last_meal > philos[i].times.die"
Burada, felsefecinin en son yediği yemekten bu yana geçen süre, onun hayatta kalabileceği 
süreyi aşıyor mu diye kontrol edilir. Eğer son yemek zamanından şu anki zamana kadar geçen süre, 
felsefecinin hayatta kalma süresini aşmışsa, bu durumda felsefeci ölmüş kabul edilir.
*/
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
			pthread_mutex_lock(philos->mutexes.meal_lock);
			if (get_current_time() - philos[i].times.last_meal > philos[i].times.die)	// Eğer filozof uzun süre yemek yememişse
			{
				pthread_mutex_unlock(philos->mutexes.meal_lock);
				print_action(&philos[i], RED" died"RESET);
				pthread_mutex_lock(philos->mutexes.write_lock);
				return (NULL);
			}
			pthread_mutex_unlock(philos->mutexes.meal_lock);
		}
		if (is_all_eat(philos) == true)		// Tüm filozoflar yemeklerini yedi mi kontrol edilir
			return (NULL);
	}
	return (NULL);
}

// if (philo->id % 2 == 0)
// 	ft_usleep(1);
// Bu, iki felsefecinin aynı anda aynı çatala (fork) erişmeye çalışmasını engeller.
// Eğer tüm felsefeciler aynı anda çatalları almak isterse, 
// bazı felsefeciler hiçbir zaman yemek yiyemez.
void	*start_simulation(void *ptr)
{
	t_philo	*philo;
	
	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	pthread_mutex_lock(philo->mutexes.meal_lock);
	philo->times.born_time = get_current_time();
	philo->times.last_meal = get_current_time();
	pthread_mutex_unlock(philo->mutexes.meal_lock);
	while (true)
		philo_routine(philo);
	return (NULL);
}

/*
thradlerin çalışma mantığı
--------------------------
start_simulation:
Her filozof kendi thread'inde paralel olarak çalışıyor, yemek yiyor, uyuyor ve düşünüyor.
Her filozofun doğum zamanı ve son yemek yediği zaman kaydediliyor.

check_philo_eating_time:
Ayrı bir thread (check_philo_eating_time) ise düzenli aralıklarla her bir filozofun uzun süre 
boyunca yemek yiyip yemedini kontrol ediyor.
Eğer tüm filozoflar tarafından belirtilen "meals_eaten" parametresindeki 
verilen sayının hepsi yenilmişse, program sona eriyor.
*/
void	create_threads(t_simulation *sim, t_philo *philo)
{
	t_thread	id;
	int			i;

	i = 0;
	pthread_create(&id, NULL, &check_philo_eating_time, sim->philos);
	while (i < philo[0].philo_count)
	{
		pthread_create(&sim->philos[i].thread_id, NULL,
			start_simulation, &sim->philos[i]);
		i++;
	}
	i = 0;
	pthread_join(id, NULL);
	while (i < philo[0].philo_count)
	{
		pthread_detach(sim->philos[i].thread_id);
		i++;
	}
}
