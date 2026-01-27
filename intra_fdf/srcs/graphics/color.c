/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:01:02 by atursun           #+#    #+#             */
/*   Updated: 2025/02/10 12:22:29 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

int	color_gradient(t_color *color, float progress)
{
	int	red;
	int	green;
	int	blue;

	red = color->delta_r * progress;
	if (red < -255)
		red = 0;
	else if (red > 255)
		red = 255;
	red = red << 16;
	green = color->delta_g * progress;
	if (green < -255)
		green = 0;
	else if (green > 255)
		green = 255;
	green = green << 8;
	blue = color->delta_b * progress;
	if (blue < -255)
		blue = 0;
	else if (blue > 255)
		blue = 255;
	return (color->start_color + red + green + blue);
}

int	get_color(t_color *color, int i_line, int line_size)
{
	float	progress;

	progress = (float) i_line / (float) line_size;
	return (color_gradient(color, progress));
}

t_color	*color_init(t_point start, t_point end)
{
	t_color	*color;

	color = malloc(sizeof(t_color));
	if (!color)
		return (NULL);
	color->start_color = start.color;
	color->start_r = (RED & start.color) >> 16;
	color->start_g = (GREEN & start.color) >> 8;
	color->start_b = (BLUE & start.color);
	color->end_color = end.color;
	color->end_r = (RED & end.color) >> 16;
	color->end_g = (GREEN & end.color) >> 8;
	color->end_b = (BLUE & end.color);
	color->delta_r = (color->end_r - color->start_r);
	color->delta_g = (color->end_g - color->start_g);
	color->delta_b = (color->end_b - color->start_b);
	return (color);
}

t_color	*color_pallet_init(int min_color, int max_color)
{
	t_color	*color;

	color = malloc(sizeof(t_color));
	if (!color)
		return (NULL);
	color->start_color = min_color;
	color->start_r = (RED & min_color) >> 16;
	color->start_g = (GREEN & min_color) >> 8;
	color->start_b = (BLUE & min_color);
	color->end_color = max_color;
	color->end_r = (RED & max_color) >> 16;
	color->end_g = (GREEN & max_color) >> 8;
	color->end_b = (BLUE & max_color);
	color->delta_r = (color->end_r - color->start_r);
	color->delta_g = (color->end_g - color->start_g);
	color->delta_b = (color->end_b - color->start_b);
	return (color);
}
