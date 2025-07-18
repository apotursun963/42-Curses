/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikkayma <mikkayma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:17:53 by mikkayma          #+#    #+#             */
/*   Updated: 2025/07/10 19:11:46 by mikkayma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	init_fps_counter(t_cub *cub)
{
	cub->fps_counter.last_time = get_time_ms();
	cub->fps_counter.frame_count = 0;
	cub->fps_counter.fps = 0;
	ft_strlcpy(cub->fps_counter.fps_text, "FPS: 0",
		sizeof(cub->fps_counter.fps_text));
}

void	update_fps(t_cub *cub)
{
	long	current_time;
	long	elapsed_time;
	char	*fps_str;

	current_time = get_time_ms();
	cub->fps_counter.frame_count++;
	elapsed_time = current_time - cub->fps_counter.last_time;
	if (elapsed_time >= 1000)
	{
		cub->fps_counter.fps
			= (cub->fps_counter.frame_count * 1000) / elapsed_time;
		ft_strlcpy(cub->fps_counter.fps_text, "FPS: ",
			sizeof(cub->fps_counter.fps_text));
		fps_str = ft_itoa(cub->fps_counter.fps);
		if (fps_str)
		{
			ft_strlcat(cub->fps_counter.fps_text, fps_str,
				sizeof(cub->fps_counter.fps_text));
			free(fps_str);
		}
		cub->fps_counter.frame_count = 0;
		cub->fps_counter.last_time = current_time;
	}
}

void	draw_fps(t_cub *cub)
{
	mlx_string_put(cub->mlx.mlx, cub->mlx.win,
		WIDTH - 60, 20, 0xFFFFFF, cub->fps_counter.fps_text);
}
