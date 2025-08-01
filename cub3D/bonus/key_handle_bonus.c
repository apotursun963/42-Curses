/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 12:41:34 by mikkayma          #+#    #+#             */
/*   Updated: 2025/07/25 12:45:14 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	handle_mouse_move(int x, int y, t_cub *cub)
{
	(void)y;
	if (x > WIDTH / 2)
		rotate_player(cub, ROT_SPEED * (x - WIDTH / 2) / 13);
	else if (x < WIDTH / 2)
		rotate_player(cub, -ROT_SPEED * (WIDTH / 2 - x) / 13);
	if (abs(x - WIDTH / 2) > 2)
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
