/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collisions_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikkayma <mikkayma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:48:11 by atursun           #+#    #+#             */
/*   Updated: 2025/07/11 14:10:30 by mikkayma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	check_wall_collisions(t_cub *cub, double x, double y, double radius)
{
	double	dx;
	double	dy;
	int		check_x;
	int		check_y;

	dx = -radius;
	while (dx <= radius)
	{
		dy = -radius;
		while (dy <= radius)
		{
			check_x = (int)(x + dx);
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
