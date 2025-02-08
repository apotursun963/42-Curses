/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:01:08 by atursun           #+#    #+#             */
/*   Updated: 2025/02/08 17:19:18 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

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
	free_coordinates(fdf->map->coordinates, fdf->map->max_x);
	free(fdf->map);
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	free(fdf);
	exit(1);
}

int	free_all(t_fdf *fdf)
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
	exit(1);
	return (0);
}
