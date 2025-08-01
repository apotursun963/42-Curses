/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:25:06 by mikkayma          #+#    #+#             */
/*   Updated: 2025/07/25 12:55:47 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = cub->mlx.win_data.texture_data;
	dst += (y * cub->mlx.win_data.size_line + x
			* (cub->mlx.win_data.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	get_addrs_of_texture(t_cub *cub)
{
	cub->south.texture_data = mlx_get_data_addr(cub->south.image, \
		&cub->south.bits_per_pixel, &cub->south.size_line, &cub->south.endian);
	cub->north.texture_data = mlx_get_data_addr(cub->north.image, \
		&cub->north.bits_per_pixel, &cub->north.size_line, &cub->north.endian);
	cub->east.texture_data = mlx_get_data_addr(cub->east.image, \
		&cub->east.bits_per_pixel, &cub->east.size_line, &cub->east.endian);
	cub->west.texture_data = mlx_get_data_addr(cub->west.image, \
		&cub->west.bits_per_pixel, &cub->west.size_line, &cub->west.endian);
}

void	xpm_to_image(t_cub *cub)
{
	cub->north.image = mlx_xpm_file_to_image(cub->mlx.mlx, \
		cub->texture.north, &cub->north.tex_width, &cub->north.tex_height);
	if (!cub->north.image)
		error_msg("Texture is incorrect: North", cub, 4);
	cub->south.image = mlx_xpm_file_to_image(cub->mlx.mlx, \
		cub->texture.south, &cub->south.tex_width, &cub->south.tex_height);
	if (!cub->south.image)
		error_msg("Texture is incorrect: south", cub, 4);
	cub->east.image = mlx_xpm_file_to_image(cub->mlx.mlx, \
		cub->texture.east, &cub->east.tex_width, &cub->east.tex_height);
	if (!cub->east.image)
		error_msg("Texture is incorrect: east", cub, 4);
	cub->west.image = mlx_xpm_file_to_image(cub->mlx.mlx, cub->texture.west, \
		&cub->west.tex_width, &cub->west.tex_height);
	if (!cub->west.image)
		error_msg("Texture is incorrect: West", cub, 4);
	get_addrs_of_texture(cub);
	cub->mlx.win_data.image = mlx_new_image(cub->mlx.mlx, WIDTH, HEIGHT);
	cub->mlx.win_data.texture_data = mlx_get_data_addr(cub->mlx.win_data.image, \
		&cub->mlx.win_data.bits_per_pixel, &cub->mlx.win_data.size_line, \
		&cub->mlx.win_data.endian);
}

static void	draw_wall_texture(t_cub *cub, t_render *render, int *tex_x, int x)
{
	double	wall_x;

	if (BONUS && render->is_door)
		draw_background_for_door(cub, render, x);
	if (render->side == 0)
		wall_x = cub->player.posy + render->perp_wall_dist * render->ray_dir_y;
	else
		wall_x = cub->player.posx + render->perp_wall_dist * render->ray_dir_x;
	wall_x -= floor(wall_x);
	*tex_x = (int)(wall_x * (double)render->selected_texture->tex_width);
	if (render->side == 0 && render->ray_dir_x < 0)
		*tex_x = render->selected_texture->tex_width - *tex_x - 1;
	if (render->side == 1 && render->ray_dir_y > 0)
		*tex_x = render->selected_texture->tex_width - *tex_x - 1;
}

void	draw_texture(t_cub *cub, t_render *render, int x, int y)
{
	int		tex_y;
	int		tex_x;
	int		color;
	double	step;
	double	tx_pos;

	draw_wall_texture(cub, render, &tex_x, x);
	step = 1.0 * render->selected_texture->tex_height / render->line_height;
	tx_pos = (render->draw_start - HEIGHT / 2 + render->line_height / 2) * step;
	y = render->draw_start;
	while (y < render->draw_end)
	{
		tex_y = (int)tx_pos & (render->selected_texture->tex_height - 1);
		tx_pos += step;
		color = *(unsigned int *)(render->selected_texture->texture_data
				+ (tex_y * render->selected_texture->size_line + tex_x
					* (render->selected_texture->bits_per_pixel / 8)));
		if (BONUS && render->is_door && color == 0x0B0A0A)
		{
			y++;
			continue ;
		}
		my_mlx_pixel_put(cub, x, y, color);
		y++;
	}
}
