/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:55:10 by mikkayma          #+#    #+#             */
/*   Updated: 2025/07/25 12:55:05 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static void	check_map_line_start_end(char *line, t_cub *cub)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] != '1')
		error_msg("Map block does not start with '1'", cub, 3);
	i = ft_strlen(line) - 1;
	while (i >= 0 && (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'))
		i--;
	if (i >= 0 && line[i] != '1')
		error_msg("Map block does not end with '1'", cub, 3);
}

int	get_num_lines(char **map)
{
	int	count;

	count = 0;
	while (map[count] != NULL)
		count++;
	return (count);
}

static void	check_walls(t_cub *cub, char *err_msg)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map.map[i])
	{
		j = 0;
		if (i == 0)
		{
			while (cub->map.map[i][j])
			{
				if (cub->map.map[i][j] != '1' && cub->map.map[i][j] != '\n'
					&& cub->map.map[i][j] != ' ' && cub->map.map[i][j] != '\t')
					error_msg(err_msg, cub, 3);
				j++;
			}
		}
		else
			check_map_line_start_end(cub->map.map[i], cub);
		i++;
	}
}

void	check_map(t_cub *cub)
{
	int	i;
	int	num_lines;

	i = 0;
	num_lines = get_num_lines(cub->map.map);
	while (cub->map.map[num_lines - 1][i])
	{
		if (cub->map.map[num_lines - 1][i] != '1'
			&& cub->map.map[num_lines - 1][i] != '\n'
			&& cub->map.map[num_lines - 1][i] != ' '
			&& cub->map.map[num_lines - 1][i] != '\t')
			error_msg("Map line does not start and end with '1", cub, 3);
		i++;
	}
	check_walls(cub, "There is no '1 in the first or last line of the map");
	check_map_around_wall(cub);
}
