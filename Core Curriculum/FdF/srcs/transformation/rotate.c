/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:59:42 by atursun           #+#    #+#             */
/*   Updated: 2025/02/08 17:19:42 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

/*
Doğruyu X ekseni etrafında döndürür.
X koordinatı sabit kalır.
Y ve Z koordinatları formüllere gore değişir:
*/
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

/*
Doğruyu Y ekseni etrafında döndürür.
Y koordinatı sabit kalır.
X ve Z koordinatları formüllere gore değişir:
*/
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

/*
Doğruyu Z ekseni etrafında döndürür.
Z koordinatı sabit kalır.
X ve Y koordinatları formüllere gore değişir:
*/
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
