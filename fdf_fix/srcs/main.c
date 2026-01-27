/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:00:14 by atursun           #+#    #+#             */
/*   Updated: 2026/01/27 09:41:23 by atursun          ###   ########.fr       */
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
	t_line line;

	// init line
	line.start = start;
	line.end = end;
	
	isometric(&line);
	
	// scale
	line.start.x *= fdf->cam->scale_factor;
	line.start.y *= fdf->cam->scale_factor;
	line.end.x *= fdf->cam->scale_factor;
	line.end.y *= fdf->cam->scale_factor;

	// translate
	line.start.x += fdf->cam->move_x;
	line.start.y += fdf->cam->move_y;
	line.end.x += fdf->cam->move_x;
	line.end.y += fdf->cam->move_y;

	bresenham(fdf, line.start, line.end);
}

void	render_image(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->map->max_y)
	{
		x = 0;
		while (x < fdf->map->max_x)
		{
			if (x < fdf->map->max_x - 1)
				render_line(fdf, fdf->map->coord[x][y], \
					fdf->map->coord[x + 1][y]);
			if (y < fdf->map->max_y - 1)
				render_line(fdf, fdf->map->coord[x][y], \
					fdf->map->coord[x][y + 1]);
			x++;
		}
		y++;
	}
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
	init_mlx_image_cam(fdf);
	render_image(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image->image, 0, 0);
	mlx_string_put(fdf->mlx, fdf->win, 50, 100, 0XC70839, "PRESS 'ESC' TO CLOSE");
	mlx_key_hook(fdf->win, handle_esc, fdf);
	mlx_hook(fdf->win, 17, 0, &free_all, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}

/*
.fdf içeriği boş olduğunda ve yok_boyle_dosya.fdf veridiğmizde leak alıyoruzz

*/