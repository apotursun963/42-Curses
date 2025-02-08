/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:00:56 by atursun           #+#    #+#             */
/*   Updated: 2025/02/08 18:48:35 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

/*
Bu fonksiyon, Bresenham algoritması kullanarak iki nokta arasındaki doğruyu çizer. 
Renk geçişleri get_color ile yapılır ve her bir nokta için piksel ekranda yerleştirilir. 
Fonksiyon, çizgi boyunca her bir adımı hesaplayarak çizim işlemi gerçekleştirir.
*/
void	bresenham(t_fdf *fdf, t_point start, t_point end)
{
	float	x_step;
	float	y_step;
	int		max_steps;
	int		i_line;
	t_color	*color;

	/*
	çizgiyi oluşturacak iki nokta arasındaki farklar hesaplanir
	*/
	x_step = end.x - start.x;
	y_step = end.y - start.y;
	max_steps = (int)max(absolute(x_step), absolute(y_step));
	x_step /= max_steps;
	y_step /= max_steps;
	color = color_init(start, end);
	if (!color)
		free_all(fdf);
	i_line = 0;
	while (i_line < max_steps)
	{
		start.color = get_color(color, i_line++, max_steps);
		if (start.x > 0 && start.y > 0 && start.x < WIDTH && start.y < HEIGHT)
			pixel_to_image(fdf->image, start.x, start.y, start.color);
		start.x += x_step;
		start.y += y_step;
	}
	free(color);
}

/*
Bu fonksiyon, bir görüntü (image) üzerindeki belirli bir x, y koordinatındaki pikselin rengini (color) belleğe yazar.
// "endian" Byte Sıralaması: Renk verisinin bellekte nasıl saklandığını belirler.
Big Endian: En yüksek bayt önce gelir. 1
Little Endian: En düşük bayt önce gelir. 0
RGBA = ABGA
*/	
void	pixel_to_image(t_image *image, float x, float y, int color)
{
	int	pixel;

	pixel = ((int)y * image->line_bytes) + ((int)x * 4);	// Belirtilen x ve y koordinatlarındaki pikselin hafıza adresi hesaplanır.
	if (image->endian == 1)										// yani bellekteki adresi .
	{
		image->buffer[pixel + 0] = (color >> 24);
		image->buffer[pixel + 1] = (color >> 16);
		image->buffer[pixel + 2] = (color >> 8);
		image->buffer[pixel + 3] = (color);
	}
	else if (image->endian == 0)
	{
		image->buffer[pixel + 0] = (color);
		image->buffer[pixel + 1] = (color >> 8);
		image->buffer[pixel + 2] = (color >> 16);
		image->buffer[pixel + 3] = (color >> 24);
	}
}

/*
Bu fonksiyounun amaci görüntü sürekli güncelleniyor ve önceki çizimlerin 
kalmaması için clear_image fonksiyonunu çağıriliyo.
Yani görüntüye yeni bir şey çizmeden önce eski kalıntıları silmek için bu işlemi yapıyorsun.
Bu fonksiyon, bir resim (image) üzerinde tüm pikselleri sıfırlayıp, 
her pikseli belirli bir arka plan rengi ile doldurur. 
Bu, genellikle yeni bir çizim yapılmadan önce önceki içeriklerin silinmesi gerektiğinde kullanılır. 
*/
void	clear_image(t_image *image)
{
	int	x;
	int	y;

	ft_bzero(image->buffer, MAX_PIXEL);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel_to_image(image, x, y, BACK_DEF);
			x++;
		}
		y++;
	}
}
