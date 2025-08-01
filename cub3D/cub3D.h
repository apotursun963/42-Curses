/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:52:05 by mikkayma          #+#    #+#             */
/*   Updated: 2025/07/25 11:52:01 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H 

# include "bonus/cub3D_bonus.h"
# include "libs/libft/libft.h"
# include "libs/mlx/mlx.h"
# include <fcntl.h>
# include <math.h>

# define WIDTH 800
# define HEIGHT 600
# define MOVE_SPEED 0.02
# define ROT_SPEED 0.02

# define KEY_W 119
# define KEY_A 97 
# define KEY_S 115
# define KEY_D 100
# define KEY_E 101
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307

# ifndef BONUS
#  define BONUS 0
# endif

typedef struct s_tmp
{
	int	start_x;
	int	start_y;
	int	color;
}	t_tmp;

typedef struct s_fps
{
	long	last_time;
	int		frame_count;
	int		fps;
	char	fps_text[20];
}	t_fps;

typedef struct s_door
{
	int			door_x;
	int			door_y;
	int			is_open;
	int			is_opening;
	int			is_closing;
	int			door_frame;
	long		time;
}	t_door;

typedef struct s_minimap
{
	int		cell_size;
	int		offset_x;
	int		offset_y;
	int		player_map_px;
	int		player_map_py;
	void	*mini_image;
	char	*data;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_minimap;

typedef struct s_texture
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
}	t_texture;

typedef struct s_rgb
{
	int				r;
	int				g;
	int				b;
	unsigned int	colour;
}	t_rgb;

typedef struct s_fc
{
	t_rgb	floor_c;
	t_rgb	ceiling_c;
}	t_fc;

typedef struct s_map
{
	char	**map;
	int		map_height;
	int		map_width;
}	t_map;

typedef struct s_player
{
	double	dirx;
	double	diry;
	double	posx;
	double	posy;
}	t_player;

typedef struct s_tex_data
{
	void	*image;
	char	*texture_data;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		tex_width;
	int		tex_height;
}	t_tex_data;

typedef struct s_door_manager
{
	t_tex_data	frames[8];
	t_door		*door;
	int			door_len;
}	t_doors_manager;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_tex_data	win_data;
}	t_mlx;

typedef struct s_render
{
	int			is_door;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	double		perp_wall_dist;
	int			line_height;
	int			draw_start;
	int			draw_end;
	t_tex_data	*selected_texture;
}	t_render;

typedef struct s_cub
{
	double			plane_x;
	double			plane_y;
	int				is_player;
	t_fps			fps_counter;
	t_doors_manager	doors_manager;
	t_texture		texture;
	t_map			map;
	t_fc			fc;
	t_player		player;
	t_mlx			mlx;
	t_tex_data		tex_data;
	t_tex_data		north;
	t_tex_data		west;
	t_tex_data		south;
	t_tex_data		east;
	t_minimap		minimap;
	int				move_forward;
	int				move_backward;
	int				move_left;
	int				move_right;
	int				rotate_left;
	int				rotate_right;
	int				mouse_rotate_left;
	int				mouse_rotate_right;
}	t_cub;

void	xpm_to_image(t_cub *cub);
t_tmp	fill_tmp(int start_x, int start_y, int color);
void	free_image(t_cub *cub);
int		is_player(char p);
int		get_num_lines(char **map);
int		is_valid_position(t_cub *cub, double x, double y);

void	painting_sky_and_ground(t_cub *cub);
void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color);
void	select_texture(t_cub *cub, t_render *render);
void	draw_texture(t_cub *cub, t_render *render, int x, int y);
void	move_ray(t_render *render);
void	check_map_around_wall(t_cub *cub);
void	continue_ray_after_door(t_cub *cub, t_render *render);

void	validate_map_line(char *line, t_cub *cub);
void	set_coor_and_pos(t_cub *cub, char *line, int i);
int		map_reel_lenght(char *file, t_cub *cub);
int		skip_whitespaces(char *line, int i);
void	read_texture(t_cub *cub, int fd, int j);
int		check_texture(t_cub *cub);
void	open_file(t_cub *cub, char *file);
int		check_extension(char *file, char *ext);
void	check_map(t_cub *cub);
void	render_map(t_cub *cub);
void	read_fc_rgb(t_cub *cub, int fd);
void	error_msg(char *msg, t_cub *cub, int is_free);
void	free_texture(t_texture texture);
void	free_map(char **map);
void	init_movement_state(t_cub *cub);
void	setup_hooks(t_cub *cub);
void	move_player(t_cub *cub);
int		handle_keypress(int key, t_cub *cub);
int		handle_keyrelease(int key, t_cub *cub);
int		handle_close(t_cub *cub);
void	rotate_player(t_cub *cub, double angle);
int		unknown_line_check(t_cub *cub, char *line);
void	calculate_wall_distance_and_height(t_cub *cub, t_render *render);
void	check_the_door_after_the_door(t_cub *cub, t_render *render);
#endif