/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 12:05:38 by atursun           #+#    #+#             */
/*   Updated: 2025/02/23 12:05:38 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/*
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
	while (get_current_time() - start < mls)	// Geçerli zaman ile başlama zamanının farkını alır ve bu fark, geçen süreyi temsil eder.
		usleep(500);	// Bu fonksiyon mikro saniye cinsinden bir bekleme yapar. 500 mikro saniye
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
