/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:11:11 by mikkayma          #+#    #+#             */
/*   Updated: 2025/07/20 16:47:27 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

/*Minimap görüntü tamponuna (buffera / adrese) tek bir piksel çizer:
- Koordinatların geçerli olup olmadığını kontrol eder
- Görüntü tamponundaki ilgili bellek adresini hesaplar
- Belirtilen renk değerini o adrese yazar
*/
void	my_mlx_pixel_put_for_minimap(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= MINIMAP_WIDTH || y < 0 || y >= MINIMAP_HEIGHT)
		return ;
	dst = cub->minimap.data;
	dst += (y * cub->minimap.size_line + x * (cub->minimap.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/* 
Bu fonksiyon, minimap görüntüleme pozisyonunu düzenler. 
Yani haritanın minimap penceresi içinde nerede görüntüleneceğini belirler. 
Harita boyutuna bağlı olarak, haritayı ortalar veya görüş alanının sınırlar 
içinde kalmasını sağlar.
- Haritanın toplam piksel boyutlarını hesaplar
- Harita minimap penceresinden küçükse, haritayı ortalar
- Harita büyükse, görünüm alanının sınırlar içinde kalmasını sağlar
*/
static void	check_minimap(t_cub *cub)
{
	int	total_map_pixel_width;
	int	total_map_pixel_height;

	total_map_pixel_width = cub->map.map_width * cub->minimap.cell_size;
	total_map_pixel_height = cub->map.map_height * cub->minimap.cell_size;
	if (total_map_pixel_width < MINIMAP_WIDTH)		// haritanın genişliği pencerenin genişliğinden küçükse
		cub->minimap.offset_x = (MINIMAP_WIDTH - total_map_pixel_width) / 2;	// yatay olarak ortala (kaydır)
	else
	{
		if (cub->minimap.offset_x > 0)	// eğer genişlik olarak harita ortada değilse 
			cub->minimap.offset_x = 0;	// haritayı pencereye ortala 
		if (cub->minimap.offset_x < MINIMAP_WIDTH - total_map_pixel_width)	// haritanın sağ sınırına (genişlik sınırının) geldiğinde kaydırmsaını engelliyor
			cub->minimap.offset_x = MINIMAP_WIDTH - total_map_pixel_width;
	}
	if (total_map_pixel_height < MINIMAP_HEIGHT)	// haritanın yüksekliği pencerenin yüksekliğinden küçükse
		cub->minimap.offset_y = (MINIMAP_HEIGHT - total_map_pixel_height) / 2;	// dikey olarak ortala (kaydır)
	else
	{
		if (cub->minimap.offset_y > 0)	// eğer yükseklik olarak harita ortada değilse 
			cub->minimap.offset_y = 0;	// haritayı pencereye ortala 
		if (cub->minimap.offset_y < MINIMAP_HEIGHT - total_map_pixel_height)	// haritanın aşağı sınırına (yükseklik sınırının) geldiğinde kaydırmsaını engelliyor
			cub->minimap.offset_y = MINIMAP_HEIGHT - total_map_pixel_height;
	}
}

t_tmp	fill_tmp(int start_x, int start_y, int color)
{
	t_tmp	tmp;

	tmp.color = color;
	tmp.start_x = start_x;
	tmp.start_y = start_y;
	return (tmp);
}

/* Ana fonksiyon
- mapin genişlik ve yüksekliğini hesaplar
- Oyuncunun minimap koordinatlarını belirler
- Görüntü ofsetlerini ayarlar (oyuncuyu merkezde tutmak için)
- Minimapın sınırlarını kontrol eder
- Çerçeveyi, haritayı ve oyuncuyu sırayla çizer
- Tamamlanan minimap görüntüsünü ana pencereye yerleştirir

Ne yapıyor
Oyuncunun haritadaki yatay (X) konumunu piksel koordinatlarına dönüştürüyor
- cub->player.posx: Oyuncunun haritadaki X koordinatı (harita hücresi biriminde)
- cub->minimap.cell_size: Minimapta bir harita karesinin piksel cinsinden boyutu
- cub->minimap.player_map_px: Oyuncunun minimapta piksel cinsinden X pozisyonu

Ne Yapıyor
Oyuncuyu minimapın merkezi olarak konumlandırmak için gerekli X ofsetini hesaplıyor (haritayı kaydırıyor)
- cub->minimap.offset_x, minimap görüntüleme sisteminde kullanılan yatay kaydırma değeridir
*/
void	minimap(t_cub *cub)
{
	calculate_map_height_and_with(cub);
	
	/*Koordinat sistemi dönüşümü yapılıyor:
	Harita koordinat sisteminden (hücre birimi) → Minimap piksel sistemine dönüştürülüyor
	Örnek: posx = 5.3 hücre × 10 piksel/hücre = 53 piksel pozisyonu
	*/
	cub->minimap.player_map_px = cub->player.posx * cub->minimap.cell_size;
	cub->minimap.player_map_py = cub->player.posy * cub->minimap.cell_size;
	
	cub->minimap.offset_x = (MINIMAP_WIDTH / 2) - cub->minimap.player_map_px;
	cub->minimap.offset_y = (MINIMAP_HEIGHT / 2) - cub->minimap.player_map_py;
	check_minimap(cub);
	draw_rectangle(cub, fill_tmp(0, 0, 0x000000), MINIMAP_WIDTH, MINIMAP_HEIGHT);	// minimapin içini siyaha boyar
	draw_minimap(cub);
	draw_player_in_minimap(cub, 0, 0, 0);
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win,
		cub->minimap.mini_image, 10, 10);
}
