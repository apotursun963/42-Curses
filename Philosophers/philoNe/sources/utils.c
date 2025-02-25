/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:10:27 by atursun           #+#    #+#             */
/*   Updated: 2025/02/25 22:45:16 by atursun          ###   ########.fr       */
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

/*
Bu fonksiyon, filozof simülasyonu sona erdiğinde kullanılan mutex kilitlerini 
temizler ve serbest bırakır.
*/
void	destroy_mutexes(t_simulation *sim, t_mutex *forks, int num_of_philo)
{
	while (--num_of_philo >= 0)
		pthread_mutex_destroy(&forks[num_of_philo]);
	pthread_mutex_destroy(&sim->write_lock);
	pthread_mutex_destroy(&sim->meal_lock);
	pthread_mutex_destroy(&sim->dead_lock);
}

/*
Bu fonksyon, sağladığından daha hassas zamanlama ve daha az CPU kullanımı sağlar.
Bu bu fonsiyon yerine direkt olarak usleep fonksiyonu kullanabilirdim ama 
benim "geçen zamanı" kontrol etmem gerekiyor.
Bu fonksiyon, Belirli bir süre boyunca (milisaniye cinsinden) beklerken, get_current_time() 
fonksiyonu kullanılarak geçen süre takip edilir ve sürekli kısa beklemelerle (usleep(500)) 
daha verimli bir bekleme yapılır.
*/
void	ft_usleep(int mls)
{
	int	start;

	start = get_current_time();
	while ((get_current_time() - start) < mls)
		usleep(500);
}

// Bu fonksiyon, sistemin geçerli zamanını "milisaniye" cinsinden almak için kullanılır. 
// "sistemin geçerli zamanını": sistemin başlangıcından itibaren geçen süreyi ifade eder.
// Dönüş değeri olarak "milisaniye" cinsinden bir int değerini döndürür.
int	get_current_time(void)
{
	struct timeval	time;	// bu değişken zaman bilgisini tutmak için kullanılır.

	// Bu fonksiyon, sistemdeki geçerli zamanı almak için kullanılır.
	// &time: Geçerli zamanı bu adrese yazdırır. Bu, saniye (tv_sec) ve mikrosaniye (tv_usec) bilgilerini içerir.
	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);		// Elde edilen Zamanı milisaniyeye dönüştür
	// Sonuç olarak, saniye ve mikrosaniye cinsinden olan zaman, milisaniye cinsine çevrilmiş olur.
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
