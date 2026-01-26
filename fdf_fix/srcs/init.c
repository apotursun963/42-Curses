/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:00:25 by atursun           #+#    #+#             */
/*   Updated: 2026/01/26 15:44:54 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void init_fdf(t_fdf	*fdf)
{
	fdf->mlx = mlx_init();
	fdf->win_x = WIDTH;
	fdf->win_y = HEIGHT;
	fdf->win = mlx_new_window(fdf->mlx, fdf->win_x, fdf->win_y, "FDF");
	fdf->image = init_image(fdf->mlx);
	if (!fdf->image)
		free_map(fdf);
	fdf->cam = init_cam(fdf->map);
	if (!fdf->cam)
		free_all(fdf);
}

t_image	*init_image(void *mlx)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	if (!image)
		return (NULL);
	image->image = mlx_new_image(mlx, WIDTH, HEIGHT);
	image->buffer = mlx_get_data_addr(image->image, &image->pixel_bits, \
			&image->line_bytes, &image->endian);
	image->line = NULL;
	return (image);
}

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

t_cam	*init_cam(t_map *map)
{
	t_cam	*cam;

	cam = malloc(sizeof(t_cam));
	if (!cam)
		return (NULL);
	cam->scale_factor = scale_to_fit(map);
	cam->scale_z = 1;
	cam->move_x = WIDTH / 2;
	cam->move_y = HEIGHT / 2;
	return (cam);
}

t_line	*init_line(t_point start, t_point end)
{
	t_line	*line;

	line = malloc(sizeof(t_line));
	if (!line)
		return (NULL);
	line->start.x = start.x;
	line->start.y = start.y;
	line->start.z = start.z;
	line->start.color = start.color;
	line->end.x = end.x;
	line->end.y = end.y;
	line->end.z = end.z;
	line->end.color = end.color;
	return (line);
}
