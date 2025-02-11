/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:01:02 by atursun           #+#    #+#             */
/*   Updated: 2025/02/11 15:00:52 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

/*
Bu fonksiyon, bir renk geçişi hesaplar. 
Renk, RGB (kırmızı, yeşil, mavi) bileşenlerinden oluşur ve her 
bileşen için bir değişim (delta) miktarı vardır. 
progress parametresi, 
renk geçişinin ne kadar ilerlediğini belirten bir orandır (0 ile 1 arasında bir değer). 
Bu oran, başlangıç renginden hedef renge doğru yapılan geçişin miktarını belirler.
bir renk genellikle 24 bit ile temsil edilir. 8 bit * 3 = 24 bit (24-bit renk)
*/
int	color_gradient(t_color *color, float progress)
{
	int	red;
	int	green;
	int	blue;

	// delta_r (kırmızı bileşeninin değişim miktarı) ile geçiş oranı (progress) çarpılır 
		// ve kırmızı bileşenin yeni değeri hesaplanır.
	red = color->delta_r * progress;
	if (red < -255)
		red = 0;
	else if (red > 255)
		red = 255;
	red = red << 16;			// 16 bit sola kaydiriliyor
	green = color->delta_g * progress;
	if (green < -255)
		green = 0;
	else if (green > 255)
		green = 255;
	green = green << 8;
	blue = color->delta_b * progress;
	if (blue < -255)
		blue = 0;
	else if (blue > 255)
		blue = 255;
	return (color->start_color + red + green + blue);	// yeni renk degeri return ediliyor
}

/*
get_color fonksiyonu, bir renk geçişi oranı hesaplamak için kullanılır 
ve belirli bir satır için renk değerini elde eder.
i_line parametresi, şu anda işlenen satırın numarasını temsil eder, 
line_size ise toplam satır (adım) /piksel sayısını ifade eder. 
Bu oran, o satırın geçişin ne kadar ilerlediğini belirtir.
*/
int	get_color(t_color *color, int i_line, int line_size)
{
	float	progress;

	progress = (float)i_line / (float)line_size;
	return (color_gradient(color, progress));
}

t_color	*color_init(t_point start, t_point end)
{
	t_color	*color;

	color = malloc(sizeof(t_color));
	if (!color)
		return (NULL);
	color->start_color = start.color;
	color->start_r = (RED & start.color) >> 16;		// RED & start.color: 0xFF0000 & 0xFF5733 = 0xFF0000 >> 16 = 0xFF (kırmızı)
	color->start_g = (GREEN & start.color) >> 8;
	color->start_b = (BLUE & start.color);
	
	color->end_color = end.color;
	color->end_r = (RED & end.color) >> 16;
	color->end_g = (GREEN & end.color) >> 8;
	color->end_b = (BLUE & end.color);

	color->delta_r = (color->end_r - color->start_r);
	color->delta_g = (color->end_g - color->start_g);
	color->delta_b = (color->end_b - color->start_b);
	return (color);
}

/*
Bu fonksiyon, iki renk (başlangıç ve bitiş renkleri) arasındaki farkları hesaplayan bir yapı (t_color) başlatır. 
min_color ve max_color değerlerini alarak, her iki rengin kırmızı, yeşil ve mavi bileşenlerini ayrıştırır. 
Ardından, bu bileşenler arasındaki farkları (delta) hesaplar. 
Fonksiyon, başlangıç ve bitiş renkleri ile bu farkları içeren bir t_color yapısını döndürür.
Bu yapı, renk geçişleri veya animasyonları için kullanılabilir.
*/
t_color	*color_pallet_init(int min_color, int max_color)
{
	t_color	*color;

	color = malloc(sizeof(t_color));
	if (!color)
		return (NULL);

	color->start_color = min_color;
	color->start_r = (RED & min_color) >> 16;		// RED & min_color: 0xFF0000 & 0xFF5733 = 0xFF0000 >> 16 = 0xFF (kırmızı)
	color->start_g = (GREEN & min_color) >> 8;
	color->start_b = (BLUE & min_color);

	color->end_color = max_color;
	color->end_r = (RED & max_color) >> 16;
	color->end_g = (GREEN & max_color) >> 8;
	color->end_b = (BLUE & max_color);

	color->delta_r = (color->end_r - color->start_r);
	color->delta_g = (color->end_g - color->start_g);
	color->delta_b = (color->end_b - color->start_b);
	return (color);
}
