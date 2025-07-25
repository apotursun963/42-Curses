/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:33:37 by mikkayma          #+#    #+#             */
/*   Updated: 2025/07/22 19:16:35 by atursun          ###   ########.fr       */
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

// int	check_extension(char *file, char *ext)
// {
// 	char	*res;
// 	char	*filename;

// 	res = ft_strrchr(file, '.');	// String içinde son bulduğu karakterin pozisyonunu döndürür
// 	ft_putendl_fd(res, 1);
// 	filename = ft_strrchr(file, '/');
// 	ft_putendl_fd(filename, 1);
// 	if (filename)
// 		filename++;			// '/' karakterini atlayıp dosya adına geçiyorsunuz
// 	else
// 		filename = file;	 // '/' yoksa zaten dosya adı verilmiş demektir
// 	// Gizli dosya kontrolü (dosya adı . ile başlıyorsa)
// 	if (filename[0] == '.')
// 		return (1);
// 	// Uzantı kontrolü
// 	if (!res || ft_strncmp(res, ext, 4) != 0 || ft_strlen(file) <= 4)
// 		return (1);
// 	// Dosya adının sadece uzantıdan ibaret olmaması kontrolü
// 	if (res == filename)
// 		return (1);
// 	return (0);
// }

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
		error_msg("Too many arguments", NULL, 0);
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
		init_fps_counter(cub);		// FPS, bir görüntüde saniyede gösterilen kare sayısını ifade eden ve akıcılığı belirleyen ölçüdür
	}
	cub->mlx.win = mlx_new_window(cub->mlx.mlx, WIDTH, HEIGHT, "Cub3D");
	render_map(cub);
	setup_hooks(cub);
	mlx_loop(cub->mlx.mlx);
}
