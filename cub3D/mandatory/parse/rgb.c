/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:37:13 by mikkayma          #+#    #+#             */
/*   Updated: 2025/07/25 12:55:35 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static void	check_rgb_line(char *line, t_cub *cub)
{
	int	i;

	i = skip_whitespaces(line, 0);
	if (line[i] == 'F' || line[i] == 'C')
	{
		i++;
		i = skip_whitespaces(line, i);
	}
	while (line[i])
	{
		i = skip_whitespaces(line, i);
		if (line[i] == ',' && i++)
		{
			i = skip_whitespaces(line, i);
			if (line[i] == '\n')
				return (free(line), error_msg("Rgb is not valid", cub, 2));
		}
		if (line[i] != ',' && line[i] != '\n')
		{
			if (!ft_isdigit(line[i]))
				return (free(line), error_msg("Rgb is not valid", cub, 2));
		}
		i++;
	}
}

static int	len_of_double_tmp(char **double_ptr)
{
	int	i;

	i = 0;
	while (double_ptr[i])
		i++;
	return (i);
}

static void	rbg_line(t_rgb *rgb, char *line, t_cub *cub)
{
	char	*tmp;
	char	**double_tmp;

	check_rgb_line(line, cub);
	tmp = ft_strdup(line + 2);
	double_tmp = ft_split(tmp, ',');
	free(tmp);
	if (len_of_double_tmp(double_tmp) != 3)
	{
		free_map(double_tmp);
		free(line);
		error_msg("rgb num is not valid", cub, 2);
	}
	if (double_tmp[0] && double_tmp[1] && double_tmp[2])
	{
		rgb->r = ft_atoi(double_tmp[0]);
		rgb->g = ft_atoi(double_tmp[1]);
		rgb->b = ft_atoi(double_tmp[2]);
		free_map(double_tmp);
		if (!(rgb->r >= 0 && rgb->r <= 255) || !(rgb->g >= 0 && rgb->g <= 255)
			|| !(rgb->b >= 0 && rgb->b <= 255))
			return (free(line),
				error_msg("RGB range value must be between 0 - 255", cub, 2));
	}
}

static unsigned int	rgb_to_colour(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	read_fc_rgb(t_cub *cub, int fd)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		j = 0;
		while (line[j] == ' ' || line[j] == '\t')
			j++;
		if (line[j] == 'F' && line[j + 1] == ' ' && ++i)
			rbg_line(&cub->fc.floor_c, line, cub);
		if (line[j] == 'C' && line[j + 1] == ' ' && ++i)
			rbg_line(&cub->fc.ceiling_c, line, cub);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (i != 2)
		error_msg("Missing floor or ceiling color", cub, 2);
	cub->fc.ceiling_c.colour = rgb_to_colour(cub->fc.ceiling_c.r, \
		cub->fc.ceiling_c.g, cub->fc.ceiling_c.b);
	cub->fc.floor_c.colour = rgb_to_colour(cub->fc.floor_c.r, \
		cub->fc.floor_c.g, cub->fc.floor_c.b);
}
