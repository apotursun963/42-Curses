/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 13:03:04 by atursun           #+#    #+#             */
/*   Updated: 2025/07/25 12:55:29 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	is_player(char p)
{
	if (p == 'N' || p == 'S' || p == 'E' || p == 'W')
		return (1);
	return (0);
}

void	validate_map_line(char *line, t_cub *cub)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!(line[i] == '0' || line[i] == '1' || is_player(line[i])
				|| line[i] == '\0' || line[i] == '\n' || line[i] == ' '))
		{
			if (BONUS && line[i] == 'D' && i++)
				continue ;
			free(line);
			error_msg("Unknown character", cub, 3);
		}
		i++;
	}
	if ((line[0] == ' ' || line[0] == '\t' || line[0] == '\n')
		&& !ft_strchr(line, '1'))
	{
		free(line);
		error_msg("Empty or whitespace-only line in map", cub, 3);
	}
}

static void	set_player_info(t_cub *cub, char *line)
{
	if (ft_strchr(line, 'N'))
	{
		cub->player.diry = -1;
		cub->plane_x = 0.66;
	}
	if (ft_strchr(line, 'S'))
	{
		cub->plane_x = -0.66;
		cub->player.diry = 1;
	}
	if (ft_strchr(line, 'E'))
	{
		cub->player.dirx = 1;
		cub->plane_y = 0.66;
	}
	if (ft_strchr(line, 'W'))
	{
		cub->player.dirx = -1;
		cub->plane_y = -0.66;
	}
}

void	set_coor_and_pos(t_cub *cub, char *line, int i)
{
	int	j;

	if (ft_strchr(line, 'N') || ft_strchr(line, 'S')
		|| ft_strchr(line, 'W') || ft_strchr(line, 'E'))
	{
		j = 0;
		cub->player.posy = (double)i + 0.5;
		while (line[j])
		{
			if (is_player(line[j]))
			{
				cub->is_player++;
				if (cub->is_player > 1)
				{
					cub->map.map[i] = NULL;
					free(line);
					error_msg("Player multiple", cub, 3);
				}
				cub->player.posx = (double)j + 0.5;
			}
			j++;
		}
		set_player_info(cub, line);
	}
}

int	map_reel_lenght(char *file, t_cub *cub)
{
	int		fd;
	char	*line;
	int		len;

	len = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strchr(line, '1') && !ft_strchr(line, 'F')
			&& !ft_strchr(line, 'C') && !ft_strchr(line, 'S')
			&& !ft_strchr(line, 'W') && !ft_strchr(line, 'N')
			&& !ft_strchr(line, 'E'))
			len++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (len == 0)
		error_msg("there is not map", cub, 2);
	len++;
	return (len);
}
