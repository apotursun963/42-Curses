/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_draw_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:56:59 by mikkayma          #+#    #+#             */
/*   Updated: 2025/07/25 12:57:46 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

static int	color_selection(t_cub *cub, int x, int y)
{
	int	color;

	color = 0;
	if (cub->map.map[y][x] == '1')
		color = 0xE0E0E0;
	else if (cub->map.map[y][x] == '0' || cub->map.map[y][x] == 'N'
				|| cub->map.map[y][x] == 'S' || cub->map.map[y][x] == 'E'
				|| cub->map.map[y][x] == 'W')
		color = 0x606060;
	else if (cub->map.map[y][x] == 'D')
		color = 0x8B4513;
	else
		color = 0x303030;
	return (color);
}

void	draw_rectangle(t_cub *cub, t_tmp tmp, int width, int height)
{
	int	x;
	int	y;

	y = tmp.start_y;
	while (y < tmp.start_y + height)
	{
		x = tmp.start_x;
		while (x < tmp.start_x + width)
		{
			my_mlx_pixel_put_for_minimap(cub, x, y, tmp.color);
			x++;
		}
		y++;
	}
}

void	draw_player_in_minimap(t_cub *cub, float dx, float dy, int pl_size)
{
	int			pl_x;
	int			pl_y;
	int			px;
	int			py;
	int			i;

	pl_x = cub->minimap.offset_x + cub->minimap.player_map_px;
	pl_y = cub->minimap.offset_y + cub->minimap.player_map_py;
	pl_size = cub->minimap.cell_size / 2;
	draw_rectangle(cub, fill_tmp(pl_x - pl_size / 2,
			pl_y - pl_size / 2, 0xFF0000), pl_size, pl_size);
	dx = cub->player.dirx;
	dy = cub->player.diry;
	i = 0;
	while (i < cub->minimap.cell_size + 4)
	{
		px = pl_x + (int)(dx * i);
		py = pl_y + (int)(dy * i);
		my_mlx_pixel_put_for_minimap(cub, px, py, 0x00FF00);
		i++;
	}	
}

void	draw_minimap(t_cub *cub)
{
	int	mini_x;
	int	mini_y;
	int	x;
	int	y;
	int	color;

	color = 0;
	y = 0;
	while (y < cub->map.map_height && cub->map.map[y])
	{
		x = 0;
		while (x < (int)ft_strlen(cub->map.map[y]))
		{
			if (cub->map.map[y][x] && cub->map.map[y][x] != ' ')
			{
				color = color_selection(cub, x, y);
				mini_x = cub->minimap.offset_x + (x * cub->minimap.cell_size);
				mini_y = cub->minimap.offset_y + (y * cub->minimap.cell_size);
				draw_rectangle(cub, fill_tmp(mini_x, mini_y, color),
					cub->minimap.cell_size, cub->minimap.cell_size);
			}
			x++;
		}
		y++;
	}
}

void	calculate_map_height_and_with(t_cub *cub)
{
	int	current_width;

	current_width = 0;
	while (cub->map.map[cub->map.map_height])
	{
		current_width = ft_strlen(cub->map.map[cub->map.map_height]);
		if (current_width > cub->map.map_width)
			cub->map.map_width = current_width;
		cub->map.map_height++;
	}
}
