/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 11:25:47 by atursun           #+#    #+#             */
/*   Updated: 2025/07/14 11:25:47 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	rotate_player(t_cub *cub, double angle)
{
	double	old_dirx;
	double	old_planex;

	old_planex = cub->plane_x;
	old_dirx = cub->player.dirx;
	cub->player.dirx = \
		cub->player.dirx * cos(angle) - cub->player.diry * sin(angle);
	cub->player.diry = old_dirx * sin(angle) + cub->player.diry * cos(angle);
	cub->plane_x = cub->plane_x * cos(angle) - cub->plane_y * sin(angle);
	cub->plane_y = old_planex * sin(angle) + cub->plane_y * cos(angle);
}

int	is_valid_position(t_cub *cub, double x, double y)
{
	double	radius;
	double	dx;
	double	dy;
	int		check_x;
	int		check_y;

	radius = 0.2;
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
			dy += 0.1;
		}
		dx += 0.1;
	}	
	return (1);
}

static int	game_loop(t_cub *cub)
{
	move_player(cub);
	render_map(cub);
	if (BONUS)
	{
		minimap(cub);
		update_fps(cub);
		draw_fps(cub);
	}
	return (0);
}

void	init_movement_state(t_cub *cub)
{
	cub->move_forward = 0;
	cub->move_backward = 0;
	cub->move_left = 0;
	cub->move_right = 0;
	cub->rotate_left = 0;
	cub->rotate_right = 0;
	cub->mouse_rotate_left = 0;
	cub->mouse_rotate_right = 0;
}

void	setup_hooks(t_cub *cub)
{
	mlx_hook(cub->mlx.win, 2, 1L << 0, handle_keypress, cub);
	mlx_hook(cub->mlx.win, 3, 1L << 1, handle_keyrelease, cub);
	if (BONUS)
		mlx_hook(cub->mlx.win, 6, 1L << 6, handle_mouse_move, cub);
	mlx_hook(cub->mlx.win, 33, 0L, handle_close, cub);
	mlx_loop_hook(cub->mlx.mlx, game_loop, cub);
}
