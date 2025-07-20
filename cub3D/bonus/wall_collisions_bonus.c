/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collisions_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:48:11 by atursun           #+#    #+#             */
/*   Updated: 2025/07/20 16:37:09 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

/*
Bu fonksiyon, bir oyuncunun kapı veya duvara çarpışmasını önlemek için kontrol eder.
Fonksiyon, oyuncunun merkez pozisyonu etrafında kare şeklinde bir alan
tarar. -radius ile +radius arasındaki tüm noktaları kontrol eder.

Return 0: kapı veya duvar var içinden geçilemez yani oyuncu hareket ettirilmez
Return 1: kapı veya duvar yok. içinden geçilebilir yani oyuncu hareket edilebilir
- x, y: Kontrol edilecek pozisyon koordinatları
- radius: Oyuncunun çevresinde kontrol edilecek alan yarıçapı

koordinatların (x, y) double olmasının sebebi hassasiyet (Pürüzsüz hareket)
double ile oyuncu 2.3, 4.7 gibi ondalık pozisyonlarda olabilir, int ile sadece 2, 4 gibi tam sayı karelerinde hareket ederdi.
*/
int	check_wall_collisions(t_cub *cub, double x, double y, double radius)
{
	double	dx;
	double	dy;
	int		check_x;
	int		check_y;

	dx = -radius;
	while (dx <= radius)	// Çift Döngü ile Alan Tarama
	{
		dy = -radius;
		while (dy <= radius)
		{
			check_x = (int)(x + dx);	// Her döngü adımında, merkez pozisyondan dx ve dy kadar uzaklıktaki noktanın koordinatlarını hesaplar.
			check_y = (int)(y + dy);
			if (cub->map.map[check_y] && cub->map.map[check_y][check_x] == '1')
				return (0);
			if (cub->map.map[check_y] && cub->map.map[check_y][check_x] == 'D')
				if (cub->doors_manager.door
					[find_true_door(cub, check_x, check_y)].is_open == 0)
					return (0);
			dy += 0.1;
		}
		dx += 0.1;
	}	
	return (1);
}
