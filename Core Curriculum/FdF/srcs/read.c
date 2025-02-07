/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:59:28 by atursun           #+#    #+#             */
/*   Updated: 2025/02/07 11:20:54 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*
Bu fonksiyon, verilen dosyanın her satırındaki kelime sayısının
sabit olup olmadığını kontrol ediyor.
yani her satırdaki kelime (sayı) sayısı eşitse yani sütün sayısı eşitse 
okeydir
*/
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
		if (!is_twin(col, next_col))
			return (0);
		free(line);
	}
	return (close(fd), col);
}

/*
Bu fonksiyon, dosyadaki toplam satır sayısını yani "derinliği" hesaplar. 
Bu, haritadaki satır sayısını (Y eksenindeki boyutu) belirler.
*/
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
			break;
		if (ft_isprint(*line))		// *line -> line dizisinin ilk karakterini temsil eder
			row++;
		free(line);
	}
	return (close(fd), row);
}

/*
Bu fonksiyon, her bir harita noktasına ait veriyi (nokta) alır ve bu veriyi 
map yapısındaki uygun koordinatlara yerleştirir.
Bu fonksiyon, her bir harita noktası için hem yükseklik hem de renk 
bilgilerini alarak harita yapısını oluşturur.
*/
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
		i = 0;			// bunu kolayca free liycek daha kolay bir fonksoyn vardi free dosyasinda
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

/*
get_points fonksiyonu, her bir harita noktasının değerlerini dosyadan okur ve 
fill_point fonksiyonu ile bu verileri harita yapısına yerleştirir.
kisacasi belirtilen dosyadaki verileri okuyarak her satırdaki her bir 
değeri harita yapısındaki ilgili noktalara yerleştirir.
*/
void	get_points(char *file, t_map *map)
{
	int		fd;
	char	*line;
	char	**split;
	int		coord[2];

	fd = open(file, O_RDONLY, 0);
	coord[1] = 0;		// y ekseni rows
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		split = ft_split(line, ' ');
		coord[0] = 0;		// x ekseni cols
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

/*
Bu fonksiyon, harita dosyasını baştan sona okur ve harita verilerini işleyip bir t_map yapısında toplar.
*/
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
