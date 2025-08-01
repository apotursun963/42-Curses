/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:11:11 by mikkayma          #+#    #+#             */
/*   Updated: 2025/07/25 12:57:43 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

void	my_mlx_pixel_put_for_minimap(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= MINIMAP_WIDTH || y < 0 || y >= MINIMAP_HEIGHT)
		return ;
	dst = cub->minimap.data;
	dst += (y * cub->minimap.size_line + x * (cub->minimap.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	check_minimap(t_cub *cub)
{
	int	total_map_pixel_width;
	int	total_map_pixel_height;

	total_map_pixel_width = cub->map.map_width * cub->minimap.cell_size;
	total_map_pixel_height = cub->map.map_height * cub->minimap.cell_size;
	if (total_map_pixel_width < MINIMAP_WIDTH)
		cub->minimap.offset_x = (MINIMAP_WIDTH - total_map_pixel_width) / 2;
	else
	{
		if (cub->minimap.offset_x > 0)
			cub->minimap.offset_x = 0;
		if (cub->minimap.offset_x < MINIMAP_WIDTH - total_map_pixel_width)
			cub->minimap.offset_x = MINIMAP_WIDTH - total_map_pixel_width;
	}
	if (total_map_pixel_height < MINIMAP_HEIGHT)
		cub->minimap.offset_y = (MINIMAP_HEIGHT - total_map_pixel_height) / 2;
	else
	{
		if (cub->minimap.offset_y > 0)
			cub->minimap.offset_y = 0;
		if (cub->minimap.offset_y < MINIMAP_HEIGHT - total_map_pixel_height)
			cub->minimap.offset_y = MINIMAP_HEIGHT - total_map_pixel_height;
	}
}

t_tmp	fill_tmp(int start_x, int start_y, int color)
{
	t_tmp	tmp;

	tmp.color = color;
	tmp.start_x = start_x;
	tmp.start_y = start_y;
	return (tmp);
}

void	minimap(t_cub *cub)
{
	calculate_map_height_and_with(cub);
	cub->minimap.player_map_px = cub->player.posx * cub->minimap.cell_size;
	cub->minimap.player_map_py = cub->player.posy * cub->minimap.cell_size;
	cub->minimap.offset_x = (MINIMAP_WIDTH / 2) - cub->minimap.player_map_px;
	cub->minimap.offset_y = (MINIMAP_HEIGHT / 2) - cub->minimap.player_map_py;
	check_minimap(cub);
	draw_rectangle(cub, fill_tmp(0, 0, 0x000000),
		MINIMAP_WIDTH, MINIMAP_HEIGHT);
	draw_minimap(cub);
	draw_player_in_minimap(cub, 0, 0, 0);
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win,
		cub->minimap.mini_image, 10, 10);
}
