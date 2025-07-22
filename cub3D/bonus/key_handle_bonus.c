/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 12:41:34 by mikkayma          #+#    #+#             */
/*   Updated: 2025/07/22 12:54:17 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/*
Fare ile oyuncunun bakış açısını değiştirme (döndürme/rotate)
*/
int	handle_mouse_move(int x, int y, t_cub *cub)
{
	static int	prev_x;        // Önceki fare x pozisyonu (static - bellekte kalıcı)
	double		rotation_speed; // Dönüş hızı

	(void)y;                   // y koordinatı kullanılmıyor
	prev_x = WIDTH / 2;        // Referans noktası ekranın ortası
	rotation_speed = ROT_SPEED; // Dönüş hızı sabiti
	if (x > prev_x)		// Sağa hareket: Pozitif yönde döndürme
		rotate_player(cub, rotation_speed * (x - prev_x) / 13);		// /13 ile dönüş hızı ayarlanıyor 
	else if (x < prev_x)	// Sola hareket Negatif yönde döndürme
		rotate_player(cub, -rotation_speed * (prev_x - x) / 13);
	prev_x = WIDTH / 2;		// Fare imlecini sürekli ekranın ortasına geri taşıyor
	mlx_mouse_move(cub->mlx.mlx, cub->mlx.win, prev_x, HEIGHT / 2);
	return (0);
}

void	render_bonus(t_cub *cub)
{
	render_door(cub);
	cub->minimap.mini_image = \
		mlx_new_image(cub->mlx.mlx, MINIMAP_WIDTH, MINIMAP_HEIGHT);
	cub->minimap.data = \
		mlx_get_data_addr(cub->minimap.mini_image, \
			&cub->minimap.bits_per_pixel, &cub->minimap.size_line, \
			&cub->minimap.endian);
}
