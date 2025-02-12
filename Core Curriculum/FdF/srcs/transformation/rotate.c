/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:59:42 by atursun           #+#    #+#             */
/*   Updated: 2025/02/10 12:24:31 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

void	rotate_x(t_line *line, double alpha)
{
	t_point	new_start;
	t_point	new_end;

	new_start.y = line->start.y * cos(alpha) - line->start.z * sin(alpha);
	new_start.z = line->start.y * sin(alpha) + line->start.z * cos(alpha);
	line->start.y = new_start.y;
	line->start.z = new_start.z;
	new_end.y = line->end.y * cos(alpha) - line->end.z * sin(alpha);
	new_end.z = line->end.y * sin(alpha) + line->end.z * cos(alpha);
	line->end.y = new_end.y;
	line->end.z = new_end.z;
}

void	rotate_y(t_line *line, double beta)
{
	t_point	new_start;
	t_point	new_end;

	new_start.x = line->start.x * cos(beta) + line->start.z * sin(beta);
	new_start.z = -line->start.x * sin(beta) + line->start.z * cos(beta);
	line->start.x = new_start.x;
	line->start.z = new_start.z;
	new_end.x = line->end.x * cos(beta) + line->end.z * sin(beta);
	new_end.z = -line->end.x * sin(beta) + line->end.z * cos(beta);
	line->end.x = new_end.x;
	line->end.z = new_end.z;
}

void	rotate_z(t_line *line, double gamma)
{
	t_point	new_start;
	t_point	new_end;

	new_start.x = line->start.x * cos(gamma) - line->start.y * sin(gamma);
	new_start.y = line->start.x * sin(gamma) + line->start.y * cos(gamma);
	line->start.x = new_start.x;
	line->start.y = new_start.y;
	new_end.x = line->end.x * cos(gamma) - line->end.y * sin(gamma);
	new_end.y = line->end.x * sin(gamma) + line->end.y * cos(gamma);
	line->end.x = new_end.x;
	line->end.y = new_end.y;
}

void	rotate(t_cam *cam, t_line *line)
{
	rotate_x(line, cam->alpha);
	rotate_y(line, cam->beta);
	rotate_z(line, cam->gamma);
}
