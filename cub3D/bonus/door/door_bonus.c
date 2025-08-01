/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:21:53 by mikkayma          #+#    #+#             */
/*   Updated: 2025/07/25 12:57:32 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

void	init_door(t_cub *cub)
{
	int	x;	
	int	y;
	int	i;

	i = 0;
	cub->doors_manager.door_len = door_lenght(cub);
	if (cub->doors_manager.door_len == 0)
		return ;
	cub->doors_manager.door = malloc(sizeof(t_door)
			* cub->doors_manager.door_len + 1);
	y = 0;
	while (cub->map.map[y])
	{
		x = 0;
		while (cub->map.map[y][x])
		{
			if (cub->map.map[y][x] == 'D')
			{
				fill_doors_manager_struct(cub, i, x, y);
				i++;
			}
			x++;
		}
		y++;
	}
}

static void	doors_get_data_addres(t_tex_data *frames, t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (!frames[i].image)
		{
			free_door_sprite(cub);
			free(cub->doors_manager.door);
			error_msg("Door image error", cub, 4);
		}
		i++;
	}
	i = 0;
	while (i < 8)
	{
		frames[i].texture_data = mlx_get_data_addr(frames[i].image,
				&frames[i].bits_per_pixel, &frames[i].size_line,
				&frames[i].endian);
		i++;
	}
}

void	render_door(t_cub *cub)
{
	int			i;
	char		*door_files[8];
	t_tex_data	*frames;

	if (cub->doors_manager.door_len == 0)
		return ;
	door_files[0] = "textures/door/Door0.xpm";
	door_files[1] = "textures/door/Door1.xpm";
	door_files[2] = "textures/door/Door2.xpm";
	door_files[3] = "textures/door/Door3.xpm";
	door_files[4] = "textures/door/Door4.xpm";
	door_files[5] = "textures/door/Door5.xpm";
	door_files[6] = "textures/door/Door6.xpm";
	door_files[7] = "textures/door/Door7.xpm";
	frames = cub->doors_manager.frames;
	i = 0;
	while (i < 8)
	{
		frames[i].image = mlx_xpm_file_to_image(cub->mlx.mlx, door_files[i],
				&frames[i].tex_width, &frames[i].tex_height);
		i++;
	}
	doors_get_data_addres(cub->doors_manager.frames, cub);
}

static void	execute_door(t_cub *cub, int check_x, int check_y)
{
	int	i;

	i = find_true_door(cub, check_x, check_y);
	if (cub->doors_manager.door[i].is_opening == 1
		|| cub->doors_manager.door[i].is_closing == 1)
		return ;
	if (cub->doors_manager.door[i].is_open == 0
		&& cub->doors_manager.door[i].is_opening == 0)
	{
		cub->doors_manager.door[i].is_opening = 1;
		cub->doors_manager.door[i].is_closing = 0;
		cub->doors_manager.door[i].time = get_time_ms();
		cub->doors_manager.door[i].door_frame = 1;
	}
	else if (cub->doors_manager.door[i].is_open == 1)
	{
		cub->doors_manager.door[i].is_open = 0;
		cub->doors_manager.door[i].is_closing = 1;
		cub->doors_manager.door[i].is_opening = 0;
		cub->doors_manager.door[i].door_frame = 7;
	}
}

void	handle_door(t_cub *cub)
{
	int		check_x;
	int		check_y;
	double	door_cx;
	double	door_cy;

	check_x = (int)(cub->player.posx + cub->player.dirx * 1.1);
	check_y = (int)(cub->player.posy + cub->player.diry * 1.1);
	door_cx = check_x + 0.5;
	door_cy = check_y + 0.5;
	if (sqrt(pow(door_cx - cub->player.posx, 2)
			+ pow(door_cy - cub->player.posy, 2)) < 0.74)
		return ;
	if (check_y <= 0 || check_x <= 0
		|| check_x >= (int)ft_strlen(cub->map.map[check_y]))
		return ;
	if (cub->map.map[check_y][check_x] == 'D')
		execute_door(cub, check_x, check_y);
}
