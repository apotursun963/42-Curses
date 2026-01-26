/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:00:30 by atursun           #+#    #+#             */
/*   Updated: 2026/01/26 15:51:50 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	scale(t_line *line, int scale_factor)
{
	line->start.x *= scale_factor;
	line->start.y *= scale_factor;
	line->end.x *= scale_factor;
	line->end.y *= scale_factor;
}

void	translate(t_line *line, int move_x, int move_y)
{
	line->start.x += move_x;
	line->start.y += move_y;
	line->end.x += move_x;
	line->end.y += move_y;
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
			map->coordinates[x][y].x -= map->max_x / 2;
			map->coordinates[x][y].y -= map->max_y / 2;
			x++;
		}
		y++;
	}
}
