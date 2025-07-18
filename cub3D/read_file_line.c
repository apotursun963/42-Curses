/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:24:08 by mikkayma          #+#    #+#             */
/*   Updated: 2025/07/14 11:17:04 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

static int	is_texture_or_color_line(char *line)
{
	if (ft_strnstr(line, "NO ", ft_strlen(line))
		|| ft_strnstr(line, "SO ", ft_strlen(line))
		|| ft_strnstr(line, "WE ", ft_strlen(line))
		|| ft_strnstr(line, "EA ", ft_strlen(line)))
		return (1);
	if (ft_strnstr(line, "F ", ft_strlen(line))
		|| ft_strnstr(line, "C ", ft_strlen(line)))
		return (1);
	return (0);
}

static int	is_map_line(char *line)
{
	if (ft_strchr(line, '1') && !is_texture_or_color_line(line))
		return (1);
	return (0);
}

int	unknown_line_check(t_cub *cub, char *line)
{
	if (is_empty_line(line))
		return (0);
	if (is_texture_or_color_line(line))
		return (0);
	if (is_map_line(line))
		return (1);
	free(line);
	error_msg("Invalid line", cub, 2);
	return (0);
}
