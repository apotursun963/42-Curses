/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:00:30 by atursun           #+#    #+#             */
/*   Updated: 2025/02/11 12:31:45 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

t_point	**init_coordinates(int width, int depth)
{
	t_point	**coordinates;
	int		i;
	int		j;

	coordinates = malloc(width * sizeof(t_point *));
	if (!coordinates)
		return (NULL);
	i = 0;
	while (i < width)
	{
		coordinates[i] = malloc(depth * sizeof(t_point));
		if (!coordinates[i])
			return (NULL);
		j = 0;
		while (j < depth)
		{
			coordinates[i][j].x = 0;
			coordinates[i][j].y = 0;
			coordinates[i][j].z = 0;
			coordinates[i][j].color = 0;
			j++;
		}
		i++;
	}
	return (coordinates);
}

/*
koordinat sistemini haritanın merkezine göre sıfırlamaktır. 
Bu fonksiyon, harita koordinatlarını haritanın merkezine göre kaydırarak orijine taşır.
Orijin, koordinat sisteminde (0,0) noktası olup tüm koordinatların referans alındığı merkez noktasıdır.
Her bir noktanın x ve y koordinatlarından haritanın yarı genişliği ve yüksekliği kadar çıkarma işlemi yapılır. 
X ekseni haritanın genişliğinin yarısı kadar, Y ekseni haritanın yüksekliğinin yarısı kadar kaydırılır.
map->max_x / 2 → Haritanın x ekseni merkezini bulur.
map->max_y / 2 → Haritanın y ekseni merkezini bulur.
*/
void	center_to_origin(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->max_y)
	{
		x = 0;
		while (x < map->max_x)
		{
			map->coordinates[x][y].x -= map->max_x / 2;		// x koordinatını haritanın yatay ortalamasına göre sola kaydırıyoruz.
			map->coordinates[x][y].y -= map->max_y / 2;		// y koordinatını haritanın dikey ortalamasına göre yukarı kaydırıyoruz.
			x++;
		}
		y++;
	}
}

/*
Bu fonksiyon, haritanın boyutlarını ekranın boyutlarına sığacak şekilde ölçeklendirir. 
scale_x ve scale_y oranlarını hesaplayıp, hangisi küçükse onu seçer, 
böylece harita boyutları ekranın içine sığacak şekilde ayarlanır.
*/
float	scale_to_fit(t_map *map)
{
	float	scale_x;
	float	scale_y;
	float	scale_factor;

	scale_x = WIDTH / map->max_x;
	scale_y = HEIGHT / map->max_y;
	scale_factor = min(scale_x, scale_y);
	if (scale_factor < 4)
		return (2);
	return (scale_factor / 2);
}

void	reset(t_fdf *fdf)
{
	fdf->cam->scale_factor = scale_to_fit(fdf->map);
	fdf->cam->scale_z = 1;
	fdf->cam->move_x = WIDTH / 2;
	fdf->cam->move_y = HEIGHT / 2;
	fdf->cam->alpha = 0;
	fdf->cam->beta = 0;
	fdf->cam->gamma = 0;
}
