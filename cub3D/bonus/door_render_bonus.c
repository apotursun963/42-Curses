/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_render_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:27:38 by mikkayma          #+#    #+#             */
/*   Updated: 2025/07/14 11:29:32 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	render_vertical_texture(t_cub *cub, t_render *render, int x
	, int tex_x)
{
	double	step;
	double	tex_pos;
	int		color;
	int		tex_y;
	int		y;

	step = 1.0 * render->selected_texture->tex_height / render->line_height;
	tex_pos = (render->draw_start - HEIGHT
			/ 2 + render->line_height / 2) * step;
	y = render->draw_start;
	while (y < render->draw_end)
	{
		tex_y = (int)tex_pos & (render->selected_texture->tex_height - 1);
		tex_pos += step;
		color = *(unsigned int *)(render->selected_texture->texture_data
				+ (tex_y * render->selected_texture->size_line + tex_x
					* (render->selected_texture->bits_per_pixel / 8)));
		my_mlx_pixel_put(cub, x, y, color);
		y++;
	}
}

static void	draw_wall_texture_for_door_back(t_cub *cub, t_render *render
	, int x)
{
	double	wall_x;
	int		tex_x;

	if (render->side == 0)
		wall_x = cub->player.posy + render->perp_wall_dist * render->ray_dir_y;
	else
		wall_x = cub->player.posx + render->perp_wall_dist * render->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)render->selected_texture->tex_width);
	if (render->side == 0 && render->ray_dir_x < 0)
		tex_x = render->selected_texture->tex_width - tex_x - 1;
	if (render->side == 1 && render->ray_dir_y > 0)
		tex_x = render->selected_texture->tex_width - tex_x - 1;
	render_vertical_texture(cub, render, x, tex_x);
}

static void	continue_ray_after_door(t_cub *cub, t_render *render)
{
	render->hit = 0;
	while (render->hit == 0)
	{
		move_ray(render);
		if (render->map_y < 0 || render->map_x < 0
			|| !cub->map.map[render->map_y] || render->map_x
			>= (int)ft_strlen(cub->map.map[render->map_y]))
		{
			render->hit = 0;
			render->selected_texture = NULL;
			return ;
		}
		if (cub->map.map[render->map_y][render->map_x] == '1')
		{
			render->hit = 1;
			render->is_door = 0;
			break ;
		}
		if (cub->map.map[render->map_y][render->map_x] == 'D')
			continue ;
	}
	calculate_wall_distance_and_height(cub, render);
}

void	draw_background_for_door(t_cub *cub, t_render *render, int x)
{
	int			y;
	t_render	bg_render;

	bg_render = *render;
	continue_ray_after_door(cub, &bg_render);
	select_texture(cub, &bg_render);
	if (bg_render.selected_texture)
		draw_wall_texture_for_door_back(cub, &bg_render, x);
	else
	{
		y = render->draw_start;
		while (y < render->draw_end)
		{
			if (y < HEIGHT / 2)
				my_mlx_pixel_put(cub, x, y, cub->fc.ceiling_c.colour);
			else
				my_mlx_pixel_put(cub, x, y, cub->fc.floor_c.colour);
			y++;
		}
	}
}
