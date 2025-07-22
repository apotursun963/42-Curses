/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:08:37 by mikkayma          #+#    #+#             */
/*   Updated: 2025/07/22 11:51:09 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
Bu fonksiyon, oyuncunun başlangıç pozisyonundan başlayarak haritada 
ulaşılabilir tüm alanları işaretler. 
Eğer algoritma sırasında harita sınırının dışına çıkarsa veya 
boşluk/tab karakterine rastlarsa, 
bu haritanın düzgün duvarlarla çevrilmediği anlamına gelir ve hata verir.
*/
static void	flood_fill(char **map_copy, int x, int y, int *error)
{
	if (y < 0 || x < 0)		// Sınır Kontrolleri
	{
		*error = 1;
		return ;
	}
	if (!map_copy[y] || x >= (int)ft_strlen(map_copy[y]))	// X, o satırın uzunluğundan büyükse
	{
		*error = 1;
		return ;
	}
	if (map_copy[y][x] == ' ' || map_copy[y][x] == '\t')
	{
		*error = 1;
		return ;
	}
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'X')
		return ;
	map_copy[y][x] = 'X';	// DAHA ÖNCE GEÇTİĞİMİZ YERLERİ X koyuyoruz
	/*
	Sağ, sol, aşağı, yukarı yönlere recursive olarak git
	Her yöne aynı flood fill algoritmasını uygula
	*/
	flood_fill(map_copy, x + 1, y, error);	// SAĞ
	flood_fill(map_copy, x - 1, y, error);	// SOL
	flood_fill(map_copy, x, y + 1, error);	// AŞAĞI
	flood_fill(map_copy, x, y - 1, error);	// YUKARI
}

static char	**create_map_copy(t_cub *cub)
{
	char	**copy;
	int		i;
	int		height;

	height = get_num_lines(cub->map.map);
	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(cub->map.map[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[height] = NULL;
	return (copy);
}

// haritanın tamamı duvarlarla çevrilimi
void	check_map_around_wall(t_cub *cub)
{
	char	**map_copy;
	int		error;

	map_copy = create_map_copy(cub);
	if (!map_copy)
		error_msg("Memory allocation failed", cub, 3);
	error = 0;
	flood_fill(map_copy, (int)cub->player.posx, (int)cub->player.posy, &error);
	free_map(map_copy);
	if (error)
		error_msg("Map is not closed/surrounded by walls", cub, 3);
}
