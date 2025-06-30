/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:36:29 by atursun           #+#    #+#             */
/*   Updated: 2025/06/30 16:57:10 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void read_texture(t_cub *cub, int fd)
{
	char *line = get_next_line(fd);
	int i = 0;
	while (line != NULL && i != 4)
	{
		if (line[0] == 'N' && line[1] == 'O')
		{
			cub->texture.north = ft_strtrim(line, "NO ");
			i++;
		}
		else if (line[0] == 'S' && line[1] == 'O')
		{
			cub->texture.south = ft_strtrim(line, "SO ");
			i++;
		}
		else if (line[0] == 'W' && line[1] == 'E')
		{
			cub->texture.west = ft_strtrim(line, "WE ");
			i++;
		}
		else if (line[0] == 'E' && line[1] == 'A')
		{
			cub->texture.east = ft_strtrim(line, "EA ");
			i++;
		} 
		free(line);
		line = get_next_line(fd);
		cub->map_index++;
	}
	close(fd);
}

void	check_map(t_cub *cub)
{
    int i = 0;
	int j = 0;
    while (cub->map.map[i])
    {
		if (i == 0)
		{		
			while (cub->map.map[i][j])
			{
				if (cub->map.map[i][j] != '1' && cub->map.map[i][j] != '\n' 
					&& cub->map.map[i][j] != ' ' && cub->map.map[i][j] != '\t')
				{
        			ft_putendl_fd("Error: Map line %d does not start and end with '1'", 1);
            		exit(EXIT_FAILURE);
        		}
				j++;
			}
		}
        int start = 0;
        int end = ft_strlen(cub->map.map[i]) - 1;
	
        while (cub->map.map[i][start] == ' ' || cub->map.map[i][start] == '\t')
            start++;
        while (end >= 0 && (cub->map.map[i][end] == ' ' || cub->map.map[i][end] == '\t'
			|| cub->map.map[i][end] == '\n'))
            end--;

        if (cub->map.map[i][start] != '1' || cub->map.map[i][end] != '1')
        {
        	ft_putendl_fd("Error: Map line %d does not start and end with '1'", 1);
            exit(EXIT_FAILURE);
        }
        i++;
    }
	j = 0;
	i--;
	while (cub->map.map[i][j])
	{
		if (cub->map.map[i][j] != '1' && cub->map.map[i][j] != '\n' 
			&& cub->map.map[i][j] != ' ' && cub->map.map[i][j] != '\t')
		{
        	ft_putendl_fd("Error: Map line %d does not start and end with '1'", 1);
        	exit(EXIT_FAILURE);
        }
		j++;
	}
}

int check_texture(t_cub *cub)
{
	if (check_extension(cub->texture.east, ".xpm"))
		return (1);
	if (check_extension(cub->texture.north, ".xpm"))
		return (1);
	if (check_extension(cub->texture.west, ".xpm"))
		return (1);
	if (check_extension(cub->texture.south, ".xpm"))
		return (1);

	int fd = open(cub->texture.east, O_RDONLY);
	if (fd != -1)
		return (1);
	return (close(fd), 0);
}
