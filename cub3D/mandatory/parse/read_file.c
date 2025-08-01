/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:35:00 by atursun           #+#    #+#             */
/*   Updated: 2025/07/25 12:55:43 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static void	read_xpm_after_map(t_cub *cub, char *tmp, int fd)
{
	int	i;

	if (cub->is_player == 0)
		error_msg("Player is missing", cub, 3);
	while (tmp != NULL)
	{
		i = 0;
		while (tmp[i])
		{
			if (tmp[i] != '\0' && tmp[i] != ' '
				&& tmp[i] != '\t' && tmp[i] != '\n')
			{
				free(tmp);
				error_msg("Wrong map design", cub, 3);
			}
			i++;
		}
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
}

static char	*read_xpm_until_map(t_cub *cub, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (unknown_line_check(cub, line))
			break ;
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
		error_msg("No map", cub, 2);
	if (ft_strchr(line, 'W') || ft_strchr(line, 'E')
		|| ft_strchr(line, 'N') || ft_strchr(line, 'S'))
	{
		free(line);
		error_msg("Player on the wall", cub, 2);
	}
	return (line);
}

static void	read_map(t_cub *cub, char *file)
{
	char	*tmp;
	int		fd;
	int		i;
	int		map_lengt;

	i = 0;
	fd = open(file, O_RDONLY);
	tmp = read_xpm_until_map(cub, fd);
	map_lengt = map_reel_lenght(file, cub);
	cub->map.map = ft_calloc(map_lengt + 1, sizeof(char *));
	while (tmp != NULL && tmp[0] != '\0')
	{
		if (!ft_strchr(tmp, '1'))
			break ;
		validate_map_line(tmp, cub);
		set_coor_and_pos(cub, tmp, i);
		cub->map.map[i] = ft_strdup(tmp);
		free(tmp);
		tmp = NULL;
		tmp = get_next_line(fd);
		i++;
	}
	cub->map.map[i] = NULL;
	read_xpm_after_map(cub, tmp, fd);
	check_map(cub);
}

static void	read_file(t_cub *cub, char *file)
{
	int	fd;
	int	fd2;

	fd = open(file, O_RDONLY);
	read_texture(cub, fd, 0);
	fd2 = open(file, O_RDONLY);
	read_fc_rgb(cub, fd2);
	close(fd2);
	read_map(cub, file);
}

void	open_file(t_cub *cub, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_msg("can not open file", cub, 2);
	line = get_next_line(fd);
	if (!line)
		error_msg("File is empty", cub, 2);
	free(line);
	close(fd);
	read_file(cub, file);
}
