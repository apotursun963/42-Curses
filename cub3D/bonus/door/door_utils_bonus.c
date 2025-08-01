/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:04:12 by mikkayma          #+#    #+#             */
/*   Updated: 2025/07/25 12:57:40 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

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

void	check_the_door_after_the_door(t_cub *cub, t_render *render)
{
	render->hit = 1;
	render->is_door = 1;
	render->selected_texture = &cub->doors_manager.frames
	[cub->doors_manager.door
	[find_true_door(cub, render->map_x, render->map_y)]
		.door_frame];
}
