/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:33:37 by mikkayma          #+#    #+#             */
/*   Updated: 2025/07/25 14:08:07 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	error_msg(char *msg, t_cub *cub, int is_free)
{
	get_next_line(-1);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	if (is_free >= 4)
	{
		free_image(cub);
		mlx_destroy_display(cub->mlx.mlx);
		free(cub->mlx.mlx);
	}
	if (is_free >= 3)
		free_map(cub->map.map);
	if (is_free >= 2)
		free_texture(cub->texture);
	if (is_free >= 1)
		free(cub);
	exit(EXIT_FAILURE);
}

int	check_extension(char *file, char *ext)
{
	char	*res;
	int		file_len;

	file_len = ft_strlen(file);
	res = ft_strrchr(file, '.');
	if (!res || file_len <= 4 || ft_strncmp(res, ext, 5) != 0)
		return (1);
	if (file[file_len - 5] == '/')
		return (1);
	return (0);
}

static void	init_cub_tex(t_cub *cub)
{
	cub->texture.north = NULL;
	cub->texture.east = NULL;
	cub->texture.west = NULL;
	cub->texture.south = NULL;
	cub->mlx.win_data.image = NULL;
	cub->tex_data.bits_per_pixel = 0;
	cub->tex_data.endian = 0;
	cub->tex_data.size_line = 0;
	cub->tex_data.tex_height = 0;
	cub->tex_data.tex_width = 0;
	cub->tex_data.texture_data = 0;
}

static void	init_cub(t_cub *cub)
{
	cub->is_player = 0;
	cub->fc.ceiling_c.r = -1;
	cub->fc.ceiling_c.g = -1;
	cub->fc.ceiling_c.b = -1;
	cub->fc.floor_c.r = -1;
	cub->fc.floor_c.g = -1;
	cub->fc.floor_c.b = -1;
	cub->player.dirx = 0;
	cub->player.diry = 0;
	cub->plane_x = 0;
	cub->plane_y = 0;
	cub->map.map = NULL;
	cub->map.map_height = 0;
	cub->map.map_width = 0;
	init_cub_tex(cub);
	init_movement_state(cub);
}

int	main(int argc, char **argv)
{
	t_cub	*cub;

	if (argc != 2)
		error_msg("Too Or Missing Arguments", NULL, 0);
	if (check_extension(argv[1], ".cub") == 1)
		error_msg("Wrong map extansion", NULL, 0);
	cub = malloc(sizeof(t_cub));
	init_cub(cub);
	open_file(cub, argv[1]);
	if (BONUS)
		init_door(cub);
	cub->mlx.mlx = mlx_init();
	xpm_to_image(cub);
	if (BONUS)
	{		
		cub->minimap.cell_size = 15;
		render_bonus(cub);
		init_fps_counter(cub);
	}
	cub->mlx.win = mlx_new_window(cub->mlx.mlx, WIDTH, HEIGHT, "Cub3D");
	render_map(cub);
	setup_hooks(cub);
	mlx_loop(cub->mlx.mlx);
}
