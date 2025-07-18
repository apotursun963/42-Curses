/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikkayma <mikkayma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:04:12 by mikkayma          #+#    #+#             */
/*   Updated: 2025/07/15 14:36:06 by mikkayma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	free_door_sprite(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (cub->doors_manager.frames[i].image)
			mlx_destroy_image(cub->mlx.mlx, cub->doors_manager.frames[i].image);
		i++;
	}
}

int	find_true_door(t_cub *cub, int x, int y)
{
	int	i;

	i = 0;
	while (i < cub->doors_manager.door_len)
	{
		if (cub->doors_manager.door[i].door_x == x
			&& cub->doors_manager.door[i].door_y == y)
			return (i);
		i++;
	}
	return (-1);
}

int	door_lenght(t_cub *cub)
{
	int	x;	
	int	y;
	int	door_len;

	y = 0;
	door_len = 0;
	while (cub->map.map[y])
	{
		x = 0;
		while (cub->map.map[y][x])
		{
			if (cub->map.map[y][x] == 'D')
				door_len++;
			x++;
		}
		y++;
	}
	return (door_len);
}

void	fill_doors_manager_struct(t_cub *cub, int i, int x, int y)
{
	cub->doors_manager.door[i].door_x = x;
	cub->doors_manager.door[i].door_y = y;
	cub->doors_manager.door[i].is_open = 0;
	cub->doors_manager.door[i].is_opening = 0;
	cub->doors_manager.door[i].is_closing = 0;
	cub->doors_manager.door[i].door_frame = 0;
}
