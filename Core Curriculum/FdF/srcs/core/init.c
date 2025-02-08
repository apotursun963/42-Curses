/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:00:25 by atursun           #+#    #+#             */
/*   Updated: 2025/02/08 17:19:28 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

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
		return (0);
	fdf->map = read_map(file_name);
	if (!fdf->map)
	{
		free(fdf);
		return (0);
	}
	fdf->mlx = mlx_init();
	fdf->win_x = WIDTH;
	fdf->win_y = HEIGHT;
	fdf->win = mlx_new_window(fdf->mlx, fdf->win_x, fdf->win_y, NAME);
	fdf->image = init_image(fdf->mlx);
	if (!fdf->image)
		free_map(fdf);
	fdf->cam = init_cam(fdf->map);
	if (!fdf->cam)
		free_all(fdf);
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

pitch, yaw, roll
3D uzayda bir nesnenin dönüş (rotate) hareketlerini tanımlayan üç temel eksen etrafındaki açılardır.
X Ekseni → Sağdan sola yatay eksen
Y Ekseni → Önden arkaya dikey eksen
Z Ekseni → Yukarıdan aşağıya derinlik ekseni

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
	cam->scale_z = 1;			// Z ekseni ölçek faktörü varsayılan olarak 1 olarak ayarlanır
	cam->move_x = WIDTH / 2;	// Kamera başlangıçta ekranın ortasına hizalanır
	cam->move_y = HEIGHT / 2;
								// Dönme Açılarının Başlangıç Değerlerini Belirleme
								// Eğer kullanıcı haritayı döndürmek isterse bu açılar değiştirilir.
	cam->alpha = 0;				// alpha -> X ekseni etrafında dönüş (pitch)
	cam->beta = 0;				// beta -> y ekseni etrafında dönüş (yaw)
	cam->gamma = 0;				// gamma -> < ekseni etrafında dönüş (roll)
	return (cam);
}

/*
Başlangıç ve bitiş noktalarını alarak bir doğru nesnesi (t_line) oluşturur.
*/
t_line	*init_line(t_point start, t_point end, t_fdf *fdf)
{
	t_line	*line;

	line = malloc(sizeof(t_line));
	if (!line)
		return (NULL);
	// Başlangıç Noktasının (start) Özelliklerini Kopyalama
	line->start.x = start.x;
	line->start.y = start.y;
	line->start.z = start.z;
	line->start.color = start.color;
	// Bitiş Noktasının (end) Özelliklerini Kopyalama 
	line->end.x = end.x;
	line->end.y = end.y;
	line->end.z = end.z;
	line->end.color = end.color;
	// Z Eksenindeki Dönüşüm Değerinin Hesaplanması
	/*
	transform_z, doğru çizimini ekran boyutlarına sığdırmak ve uygun bir ölçeklendirme yapmak için kullanılır.
	Haritanın Z eksenindeki yüksekliği heaplanır.
	Aynı zamanda haritanın X ve Y boyutlarının maksimum değeri bulunur.
	transform_z, bu iki değerin maksimum değeri olarak belirlenir.
	*/
	line->transform_z = max((fdf->map->max_z - fdf->map->min_z), \
		max(fdf->map->max_x, fdf->map->max_y));
	return (line);
}
