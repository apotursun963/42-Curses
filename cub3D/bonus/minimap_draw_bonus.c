/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_draw_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:56:59 by mikkayma          #+#    #+#             */
/*   Updated: 2025/07/18 12:04:08 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

/* Bu fonksiyon, haritadaki her bir hücrenin rengini belirler:
- Duvarlar ('1'): Açık gri (0xE0E0E0)
- Geçilebilir alanlar ('0', 'N', 'S', 'E', 'W'): Orta tonda gri (0x606060)
- Kapılar ('D'): kırmızı (0x8B4513)
- Diğer karakterler: Koyu gri (0x303030)
*/
static int	color_selection(t_cub *cub, int x, int y)
{
	int	color;

	color = 0;
	if (cub->map.map[y][x] == '1')
		color = 0xE0E0E0;
	else if (cub->map.map[y][x] == '0' || cub->map.map[y][x] == 'N'
				|| cub->map.map[y][x] == 'S' || cub->map.map[y][x] == 'E'
				|| cub->map.map[y][x] == 'W')
		color = 0x606060;
	else if (cub->map.map[y][x] == 'D')
		color = 0x8B4513;
	else
		color = 0x303030;
	return (color);
}

/* Minimapte dikdörtgen şeklinde alanlar çizer
- Başlangıç koordinatları: tmp.start_x ve tmp.start_y
- Renk: tmp.color
- İç içe döngülerle belirtilen genişlik ve yükseklikte bir dikdörtgeni piksel piksel boyar
- Her piksel için my_mlx_pixel_put_for_minimap fonksiyonunu kullanır
*/
void	draw_rectangle(t_cub *cub, t_tmp tmp, int width, int height)
{
	int	x;
	int	y;

	y = tmp.start_y;
	while (y < tmp.start_y + height)
	{
		x = tmp.start_x;
		while (x < tmp.start_x + width)
		{
			my_mlx_pixel_put_for_minimap(cub, x, y, tmp.color);
			x++;
		}
		y++;
	}
}

/* Oyuncuyu minimapte görselleştirir(çizer):
- Oyuncu pozisyonunu harita koordinatlarından piksel koordinatlarına dönüştürür
- Oyuncuyu temsil eden kare boyutunu hesaplar (hücre boyutunun yarısı)
- Boyutu 3-8 piksel arasında sınırlar
- Kırmızı renkli (0xFF0000) bir kare çizer
- Oyuncunun baktığı yönü yeşil (0x00FF00) bir çizgi olarak gösterir
*/
void	draw_player_in_minimap(t_cub *cub, float dx, float dy, int pl_size)
{
	int			pl_x;
	int			pl_y;
	int			px;
	int			py;
	int			i;

	pl_x = cub->minimap.offset_x + cub->minimap.player_map_px;
	pl_y = cub->minimap.offset_y + cub->minimap.player_map_py;
	pl_size = cub->minimap.cell_size / 2;	// oyuncunun boyutu hücrenin yarısı kadar
	draw_rectangle(cub, fill_tmp(pl_x - pl_size / 2, pl_y - pl_size / 2, 0xFF0000), pl_size, pl_size);
	dx = cub->player.dirx;
	dy = cub->player.diry;
	i = 0;
	while (i < cub->minimap.cell_size + 4)
	{
		px = pl_x + (int)(dx * i);
		py = pl_y + (int)(dy * i);
		my_mlx_pixel_put_for_minimap(cub, px, py, 0x00FF00);
		i++;
	}	
}

/* Tüm minimap haritasını çizen ana fonksiyon:
- İki iç içe döngüyle haritanın tamamını tarar
- Boşluk karakterlerini (' ') atlar
- Her hücre için rengi color_selection ile belirler
- Piksel koordinatlarını hesaplar ve draw_rectangle ile çizimi yapar

- offset_x: Minimapın ekrandaki başlangıç noktası (X ekseni)
- x: Haritadaki hücrenin sütun numarası (0, 1, 2, ...)
- cell_size: Her hücrenin piksel cinsinden boyutu

---
offset_x = 50      (minimap ekranın sol kenarından 50 piksel içeride başlar)
x = 3              (haritadaki 4. sütun)
cell_size = 10     (her hücre 10x10 piksel)

mini_x = 50 + (3 × 10) = 80 piksel
*/
void	draw_minimap(t_cub *cub)
{
	int mini_x;  // Minimapteki piksel X koordinatı
	int mini_y;  // Minimapteki piksel Y koordinatı  
	int x;       // Haritadaki hücre X indeksi (sütun)
	int y;       // Haritadaki hücre Y indeksi (satır)
	int color;   // Hücrenin rengi

	color = 0;
	y = 0;
	while (y < cub->map.map_height && cub->map.map[y])
	{
		x = 0;
		while (x < (int)ft_strlen(cub->map.map[y]))
		{
			if (cub->map.map[y][x] && cub->map.map[y][x] != ' ')
			{
				color = color_selection(cub, x, y);
				mini_x = cub->minimap.offset_x + (x * cub->minimap.cell_size);
				mini_y = cub->minimap.offset_y + (y * cub->minimap.cell_size);
				draw_rectangle(cub, fill_tmp(mini_x, mini_y, color),
					cub->minimap.cell_size, cub->minimap.cell_size);
			}
			x++;
		}
		y++;
	}
}

/*Haritanın boyutlarını hesaplar
- Harita yüksekliğini (satır sayısı) bulur
- En uzun satırı belirleyerek harita genişliğini saptar
- Bu değerleri cub->map.map_width ve cub->map.map_height yapılarında saklar
*/
void	calculate_map_height_and_with(t_cub *cub)
{
	int	current_width;

	current_width = 0;
	while (cub->map.map[cub->map.map_height])
	{
		current_width = ft_strlen(cub->map.map[cub->map.map_height]);
		if (current_width > cub->map.map_width)
			cub->map.map_width = current_width;
		cub->map.map_height++;
	}
}
