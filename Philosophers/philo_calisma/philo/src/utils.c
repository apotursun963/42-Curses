/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:03:53 by atursun           #+#    #+#             */
/*   Updated: 2025/02/21 14:07:27 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	throw_error_msg(t_error msg)
{
	if (msg == WRONG_ARGUMENT_COUNT)
		printf("Wrong Argument Count\n");
	else if (msg == INVALID_PHILOS_NUMBER)
		printf("Invalid Philosophers Number\n");
	else if (msg == ARGS_MUST_BE_DIGITS)
		printf("Arguments Must Be Only Digits\n");
	return (0);
}

// Bu fonksiyonu sil
void	finish_all(t_simulation *sim, int num_of_philo)
{
	while (--num_of_philo >= 0)
		pthread_mutex_destroy(&sim->forks[num_of_philo]);
	pthread_mutex_destroy(&sim->write_lock);
	pthread_mutex_destroy(&sim->meal_lock);
}

void	print_action(t_philo *philo, char *action)
{
	int	time;	

	pthread_mutex_lock(philo->mutexes.write_lock);
	time = get_current_time() - philo->times.born_time;		// filozofun kaç milisaniyedir yaşadığını belirlemek için kullanılır.
	printf(GREEN"[%d]"RESET" %d%s\n", time, philo->id, action);
	pthread_mutex_unlock(philo->mutexes.write_lock);
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
