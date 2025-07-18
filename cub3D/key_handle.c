/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikkayma <mikkayma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:17:17 by mikkayma          #+#    #+#             */
/*   Updated: 2025/07/03 19:17:17 by mikkayma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	handle_keypress(int key, t_cub *cub)
{
	if (key == KEY_ESC)
		handle_close(cub);
	if (key == KEY_W)
		cub->move_forward = 1;
	if (key == KEY_S)
		cub->move_backward = 1;
	if (key == KEY_A)
		cub->move_left = 1;
	if (key == KEY_D)
		cub->move_right = 1;
	if (key == KEY_LEFT)
		cub->rotate_left = 1;
	if (key == KEY_RIGHT)
		cub->rotate_right = 1;
	if (BONUS && key == KEY_E)
		handle_door(cub);
	return (0);
}

int	handle_keyrelease(int key, t_cub *cub)
{
	if (key == KEY_W)
		cub->move_forward = 0;
	if (key == KEY_S)
		cub->move_backward = 0;
	if (key == KEY_A)
		cub->move_left = 0;
	if (key == KEY_D)
		cub->move_right = 0;
	if (key == KEY_LEFT)
		cub->rotate_left = 0;
	if (key == KEY_RIGHT)
		cub->rotate_right = 0;
	return (0);
}

int	handle_close(t_cub *cub)
{
	if (BONUS)
		mlx_mouse_show(cub->mlx.mlx, cub->mlx.win);
	free_map(cub->map.map);
	free_texture(cub->texture);
	free_image(cub);
	if (BONUS)
	{
		mlx_destroy_image(cub->mlx.mlx, cub->minimap.mini_image);
		if (cub->doors_manager.door_len > 0)
		{
			free_door_sprite(cub);
			free(cub->doors_manager.door);
		}
	}
	if (cub->mlx.win)
		mlx_destroy_window(cub->mlx.mlx, cub->mlx.win);
	if (cub->mlx.mlx)
	{
		mlx_destroy_display(cub->mlx.mlx);
		free(cub->mlx.mlx);
	}
	free(cub);
	exit(0);
}
