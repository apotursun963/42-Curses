/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 17:30:45 by mikkayma          #+#    #+#             */
/*   Updated: 2025/07/25 12:55:50 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	painting_sky_and_ground(t_cub *cub)
{
	int	total_pixels;
	int	i;
	int	x;
	int	y;

	i = 0;
	total_pixels = WIDTH * HEIGHT;
	while (i < total_pixels)
	{
		x = i % WIDTH;
		y = i / WIDTH;
		if (y < HEIGHT / 2)
			my_mlx_pixel_put(cub, x, y, cub->fc.ceiling_c.colour);
		else
			my_mlx_pixel_put(cub, x, y, cub->fc.floor_c.colour);
		i++;
	}
}

void	select_texture(t_cub *cub, t_render *render)
{
	if (BONUS && render->is_door == 1)
		return ;
	if (render->side == 0 && render->ray_dir_x > 0)
		render->selected_texture = &cub->east;
	else if (render->side == 0 && render->ray_dir_x < 0)
		render->selected_texture = &cub->west;
	else if (render->side == 1 && render->ray_dir_y > 0)
		render->selected_texture = &cub->south;
	else
		render->selected_texture = &cub->north;
}

void	move_ray(t_render *render)
{
	if (render->side_dist_x < render->side_dist_y)
	{
		render->side_dist_x += render->delta_dist_x;
		render->map_x += render->step_x;
		render->side = 0;
	}
	else
	{
		render->side_dist_y += render->delta_dist_y;
		render->map_y += render->step_y;
		render->side = 1;
	}
}
