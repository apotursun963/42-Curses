/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:59:17 by atursun           #+#    #+#             */
/*   Updated: 2025/02/05 15:00:45 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*
İzometrik projeksiyon 3D nesneleri 2D düzlemde gösterirken, eksenler arasındaki açıyı 120 derece tutarak, 
tüm eksenlerde eşit ölçüler sağlar. Yani, x, y ve z eksenleri birbirinden eşit mesafeyle ve eşit derecede uzanır.
*/
void	isometric(t_line *line)
{
	t_point	new_start;
	t_point	new_end;

	new_start.x = (line->start.x - line->start.y) * cos(ANG_30);
	new_start.y = (line->start.x + line->start.y) * sin(ANG_30) - line->start.z;
	line->start.x = new_start.x;
	line->start.y = new_start.y;
	new_end.x = (line->end.x - line->end.y) * cos(ANG_30);
	new_end.y = (line->end.x + line->end.y) * sin(ANG_30) - line->end.z;
	line->end.x = new_end.x;
	line->end.y = new_end.y;
}

/*
Perspektif projeksiyonu, gerçek dünyada olduğu gibi, uzaktaki nesnelerin daha küçük, 
yakındaki nesnelerin ise daha büyük görünmesini sağlar. 
Bu tür projeksiyonlar, genellikle bir gözlemcinin bakış açısından, derinliği yansıtarak görüntü oluşturur.
*/
void	perspective(t_line *line)
{
	t_point	new_start;
	t_point	new_end;
	double	z;

	rotate_x(line, 3 * -ANG_45);
	z = line->start.z + line->transform_z;
	new_start.x = line->start.x / z;
	new_start.y = line->start.y / z;
	line->start.x = new_start.x;
	line->start.y = -new_start.y;
	z = line->end.z + line->transform_z;
	new_end.x = line->end.x / z;
	new_end.y = line->end.y / z;
	line->end.x = new_end.x;
	line->end.y = -new_end.y;
	scale(line, line->transform_z);
}

void	projection(t_cam *cam, t_line *line)
{
	if (cam->projection == ISOMETRIC)
		isometric(line);
	else if (cam->projection == PERSPECTIVE)
		perspective(line);
	else if (cam->projection == TOP)
		return ;
}
