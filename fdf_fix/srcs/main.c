/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:00:14 by atursun           #+#    #+#             */
/*   Updated: 2026/01/26 15:48:38 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_esc(int keycode, t_fdf *fdf)
{
	if (keycode == 65307)
		free_all(fdf);
	return (0);
}

void	render_line(t_fdf *fdf, t_point start, t_point end)
{
	start.z *= fdf->cam->scale_z;
	end.z *= fdf->cam->scale_z;
	start.color = 0XFFFFFF;	// beyaz
	end.color = 0XFFFFFF;	// beyaz
	fdf->image->line = init_line(start, end);
	if (!fdf->image->line)
		free_all(fdf);
	isometric(fdf->image->line);
	scale(fdf->image->line, fdf->cam->scale_factor);
	translate(fdf->image->line, fdf->cam->move_x, fdf->cam->move_y);	// to_center
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
	mlx_string_put(fdf->mlx, fdf->win, 50, 100, 0XC70839, "PRESS 'ESC' TO CLOSE");
	return (0);
}

int	is_file_extension_valid(char *filename)
{
	char	*res;
	
	res = ft_strrchr(filename, '/');
	if (!ft_strncmp(res, "/.fdf", 5))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;
	t_map	*map;

	if (argc != 2 || is_file_extension_valid(argv[1]))
		exit(1);
	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		return (1);
	map = malloc(sizeof(t_map));
	if (!map)
		return (1);
	fdf->map = parse_map(argv[1], map);	// mapten sonra image'ı init_fdf içinde ve camerayı parse_map'ten sonra çağırırız
	if (!fdf->map) {
		free(fdf);
		return (1);
	}
	init_fdf(fdf);
	render(fdf);
	mlx_key_hook(fdf->win, handle_esc, fdf);
	mlx_hook(fdf->win, 17, 0, &free_all, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}

/*
.fdf içeriği boş olduğunda ve yok_boyle_dosya.fdf veridiğmizde leak alıyoruzz

*/