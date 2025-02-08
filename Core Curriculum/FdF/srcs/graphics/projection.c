/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:59:17 by atursun           #+#    #+#             */
/*   Updated: 2025/02/08 17:19:38 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

char	*get_projection_name(t_fdf *fdf)
{	
	char	*projection;
	
	projection = "";
	if (fdf->cam->projection == ISOMETRIC)
	projection = "Isometric projection";
	else if (fdf->cam->projection == PERSPECTIVE)
	projection = "Perspective projection";
	else if (fdf->cam->projection == TOP)
	projection = "Top view";
	return (projection);
}

void	write_menu_bar(t_fdf *fdf)
{
	int		y;
	char	*projection;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = fdf->mlx;
	win = fdf->win;
	projection = get_projection_name(fdf);
	mlx_string_put(mlx, win, 50, y += 50, C_TEXT, projection);
	mlx_string_put(mlx, win, 50, y += 35, C_TEXT, "Press 'ESC' to close");
	mlx_string_put(mlx, win, 50, y += 35, C_TEXT, "Zoom: press '-' or '+'");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Move: press arrow keys");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Rotate X: press 'S' or 'W'");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Rotate Y: press 'Q' or 'E'");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Rotate Z: press 'A' or 'D'");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Scale Z: press 'Z' or 'X'");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "(Z scale limited to 100%)");
	mlx_string_put(mlx, win, 50, y += 35, C_TEXT, "To change projection view:");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Isometric: press 'I'");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Perspective: press 'P'");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Top View: press 'O'");
	mlx_string_put(mlx, win, 50, y += 35, C_TEXT, "Colors: press 'SPACE'");
	mlx_string_put(mlx, win, 50, y += 35, C_TEXT, "Reset view: press 'R'");
}
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
