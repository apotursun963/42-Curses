/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:59:28 by atursun           #+#    #+#             */
/*   Updated: 2026/01/26 22:21:08 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	calculate_number_of_column(char *file)
{
	int		fd;
	char	*line;
	int		c_col;
	int		next_col;

	fd = open(file, O_RDONLY, 0);
	if (fd == -1)
		return (-1);		
	line = get_next_line(fd);
	if (line == NULL)
		return (0);
	c_col = ft_len_of_word(line, ' ');
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		next_col = ft_len_of_word(line, ' ');
		if (c_col != next_col)
			return (0);
		free(line);
	}
	close(fd);
	return (c_col);
}

int	calculate_number_of_row(char *file)
{
	int		fd;
	int		c_row;
	char	*line;

	c_row = 0;
	fd = open(file, O_RDONLY, 0);
	if (fd == -1)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (*line >= 32 && *line <= 126)
			c_row++;
		free(line);
	}
	close(fd);	
	return (c_row);
}

void	place_the_point(char *point, t_map *map, int x, int y)
{
	char	**vertex;	// Vertex, 3D (veya 2D) uzayda bir şeklin tek bir köşe/noktasıdır. FDF’de 2,0xff gibi bir ifade, yüksekliği ve rengi olan bir vertexi temsil eder.

	map->coord[x][y].x = (float)x;
	map->coord[x][y].y = (float)y;
	if (ft_strchr(point, ','))
	{
		vertex = ft_split(point, ',');
		map->coord[x][y].z = (float)ft_atoi(vertex[0]);
		map->coord[x][y].color = ft_atoi_base(vertex[1], HEXADECM);
		ft_free(vertex);
	}
	else
	{
		map->coord[x][y].z = (float)ft_atoi(point);
		map->coord[x][y].color = false;
	}
}

void	get_points(char *file, t_map *map)
{
	int		fd;
	char	*line;
	char	**split;
	int		x;
	int		y;

	fd = open(file, O_RDONLY, 0);
	y = 0;	// satır sayısı (height)
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		split = ft_split(line, ' ');
		x = 0;	// sütün sayısı (width)
		while (x < map->max_x)
		{
			place_the_point(split[x], map, x, y);
			free(split[x]);
			x++;
		}
		free(split);
		free(line);
		y++;
	}
	close(fd);
}

t_map	*parse_map(char *file, t_map *map)
{
	map->max_x = calculate_number_of_column(file);
	if (map->max_x <= 0)
		return (NULL);
	map->max_y = calculate_number_of_row(file);
	if (map->max_y <= 0)
		return (NULL);
	map->coord = allocate_coordinates(map->max_x, map->max_y);
	if (!map->coord)
		return (free(map), NULL);
	get_points(file, map);
	center_to_origin(map);
	return (map);
}
