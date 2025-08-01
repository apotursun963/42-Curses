/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikkayma <mikkayma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:18:18 by mikkayma          #+#    #+#             */
/*   Updated: 2025/07/03 19:18:18 by mikkayma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	move_forward(t_cub *cub, double new_x, double new_y)
{
	new_x = cub->player.posx + cub->player.dirx * MOVE_SPEED;
	new_y = cub->player.posy + cub->player.diry * MOVE_SPEED;
	if (BONUS)
	{
		if (check_wall_collisions(cub, new_x, cub->player.posy, 0.2))
			cub->player.posx = new_x;
		if (check_wall_collisions(cub, cub->player.posx, new_y, 0.2))
			cub->player.posy = new_y;
	}
	else
	{
		if (is_valid_position(cub, new_x, cub->player.posy))
			cub->player.posx = new_x;
		if (is_valid_position(cub, cub->player.posx, new_y))
			cub->player.posy = new_y;
	}
}

static void	move_backward(t_cub *cub, double new_x, double new_y)
{
	new_x = cub->player.posx - cub->player.dirx * MOVE_SPEED;
	new_y = cub->player.posy - cub->player.diry * MOVE_SPEED;
	if (BONUS)
	{
		if (check_wall_collisions(cub, new_x, cub->player.posy, 0.2))
			cub->player.posx = new_x;
		if (check_wall_collisions(cub, cub->player.posx, new_y, 0.2))
			cub->player.posy = new_y;
	}
	else
	{
		if (is_valid_position(cub, new_x, cub->player.posy))
			cub->player.posx = new_x;
		if (is_valid_position(cub, cub->player.posx, new_y))
			cub->player.posy = new_y;
	}
}

static void	move_left(t_cub *cub, double new_x, double new_y)
{
	new_x = cub->player.posx + cub->player.diry * MOVE_SPEED;
	new_y = cub->player.posy - cub->player.dirx * MOVE_SPEED;
	if (BONUS)
	{
		if (check_wall_collisions(cub, new_x, cub->player.posy, 0.2))
			cub->player.posx = new_x;
		if (check_wall_collisions(cub, cub->player.posx, new_y, 0.2))
			cub->player.posy = new_y;
	}
	else
	{
		if (is_valid_position(cub, new_x, cub->player.posy))
			cub->player.posx = new_x;
		if (is_valid_position(cub, cub->player.posx, new_y))
			cub->player.posy = new_y;
	}
}

static void	move_right(t_cub *cub, double new_x, double new_y)
{
	new_x = cub->player.posx - cub->player.diry * MOVE_SPEED;
	new_y = cub->player.posy + cub->player.dirx * MOVE_SPEED;
	if (BONUS)
	{
		if (check_wall_collisions(cub, new_x, cub->player.posy, 0.2))
			cub->player.posx = new_x;
		if (check_wall_collisions(cub, cub->player.posx, new_y, 0.2))
			cub->player.posy = new_y;
	}
	else
	{
		if (is_valid_position(cub, new_x, cub->player.posy))
			cub->player.posx = new_x;
		if (is_valid_position(cub, cub->player.posx, new_y))
			cub->player.posy = new_y;
	}
}

void	move_player(t_cub *cub)
{
	double	new_x;
	double	new_y;

	new_x = 0;
	new_y = 0;
	if (cub->move_forward)
		move_forward(cub, new_x, new_y);
	if (cub->move_backward)
		move_backward(cub, new_x, new_y);
	if (cub->move_left)
		move_left(cub, new_x, new_y);
	if (cub->move_right)
		move_right(cub, new_x, new_y);
	if (cub->rotate_left)
		rotate_player(cub, -ROT_SPEED);
	if (cub->rotate_right)
		rotate_player(cub, ROT_SPEED);
	if (cub->mouse_rotate_left)
		rotate_player(cub, -ROT_SPEED);
	if (cub->mouse_rotate_right)
		rotate_player(cub, ROT_SPEED);
}
