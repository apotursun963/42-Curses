/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:00:25 by atursun           #+#    #+#             */
/*   Updated: 2025/02/06 13:01:49 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*
Bu fonksiyon, bir harita verisini okur, bir pencere oluşturur, 
resim ve kamera başlatır, ardından her şey başarılı bir şekilde 
başlatıldığında bu yapıyı geri döndürür.
*/
t_fdf	*init_fdf(char *file_name)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		error(3);
	fdf->map = read_map(file_name);
	if (!fdf->map)
	{
		free(fdf);
		error(4);
	}
	fdf->mlx = mlx_init();
	fdf->win_x = WIDTH;
	fdf->win_y = HEIGHT;
	fdf->win = mlx_new_window(fdf->mlx, fdf->win_x, fdf->win_y, NAME);
	fdf->image = init_image(fdf->mlx);
	if (!fdf->image)
		free_map(fdf, 5);
	fdf->cam = init_cam(fdf->map);
	if (!fdf->cam)
		free_all(fdf, 6);
	return (fdf);
}

/*
Bu fonksiyon, bir harita nesnesi (t_map) oluşturur ve harita için başlangıç 
değerlerini ayarlar. Koordinatlar NULL olarak başlatılır ve harita boyutları 
ve yükseklik değerleri sıfırlanır. Fonksiyon başarılı bir şekilde oluşturulan 
harita nesnesini döndürür.
max_x, max_y: Haritanın en geniş ve en uzun boyutları.
max_z, min_z: Haritanın en yüksek ve en düşük Z koordinatları (yükseklik değerleri).
*/
t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->coordinates = NULL;
	map->max_x = 0;
	map->max_y = 0;
	map->max_z = 0;
	map->min_z = 0;
	return (map);
}

/*
Bu fonksiyon, MLX kütüphanesini kullanarak yeni bir resim nesnesi (t_image) oluşturur. 
Resmin verilerine (piksel, satır uzunluğu vb.) doğrudan erişim sağlamak için gerekli 
olan tüm bilgileri toplar. 
*/
t_image	*init_image(void *mlx)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	if (!image)
		return (NULL);
	image->image = mlx_new_image(mlx, WIDTH, HEIGHT);
	image->buffer = mlx_get_data_addr(image->image, &image->pixel_bits, \
			&image->line_bytes, &image->endian);
	image->line = NULL;
	return (image);
}

/*
Bu fonksiyon, bir kamera nesnesi oluşturur ve harita verilerini uygun şekilde 
görüntülemek için gerekli başlangıç ayarlarını yapar. Kameranın projeksiyon tipi, 
renk paleti, ölçek faktörü, konum ve dönüş açıları gibi özellikler belirlenir.
Fonksiyon başarılı bir şekilde bir kamera nesnesi döndürür.
*/
t_cam	*init_cam(t_map *map)
{
	t_cam	*cam;

	cam = malloc(sizeof(t_cam));
	if (!cam)
		return (NULL);
	cam->projection = ISOMETRIC;
	cam->color_pallet = FALSE;
	cam->scale_factor = scale_to_fit(map);
	cam->scale_z = 1;
	cam->move_x = WIDTH / 2;
	cam->move_y = HEIGHT / 2;
	cam->alpha = 0;
	cam->beta = 0;
	cam->gamma = 0;
	return (cam);
}

t_line	*init_line(t_point start, t_point end, t_fdf *fdf)
{
	t_line	*line;

	line = malloc(sizeof(t_line));
	if (!line)
		return (NULL);
	line->start.x = start.x;
	line->start.y = start.y;
	line->start.z = start.z;
	line->start.color = start.color;
	line->end.x = end.x;
	line->end.y = end.y;
	line->end.z = end.z;
	line->end.color = end.color;
	line->transform_z = max((fdf->map->max_z - fdf->map->min_z), \
		max(fdf->map->max_x, fdf->map->max_y));
	return (line);
}
