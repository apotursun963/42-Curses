/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 17:30:45 by mikkayma          #+#    #+#             */
/*   Updated: 2025/07/16 12:40:04 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	painting_sky_and_ground(t_cub *cub)
{
	int	total_pixels;
	int	i;
	int	x;
	int	y;

	i = 0;
	total_pixels = WIDTH * HEIGHT;
	while (i < total_pixels)
	{
		x = i % WIDTH;
		y = i / WIDTH;
		if (y < HEIGHT / 2)
			my_mlx_pixel_put(cub, x, y, cub->fc.ceiling_c.colour);
		else
			my_mlx_pixel_put(cub, x, y, cub->fc.floor_c.colour);
		i++;
	}
}

/*
Bu fonksiyon, raycasting sırasında görüntülenecek duvar için doğru dokuyu (texture) seçmekle görevlidir.
- side == 0 -> Işın dikey bir duvara çarpmışsa (sağ - sol)
- ray_dir_x > 0 -> Işın sağ doğru ilerliyorsa
- ray_dir_x < 0 -> Işın sola doğru ilerliyorsa
- side == 1 -> Işın yatay bir duvara çarpmışsa (ön - arka)
- ray_dir_y > 0 -> Işın aşağı doğru ilerliyorsa
- ray_dir_y < 0 -> Işın yukarı doğru ilerliyorsa
*/
void	select_texture(t_cub *cub, t_render *render)
{
	if (BONUS && render->is_door == 1)
		return ;
	if (render->side == 0 && render->ray_dir_x > 0)
		render->selected_texture = &cub->east;
	else if (render->side == 0 && render->ray_dir_x < 0)
		render->selected_texture = &cub->west;
	else if (render->side == 1 && render->ray_dir_y > 0)
		render->selected_texture = &cub->south;
	else
		render->selected_texture = &cub->north;
}

/*
Fonksiyon, side_dist_x ve side_dist_y değerlerini karşılaştırarak ışının bir sonraki 
adımda hangi yönde (x veya y) ilerlemesi gerektiğine karar verir.

X ekseninde ilerleme (side_dist_x < side_dist_y durumu):
Eğer x yönünde ilerleme daha kısa mesafede gerçekleşecekse, ışın önce bir x grid çizgisine çarpacak demektir.
side_dist_x değeri, bir sonraki x grid çizgisine ulaşmak için gereken mesafe kadar (delta_dist_x) arttırılır.
map_x değeri, ışının ilerleme yönüne göre (step_x, +1 veya -1) güncellenir.
side değişkeni 0 olarak ayarlanır, bu da ışının dikey bir duvara (x-yönlü duvar) çarptığını gösterir.

Y ekseninde ilerleme (side_dist_y <= side_dist_x durumu):
Eğer y yönünde ilerleme daha kısa mesafede gerçekleşecekse, ışın önce bir y grid çizgisine çarpacak demektir.
side_dist_y değeri, bir sonraki y grid çizgisine ulaşmak için gereken mesafe kadar (delta_dist_y) arttırılır.
map_y değeri, ışının ilerleme yönüne göre (step_y, +1 veya -1) güncellenir.
side değişkeni 1 olarak ayarlanır, bu da ışının yatay bir duvara (y-yönlü duvar) çarptığını gösterir.

side_dist_x ve side_dist_y: Işının mevcut konumundan bir sonraki x veya y grid çizgisine olan mesafeleri temsil eder.
delta_dist_x ve delta_dist_y: Işının bir x veya y grid çizgisinden bir sonraki grid çizgisine ulaşmak için kat etmesi gereken mesafelerdir.
map_x ve map_y: Işının şu anda üzerinde olduğu harita hücresinin koordinatlarıdır.
step_x ve step_y: Işının x ve y eksenlerinde ilerleme yönünü belirler (-1 veya +1).
side: Işının çarptığı duvarın yönünü belirten bayrak (0: x-yönlü duvar, 1: y-yönlü duvar).
*/
void	move_ray(t_render *render)
{
	if (render->side_dist_x < render->side_dist_y)
	{
		render->side_dist_x += render->delta_dist_x;
		render->map_x += render->step_x;
		render->side = 0;
	}
	else
	{
		render->side_dist_y += render->delta_dist_y;
		render->map_y += render->step_y;
		render->side = 1;
	}
}
