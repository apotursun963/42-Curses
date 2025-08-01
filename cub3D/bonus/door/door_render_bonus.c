/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_render_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:27:38 by mikkayma          #+#    #+#             */
/*   Updated: 2025/07/25 16:44:38 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

static void	draw_the_walls_behind_the_door(t_cub *cub, t_render *render
	, int y, int x)
{
	t_render	bg_render;
	int			bg_color;

	bg_render = *render;
	continue_ray_after_door(cub, &bg_render);
	select_texture(cub, &bg_render);
	if (bg_render.selected_texture)
	{
		if (y >= bg_render.draw_start && y < bg_render.draw_end)
		{
			bg_color = calculate_the_walls_behind_the_door(cub, bg_render, y);
			my_mlx_pixel_put(cub, x, y, bg_color);
		}
		else
			draw_floor_and_ceiling(cub, x, y);
	}
	else
		draw_floor_and_ceiling(cub, x, y);
}

static void	render_vertical_texture(t_cub *cub, t_render *render
	, int x, int tex_x)
{
	double	stp;
	double	tex_pos;
	int		color;
	int		tex_y;
	int		y;

	stp = 1.0 * render->selected_texture->tex_height / render->line_height;
	tex_pos = (render->draw_start - HEIGHT / 2 + render->line_height / 2) * stp;
	y = render->draw_start;
	while (y < render->draw_end)
	{
		tex_y = (int)tex_pos & (render->selected_texture->tex_height - 1);
		tex_pos += stp;
		color = *(unsigned int *)(render->selected_texture->texture_data
				+ (tex_y * render->selected_texture->size_line + tex_x
					* (render->selected_texture->bits_per_pixel / 8)));
		if (render->is_door && color == 0x0B0A0A)
		{
			draw_the_walls_behind_the_door(cub, render, y, x);
			y++;
			continue ;
		}
		my_mlx_pixel_put(cub, x, y, color);
		y++;
	}
}

static void	draw_wall_texture_for_door_back(t_cub *cub, t_render *render, int x)
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

void	continue_ray_after_door(t_cub *cub, t_render *render)
{
	render->hit = 0;
	while (render->hit == 0)
	{
		move_ray(render);
		if (render->map_x >= (int)ft_strlen(cub->map.map[render->map_y])
			|| render->map_y < 0 || render->map_x < 0
			|| !cub->map.map[render->map_y])
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
			check_the_door_after_the_door(cub, render);
	}
	calculate_wall_distance_and_height(cub, render);
}

void	draw_background_for_door(t_cub *cub, t_render *render, int x)
{
	t_render	bg_render;
	int			y;
	t_door		door;

	door = cub->doors_manager.door
	[find_true_door(cub, render->map_x, render->map_y)];
	if (door.is_open == 0 && door.is_opening != 1 && door.is_closing != 1)
		return ;
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
