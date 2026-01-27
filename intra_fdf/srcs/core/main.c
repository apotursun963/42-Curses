/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:00:14 by atursun           #+#    #+#             */
/*   Updated: 2025/02/10 12:21:24 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

void	apply_colors(t_fdf *fdf, t_point *point)
{
	t_color	*col;

	col = NULL;
	if (fdf->cam->color_pallet == FALSE && point->color == false)
		point->color = LINE_DEF;
	else if (fdf->cam->color_pallet == TRUE)
	{
		col = color_pallet_init(BLACK, PURPLE);
		point->color = get_color(col, absolute(point->z), \
			absolute(fdf->map->max_z));
		free(col);
	}
}

void	render_line(t_fdf *fdf, t_point start, t_point end)
{
	start.z *= fdf->cam->scale_z;
	end.z *= fdf->cam->scale_z;
	apply_colors(fdf, &start);
	apply_colors(fdf, &end);
	fdf->image->line = init_line(start, end, fdf);
	if (!fdf->image->line)
		free_all(fdf);
	rotate(fdf->cam, fdf->image->line);
	projection(fdf->cam, fdf->image->line);
	scale(fdf->image->line, fdf->cam->scale_factor);
	translate(fdf->image->line, fdf->cam->move_x, fdf->cam->move_y);
	bresenham(fdf, fdf->image->line->start, fdf->image->line->end);
	free(fdf->image->line);
}

int	render(t_fdf *fdf)
{
	int	x;
	int	y;

	clear_image(fdf->image);
	y = 0;
	while (y < fdf->map->max_y)
	{
		x = 0;
		while (x < fdf->map->max_x)
		{
			if (x < fdf->map->max_x - 1)
				render_line(fdf, fdf->map->coordinates[x][y], \
					fdf->map->coordinates[x + 1][y]);
			if (y < fdf->map->max_y - 1)
				render_line(fdf, fdf->map->coordinates[x][y], \
					fdf->map->coordinates[x][y + 1]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image->image, 0, 0);
	write_menu_bar(fdf);
	return (0);
}

int	is_file_extension_valid(char *filename)
{
	char	*res;

	res = ft_strrchr(filename, '.');
	if (ft_strncmp(res, ".fdf", 4) != 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2 || !is_file_extension_valid(argv[1]))
		exit(1);
	fdf = init_fdf(argv[1]);
	render(fdf);
	mlx_hook(fdf->win, 2, 1L << 0, &key_handle, fdf);
	mlx_hook(fdf->win, 17, 0, &free_all, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
