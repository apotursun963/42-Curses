/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:00:56 by atursun           #+#    #+#             */
/*   Updated: 2026/01/26 22:27:20 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(t_fdf *fdf, t_point start, t_point end)
{
	float	x_step;
	float	y_step;
	int		max_steps;
	int		i_line;

	x_step = end.x - start.x;
	y_step = end.y - start.y;
	max_steps = (int)max(absolute(x_step), absolute(y_step));
	x_step /= max_steps;
	y_step /= max_steps;
	i_line = 0;
	while (i_line < max_steps)
	{
		if ((start.x > 0 && start.y > 0) && (start.x < WIDTH && start.y < HEIGHT))
			pixel_to_image(fdf->image, start.x, start.y, 0XFF3FFF);	// mor oldu beyaz da yapabilirsin
		start.x += x_step;
		start.y += y_step;
		i_line++;
	}
}

void	pixel_to_image(t_image *image, float x, float y, int color)
{
	int	pixel;

	pixel = ((int)y * image->line_bytes) + ((int)x * 4);
	if (image->endian == 1)
	{
		image->buffer[pixel + 0] = (color >> 24);
		image->buffer[pixel + 1] = (color >> 16);
		image->buffer[pixel + 2] = (color >> 8);
		image->buffer[pixel + 3] = (color);
	}
	else if (image->endian == 0)
	{
		image->buffer[pixel + 0] = (color);
		image->buffer[pixel + 1] = (color >> 8);
		image->buffer[pixel + 2] = (color >> 16);
		image->buffer[pixel + 3] = (color >> 24);
	}
}

void	free_coordinates(t_point **coordinates, int width)
{
	int		i;

	i = 0;
	while (i < width)
		free(coordinates[i++]);
	free(coordinates);
}

void	free_map(t_fdf *fdf)
{
	free_coordinates(fdf->map->coord, fdf->map->max_x);
	free(fdf->map);
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	free(fdf);
	exit(1);
}

int	free_all(t_fdf *fdf)
{
	free_coordinates(fdf->map->coord, fdf->map->max_x);
	free(fdf->map);
	mlx_destroy_image(fdf->mlx, fdf->image->image);
	free(fdf->image);
	free(fdf->cam);
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
	free(fdf);
	exit(1);
	return (0);
}
