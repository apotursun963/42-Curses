/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikkayma <mikkayma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:33:41 by mikkayma          #+#    #+#             */
/*   Updated: 2025/07/23 16:35:51 by mikkayma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "../cub3D.h"

# define MINIMAP_SCALE 10
# define MINIMAP_WIDTH 170
# define MINIMAP_HEIGHT 150

typedef struct s_cub	t_cub;
typedef struct s_render	t_render;
typedef struct s_tmp	t_tmp;

void	init_door(t_cub *cub);
int		door_lenght(t_cub *cub);
void	handle_door(t_cub *cub);
int		find_true_door(t_cub *cub, int x, int y);
void	render_door(t_cub *cub);
int		handle_mouse_move(int x, int y, t_cub *cub);
void	draw_background_for_door(t_cub *cub, t_render *render, int x);
int		check_wall_collisions(t_cub *cub, double x, double y, double radius);
void	fill_doors_manager_struct(t_cub *cub, int i, int x, int y);
void	play_door_sprite(t_cub *cub, t_render *render);
long	get_time_ms(void);
void	minimap(t_cub *cub);
void	free_door_sprite(t_cub *cub);
void	render_bonus(t_cub *cub);
void	init_fps_counter(t_cub *cub);
void	update_fps(t_cub *cub);
void	draw_fps(t_cub *cub);
void	draw_minimap(t_cub *cub);
void	draw_player_in_minimap(t_cub *cub, float dx, float dy, int player_size);
void	my_mlx_pixel_put_for_minimap(t_cub *cub, int x, int y, int color);
void	draw_rectangle(t_cub *cub, t_tmp tmp, int width, int height);
void	calculate_map_height_and_with(t_cub *cub);
void	draw_floor_and_ceiling(t_cub *cub, int x, int y);
int		calculate_the_walls_behind_the_door(t_cub *cub,
			t_render bg_render, int y);

#endif