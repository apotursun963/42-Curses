/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikkayma <mikkayma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 12:41:34 by mikkayma          #+#    #+#             */
/*   Updated: 2025/07/11 13:12:28 by mikkayma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	handle_mouse_move(int x, int y, t_cub *cub)
{
	static int	prev_x;
	double		rotation_speed;

	(void)y;
	prev_x = WIDTH / 2;
	rotation_speed = ROT_SPEED;
	if (x > prev_x)
		rotate_player(cub, rotation_speed * (x - prev_x) / 13);
	else if (x < prev_x)
		rotate_player(cub, -rotation_speed * (prev_x - x) / 13);
	prev_x = WIDTH / 2;
	mlx_mouse_move(cub->mlx.mlx, cub->mlx.win, WIDTH / 2, HEIGHT / 2);
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
