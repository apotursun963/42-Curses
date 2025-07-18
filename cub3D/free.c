/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikkayma <mikkayma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:33:28 by mikkayma          #+#    #+#             */
/*   Updated: 2025/07/15 14:37:43 by mikkayma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_texture(t_texture texture)
{
	if (texture.north)
		free(texture.north);
	if (texture.east)
		free(texture.east);
	if (texture.south)
		free(texture.south);
	if (texture.west)
		free(texture.west);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_image(t_cub *cub)
{
	if (cub->north.image)
		mlx_destroy_image(cub->mlx.mlx, cub->north.image);
	if (cub->east.image)
		mlx_destroy_image(cub->mlx.mlx, cub->east.image);
	if (cub->west.image)
		mlx_destroy_image(cub->mlx.mlx, cub->west.image);
	if (cub->south.image)
		mlx_destroy_image(cub->mlx.mlx, cub->south.image);
	if (cub->mlx.win_data.image)
		mlx_destroy_image(cub->mlx.mlx, cub->mlx.win_data.image);
}
