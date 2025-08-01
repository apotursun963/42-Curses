/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:36:29 by atursun           #+#    #+#             */
/*   Updated: 2025/07/25 12:55:31 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	skip_whitespaces(char *line, int i)
{
	while (line[i] == ' ')
		i++;
	return (i);
}

static void	check_is_there_texture_file(t_cub *cub)
{
	int	fd1;
	int	fd2;
	int	fd3;
	int	fd4;

	fd1 = open(cub->texture.east, O_RDONLY);
	fd2 = open(cub->texture.north, O_RDONLY);
	fd3 = open(cub->texture.south, O_RDONLY);
	fd4 = open(cub->texture.west, O_RDONLY);
	if (fd1 == -1 || fd2 == -1 || fd3 == -1 || fd4 == -1)
		error_msg("Wrong texture path", cub, 2);
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
}

int	check_texture(t_cub *cub)
{
	if (!(cub->texture.north) || !(cub->texture.south)
		|| !(cub->texture.west) || !(cub->texture.east))
		error_msg("Some of the texture packs is missing", cub, 2);
	if (check_extension(cub->texture.east, ".xpm"))
		error_msg("Wall file extensions are not valid", cub, 2);
	if (check_extension(cub->texture.north, ".xpm"))
		error_msg("Wall file extensions are not valid", cub, 2);
	if (check_extension(cub->texture.west, ".xpm"))
		error_msg("Wall file extensions are not valid", cub, 2);
	if (check_extension(cub->texture.south, ".xpm"))
		error_msg("Wall file extensions are not valid", cub, 2);
	check_is_there_texture_file(cub);
	return (0);
}

static int	check_direction_in_map(t_cub *cub, char *line, int j)
{
	if (line[j] == 'N' && line[j + 1] == 'O')
	{
		if (cub->texture.north)
			return (1);
		cub->texture.north = ft_strtrim(line, "NO ");
	}	
	else if (line[j] == 'S' && line[j + 1] == 'O')
	{
		if (cub->texture.south)
			return (1);
		cub->texture.south = ft_strtrim(line, "SO ");
	}
	else if (line[j] == 'W' && line[j + 1] == 'E')
	{
		if (cub->texture.west)
			return (1);
		cub->texture.west = ft_strtrim(line, "WE ");
	}
	else if (line[j] == 'E' && line[j + 1] == 'A')
	{
		if (cub->texture.east)
			return (1);
		cub->texture.east = ft_strtrim(line, "EA ");
	}
	return (0);
}

void	read_texture(t_cub *cub, int fd, int j)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		j = 0;
		while (line[j] == ' ' || line[j] == '\t')
			j++;
		line[ft_strlen(line) - 1] = '\0';
		if (check_direction_in_map(cub, line, j))
		{
			free(line);
			error_msg("Duplicate texture", cub, 2);
		}
		free(line);
		line = get_next_line(fd);
	}
	check_texture(cub);
	close(fd);
}
