/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_render_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:29:21 by mikkayma          #+#    #+#             */
/*   Updated: 2025/07/25 12:57:36 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

void	draw_floor_and_ceiling(t_cub *cub, int x, int y)
{
	if (y < HEIGHT / 2)
		my_mlx_pixel_put(cub, x, y, cub->fc.ceiling_c.colour);
	else
		my_mlx_pixel_put(cub, x, y, cub->fc.floor_c.colour);
}

int	calculate_the_walls_behind_the_door(t_cub *cub, t_render bg_render, int y)
{
	double	bg_step;
	double	bg_tx_pos;
	int		bg_tex_y;
	int		bg_tex_x;
	double	w_x;

	bg_step = 1.0 * bg_render.selected_texture->tex_height
		/ bg_render.line_height;
	bg_tx_pos = (y - HEIGHT / 2 + bg_render.line_height / 2) * bg_step;
	bg_tex_y = (int)bg_tx_pos & (bg_render.selected_texture->tex_height - 1);
	if (bg_render.side == 0)
		w_x = cub->player.posy + bg_render.perp_wall_dist * bg_render.ray_dir_y;
	else
		w_x = cub->player.posx + bg_render.perp_wall_dist * bg_render.ray_dir_x;
	w_x -= floor(w_x);
	bg_tex_x = (int)(w_x * (double)bg_render.selected_texture->tex_width);
	if (bg_render.side == 0 && bg_render.ray_dir_x < 0)
		bg_tex_x = bg_render.selected_texture->tex_width - bg_tex_x - 1;
	if (bg_render.side == 1 && bg_render.ray_dir_y > 0)
		bg_tex_x = bg_render.selected_texture->tex_width - bg_tex_x - 1;
	return (*(unsigned int *)(bg_render.selected_texture->texture_data
		+ (bg_tex_y * bg_render.selected_texture->size_line + bg_tex_x
			* (bg_render.selected_texture->bits_per_pixel / 8))));
}
