/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhandle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:00:20 by atursun           #+#    #+#             */
/*   Updated: 2025/02/08 18:55:05 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

void	key_translate(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_RIGHT)
		fdf->cam->move_x += 20;
	else if (keycode == KEY_LEFT)
		fdf->cam->move_x -= 20;
	else if (keycode == KEY_DOWN)
		fdf->cam->move_y += 20;
	else if (keycode == KEY_UP)
		fdf->cam->move_y -= 20;
}

void	key_scale(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_PLUS)
		fdf->cam->scale_factor += 1;
	else if (keycode == KEY_MINUS)
		fdf->cam->scale_factor -= 1;
	else if (keycode == KEY_Z && fdf->cam->scale_z > -1)
		fdf->cam->scale_z -= 0.1;
	else if (keycode == KEY_X && fdf->cam->scale_z < 1)
		fdf->cam->scale_z += 0.1;
}

void	key_rotate(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_S)
		fdf->cam->alpha -= (3 * ANG_1);
	else if (keycode == KEY_W)
		fdf->cam->alpha += (3 * ANG_1);
	else if (keycode == KEY_A)
		fdf->cam->gamma -= (3 * ANG_1);
	else if (keycode == KEY_D)
		fdf->cam->gamma += (3 * ANG_1);
	else if (keycode == KEY_Q)
		fdf->cam->beta -= (3 * ANG_1);
	else if (keycode == KEY_E)
		fdf->cam->beta += (3 * ANG_1);
}

void	key_project(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_P)
		fdf->cam->projection = PERSPECTIVE;
	else if (keycode == KEY_İ)
		fdf->cam->projection = ISOMETRIC;
	else if (keycode == KEY_O)
		fdf->cam->projection = TOP;
}

int	key_handle(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESC)
		free_all(fdf);
	else if (keycode == KEY_RIGHT || keycode == KEY_LEFT || keycode == KEY_UP \
		|| keycode == KEY_DOWN)
		key_translate(keycode, fdf);
	else if (keycode == KEY_PLUS || keycode == KEY_MINUS || keycode == KEY_Z \
		|| keycode == KEY_X)
		key_scale(keycode, fdf);
	else if (keycode == KEY_A || keycode == KEY_S || keycode == KEY_D \
		|| keycode == KEY_Q || keycode == KEY_W || keycode == KEY_E)
		key_rotate(keycode, fdf);
	else if (keycode == KEY_P || keycode == KEY_İ || keycode == KEY_O)
		key_project(keycode, fdf);
	else if (keycode == KEY_SPACE)
	{
		if (fdf->cam->color_pallet == FALSE)
			fdf->cam->color_pallet = TRUE;
		else
			fdf->cam->color_pallet = FALSE;
	}
	else if (keycode == KEY_R)
		reset(fdf);
	render(fdf);
	return (0);
}
