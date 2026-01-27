/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:59:28 by atursun           #+#    #+#             */
/*   Updated: 2026/01/27 09:48:25 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	calculate_number_of_column(t_fdf *fdf)
{
	int		c_col;
	int		next_col;
	int		i;

	if (fdf->map_line.count_line == 0)
		return (0);
	c_col = ft_len_of_word(fdf->map_line.line[0], ' ');
	i = 1;
	while (i < fdf->map_line.count_line)
	{
		next_col = ft_len_of_word(fdf->map_line.line[i], ' ');
		if (c_col != next_col)
			return (0);
		i++;
	}
	return (c_col);
}


/*
bazı haritalarda renkler hexa olarak veriliyor onları öyle göstermen gerekiyor ama 
göstermiyor onu düzenle
*/
void	place_the_point(char *point, t_map *map, int x, int y)
{
	char	**vertex;	// Vertex, 3D (veya 2D) uzayda bir şeklin tek bir köşe/noktasıdır. FDF’de 2,0xff gibi bir ifade, yüksekliği ve rengi olan bir vertexi temsil eder.

	map->coord[x][y].x = x;
	map->coord[x][y].y = y;
	if (ft_strchr(point, ','))
	{
		vertex = ft_split(point, ',');
		map->coord[x][y].z = ft_atoi(vertex[0]);
		map->coord[x][y].color = ft_atoi_base(vertex[1], HEXADECM);
		map->coord[x][y].has_color = 1;
		ft_free(vertex);
	}
	else
	{
		map->coord[x][y].z = ft_atoi(point);
		map->coord[x][y].has_color = 0;
	}
}

void	get_points(t_fdf *fdf)
{
	char	**split;
	int		x;
	int		y;

	y = 0;	// satır sayısı (height)
	while (y < fdf->map_line.count_line)
	{
		split = ft_split(fdf->map_line.line[y], ' ');
		x = 0;	// sütün sayısı (width)
		while (x < fdf->map->max_x)
		{
			if (!split) 
				return ;
			place_the_point(split[x], fdf->map, x, y);
			free(split[x]);
			x++;
		}
		free(split);
		y++;
	}
}

/*
her fonksiynda tek tek open ile açmak yerine parse_map func orada aç
ve diğerlerine fd gönder ama dikkat ilk okuyan funcs fd'nin sonuna kadar okuduğu için
bir sonraki funcs bir şey okuyamaz çünkü fd dosyanın sonuna gelmiş
bunu dikkate al
1. okudğun satırı (line) free etmek yerine bir struct yap onun içine koy daha iyi değilmi
*/
int read_map(int fd, t_fdf *fdf) {
	fdf->map_line.count_line = 0;
	fdf->map_line.line = malloc(sizeof(char *) * 10000);
	if (!fdf->map_line.line)
		return (0);
	while (fdf->map_line.count_line < 10000) {
		fdf->map_line.line[fdf->map_line.count_line] = get_next_line(fd);
		if (fdf->map_line.line[fdf->map_line.count_line] == NULL)
			break ;
		fdf->map_line.count_line++;
	}
	fdf->map_line.line[fdf->map_line.count_line] = NULL;
	return (fdf->map_line.count_line);
}

t_map	*parse_map(char *file, t_fdf *fdf)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd  == -1)
		return (NULL);
	if (read_map(fd, fdf) == 0) {
		close(fd);
		return (NULL);
	}
	fdf->map->max_x = calculate_number_of_column(fdf);	// sütün sayısı (width) al
	if (fdf->map->max_x == 0)
		return (NULL);
	fdf->map->max_y = fdf->map_line.count_line;		// satır sayısı (row) al
	if (fdf->map->max_y == 0)
		return (NULL);
	fdf->map->coord = allocate_coordinates(fdf->map->max_x, fdf->map->max_y);
	if (!fdf->map->coord)
		return (free(fdf->map), NULL);
	get_points(fdf);
	ft_free(fdf->map_line.line);
	center_map_to_origin(fdf->map, fdf->map->max_y, fdf->map->max_x);
	close(fd);
	return (fdf->map);
}
