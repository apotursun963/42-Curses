/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:10:14 by mikkayma          #+#    #+#             */
/*   Updated: 2025/07/20 21:34:20 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* Bu fonksiyon, ekranın her sütunu için ışın özelliklerini ayarlar.
- ray_dir_x ve ray_dir_y: Işının x ve y eksenlerindeki yönlerini belirler. Oyuncunun bakış yönü ve ekrandaki konuma göre hesaplanır.
- map_x ve map_y: (Işının Yönü) Işının harita üzerinde başladığı konum (oyuncunun bulunduğu hücre).
- delta_dist_x ve delta_dist_y: Işının bir sonraki x veya y harita hücresine ulaşmak için kat etmesi gereken mesafe.
- hit: Işının bir duvara çarpıp çarpmadığını kontrol eden bayrak (0: çarpmadı, 1: çarptı).

Ray_dir_x'in ve Ray_dir_y Alabileceği Değerler: 0 (sol kenar) ve 1 (sağ kenar) 
*/
static void	setup_ray(t_cub *cub, t_render *render, int x)
{
	render->ray_dir_x = cub->player.dirx + cub->plane_x
		* (2 * x / (double)WIDTH - 1);
	render->ray_dir_y = cub->player.diry + cub->plane_y
		* (2 * x / (double)WIDTH - 1);
	render->map_x = (int)cub->player.posx;
	render->map_y = (int)cub->player.posy;
	if (render->ray_dir_x != 0)
		render->delta_dist_x = fabs(1 / render->ray_dir_x);
	else
		render->delta_dist_x = 1e30;
	if (render->ray_dir_y != 0)
		render->delta_dist_y = fabs(1 / render->ray_dir_y);
	else
		render->delta_dist_y = 1e30;
	render->hit = 0;
}

/*Bu fonksiyon, ışının harita üzerinde hangi yönde ilerleyeceğini ve başlangıç yan mesafelerini hesaplar.
step_x ve step_y: Işının harita üzerinde x ve y eksenlerinde hangi yönde ilerleyeceğini belirler (-1: negatif yön, 1: pozitif yön).
side_dist_x ve side_dist_y: Işının başlangıç noktasından ilk x veya y harita çizgisine olan mesafesi.
*/
static void	calculate_step_and_side_dist(t_cub *cub, t_render *render)
{
	if (render->ray_dir_x < 0)
	{
		render->step_x = -1;
		render->side_dist_x = (cub->player.posx - render->map_x)
			* render->delta_dist_x;
	}
	else
	{
		render->step_x = 1;
		render->side_dist_x = (render->map_x + 1.0 - cub->player.posx)
			* render->delta_dist_x;
	}
	if (render->ray_dir_y < 0)
	{
		render->step_y = -1;
		render->side_dist_y = (cub->player.posy - render->map_y)
			* render->delta_dist_y;
	}
	else
	{
		render->step_y = 1;
		render->side_dist_y = (render->map_y + 1.0 - cub->player.posy)
			* render->delta_dist_y;
	}
}

/*DDA (Dijital Diferansiyel Analiz) algoritmasını kullanarak ışının bir duvara çarpana kadar ilerlemesini sağlar.
*/
static void	perform_dda(t_cub *cub, t_render *render)
{
	while (render->hit == 0)
	{
		move_ray(render);
		if (cub->map.map[render->map_y][render->map_x] == '1')
		{
			render->hit = 1;
			render->is_door = 0;
		}
		if (BONUS && cub->map.map[render->map_y][render->map_x] == 'D')
		{
			play_door_sprite(cub, render);
			render->is_door = 1;
			render->hit = 1;
		}
	}
}

/* Duvarın oyuncuya olan mesafesini ve ekranda çizilecek duvar şeridinin yüksekliğini hesaplar.
perp_wall_dist: Duvarın oyuncuya olan dik uzaklığı (balık gözü efektini önlemek için).
line_height: Ekranda çizilecek duvar şeridinin yüksekliği.
draw_start ve draw_end: Duvar şeridinin ekranda başlangıç ve bitiş y-koordinatları.
*/
void	calculate_wall_distance_and_height(t_cub *cub, t_render *render)
{
	if (render->side == 0)
		render->perp_wall_dist = (render->map_x - cub->player.posx
				+ (1 - render->step_x) / 2) / render->ray_dir_x;
	else
		render->perp_wall_dist = (render->map_y - cub->player.posy
				+ (1 - render->step_y) / 2) / render->ray_dir_y;
	render->line_height = (int)(HEIGHT / render->perp_wall_dist);
	render->draw_start = -render->line_height / 2 + HEIGHT / 2;
	render->draw_end = render->line_height / 2 + HEIGHT / 2;
	if (render->draw_start < 0)
		render->draw_start = 0;
	if (render->draw_end >= HEIGHT)
		render->draw_end = HEIGHT - 1;
}

/*
1. Gökyüzü ve zemini boyar (painting_sky_and_ground).
2. Her sütun için:
	- Işın özelliklerini ayarlar.
	- Adım değerlerini ve yan mesafeleri hesaplar.
	- DDA algoritmasını uygular (duvar bulana kadar).
	- Duvar mesafesi ve yüksekliğini hesaplar.
	- Uygun dokuyu seçer (select_texture).
	- Dokuyu çizer (draw_texture).
3. Oluşturulan görüntüyü pencereye aktarır.
*/
void	render_map(t_cub *cub)
{
	t_render	render;
	int			x;

	x = 0;
	painting_sky_and_ground(cub);
	while (x < WIDTH)
	{
		render.is_door = 0;
		setup_ray(cub, &render, x);
		calculate_step_and_side_dist(cub, &render);
		perform_dda(cub, &render);
		calculate_wall_distance_and_height(cub, &render);
		select_texture(cub, &render);
		draw_texture(cub, &render, x, 0);
		x++;
	}
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win, \
		cub->mlx.win_data.image, 0, 0);
}
