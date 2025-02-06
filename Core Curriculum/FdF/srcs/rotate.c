/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:59:42 by atursun           #+#    #+#             */
/*   Updated: 2025/02/06 20:14:56 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"


/*
Doğruyu X ekseni etrafında döndürür.
X koordinatı sabit kalır.
Y ve Z koordinatları formüllere gore değişir:
*/
void	rotate_x(t_line *line, double angle)
{
	t_point	new_start;
	t_point	new_end;

	new_start.y = line->start.y * cos(angle) - line->start.z * sin(angle);
	new_start.z = line->start.y * sin(angle) + line->start.z * cos(angle);
	line->start.y = new_start.y;
	line->start.z = new_start.z;
	new_end.y = line->end.y * cos(angle) - line->end.z * sin(angle);
	new_end.z = line->end.y * sin(angle) + line->end.z * cos(angle);
	line->end.y = new_end.y;
	line->end.z = new_end.z;
}

/*
Doğruyu Y ekseni etrafında döndürür.
Y koordinatı sabit kalır.
X ve Z koordinatları formüllere gore değişir:
*/
void	rotate_y(t_line *line, double angle)
{
	t_point	new_start;
	t_point	new_end;

	new_start.x = line->start.x * cos(angle) + line->start.z * sin(angle);
	new_start.z = -line->start.x * sin(angle) + line->start.z * cos(angle);
	line->start.x = new_start.x;
	line->start.z = new_start.z;
	new_end.x = line->end.x * cos(angle) + line->end.z * sin(angle);
	new_end.z = -line->end.x * sin(angle) + line->end.z * cos(angle);
	line->end.x = new_end.x;
	line->end.z = new_end.z;
}

/*
Doğruyu Z ekseni etrafında döndürür.
Z koordinatı sabit kalır.
X ve Y koordinatları formüllere gore değişir:
*/
void	rotate_z(t_line *line, double angle)
{
	t_point	new_start;
	t_point	new_end;

	new_start.x = line->start.x * cos(angle) - line->start.y * sin(angle);
	new_start.y = line->start.x * sin(angle) + line->start.y * cos(angle);
	line->start.x = new_start.x;
	line->start.y = new_start.y;
	new_end.x = line->end.x * cos(angle) - line->end.y * sin(angle);
	new_end.y = line->end.x * sin(angle) + line->end.y * cos(angle);
	line->end.x = new_end.x;
	line->end.y = new_end.y;
}

void	rotate(t_cam *cam, t_line *line)
{
	rotate_x(line, cam->alpha);
	rotate_y(line, cam->beta);
	rotate_z(line, cam->gamma);
}
