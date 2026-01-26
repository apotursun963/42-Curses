/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:00:30 by atursun           #+#    #+#             */
/*   Updated: 2026/01/26 19:24:01 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	scale_to_fit(t_map *map)
{
	float	scale_x;
	float	scale_y;
	float	scale_factor;

	scale_x = WIDTH / map->max_x;
	scale_y = HEIGHT / map->max_y;
	scale_factor = min(scale_x, scale_y);
	if (scale_factor < 4)
		return (2);
	return (scale_factor / 2);
}

void init_mlx_image_cam(t_fdf	*fdf)
{
	t_image	*image;
	t_cam	*cam;

	// mlx init
	fdf->mlx = mlx_init();
	fdf->win_x = WIDTH;
	fdf->win_y = HEIGHT;
	fdf->win = mlx_new_window(fdf->mlx, fdf->win_x, fdf->win_y, "FDF");	

	// image init
	image = malloc(sizeof(t_image));
	if (!image)
		return ;
	image->image = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	image->buffer = mlx_get_data_addr(image->image, &image->pixel_bits, \
			&image->line_bytes, &image->endian);
	image->line = NULL;
	fdf->image = image;

	// camera init
	cam = malloc(sizeof(t_cam));
	if (!cam)
		return ;
	cam->scale_factor = scale_to_fit(fdf->map);
	cam->move_x = WIDTH / 2;
	cam->move_y = HEIGHT / 2;
	fdf->cam = cam;
}

void	isometric(t_line *line)
{
	t_point	new_start;
	t_point	new_end;

	new_start.x = (line->start.x - line->start.y) * cos(ANG_30);
	new_start.y = (line->start.x + line->start.y) * sin(ANG_30) - line->start.z;
	line->start.x = new_start.x;
	line->start.y = new_start.y;
	new_end.x = (line->end.x - line->end.y) * cos(ANG_30);
	new_end.y = (line->end.x + line->end.y) * sin(ANG_30) - line->end.z;
	line->end.x = new_end.x;
	line->end.y = new_end.y;
}

t_point	**allocate_coordinates(int width, int depth)
{
	int		i;
	t_point	**coordin;

	coordin = malloc(width * sizeof(t_point *));
	if (!coordin)
		return (NULL);
	i = 0;
	while (i < width)
	{
		coordin[i] = malloc(depth * sizeof(t_point));
		if (!coordin[i])
			return (NULL);
		i++;
	}
	return (coordin);
}

void	center_to_origin(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->max_y)
	{
		x = 0;
		while (x < map->max_x)
		{
			map->coord[x][y].x -= map->max_x / 2;
			map->coord[x][y].y -= map->max_y / 2;
			x++;
		}
		y++;
	}
}
