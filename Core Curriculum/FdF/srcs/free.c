/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:01:08 by atursun           #+#    #+#             */
/*   Updated: 2025/02/07 12:12:10 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	free_coordinates(t_point **coordinates, int width)
{
	int		i;

	i = 0;
	while (i < width)
		free(coordinates[i++]);
	free(coordinates);
}

void	free_map(t_fdf *fdf, int exit_code)
{
	free_coordinates(fdf->map->coordinates, fdf->map->max_x);
	free(fdf->map);
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	free(fdf);
	error(exit_code);
}

int	free_all(t_fdf *fdf, int exit_code)
{
	free_coordinates(fdf->map->coordinates, fdf->map->max_x);
	free(fdf->map);
	mlx_destroy_image(fdf->mlx, fdf->image->image);
	free(fdf->image);
	free(fdf->cam);
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
	free(fdf);
	error(exit_code);
	return (0);
}
