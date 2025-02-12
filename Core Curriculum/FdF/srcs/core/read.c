/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:59:28 by atursun           #+#    #+#             */
/*   Updated: 2025/02/10 12:21:45 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

int	get_number_of_col(char *file)
{
	int		fd;
	char	*line;
	int		col;
	int		next_col;

	fd = open(file, O_RDONLY, 0);
	line = get_next_line(fd);
	if (line == NULL)
		return (0);
	col = ft_len_of_word(line, ' ');
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		next_col = ft_len_of_word(line, ' ');
		if (col != next_col)
			return (0);
		free(line);
	}
	return (close(fd), col);
}

int	get_number_of_row(char *file)
{
	int		fd;
	int		row;
	char	*line;

	row = 0;
	fd = open(file, O_RDONLY, 0);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_isprint(*line))
			row++;
		free(line);
	}
	return (close(fd), row);
}

void	fill_point(char *point, t_map *map, int coord_x, int coord_y)
{
	char	**info;
	int		i;

	map->coordinates[coord_x][coord_y].x = (float)coord_x;
	map->coordinates[coord_x][coord_y].y = (float)coord_y;
	if (ft_strchr(point, ','))
	{
		info = ft_split(point, ',');
		map->coordinates[coord_x][coord_y].z = (float)ft_atoi(info[0]);
		map->coordinates[coord_x][coord_y].color = \
			ft_atoi_base(info[1], HEXADECM);
		i = 0;
		while (info[i])
			free(info[i++]);
		free(info);
	}
	else
	{
		map->coordinates[coord_x][coord_y].z = (float)ft_atoi(point);
		map->coordinates[coord_x][coord_y].color = false;
	}
	if (map->coordinates[coord_x][coord_y].z > map->max_z)
		map->max_z = map->coordinates[coord_x][coord_y].z;
	if (map->coordinates[coord_x][coord_y].z < map->min_z)
		map->min_z = map->coordinates[coord_x][coord_y].z;
}

void	get_points(char *file, t_map *map)
{
	int		fd;
	char	*line;
	char	**split;
	int		coord[2];

	fd = open(file, O_RDONLY, 0);
	coord[1] = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		split = ft_split(line, ' ');
		coord[0] = 0;
		while (coord[0] < map->max_x)
		{
			fill_point(split[coord[0]], map, coord[0], coord[1]);
			free(split[coord[0]]);
			coord[0]++;
		}
		free(split);
		free(line);
		coord[1]++;
	}
	close(fd);
}

t_map	*read_map(char *file)
{
	t_map	*map;

	map = init_map();
	if (!map)
		return (NULL);
	map->max_x = get_number_of_col(file);
	map->max_y = get_number_of_row(file);
	map->coordinates = init_coordinates(map->max_x, map->max_y);
	if (!map->coordinates)
		return (free(map), NULL);
	get_points(file, map);
	center_to_origin(map);
	return (map);
}
