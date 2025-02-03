/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:21:29 by atursun           #+#    #+#             */
/*   Updated: 2025/02/03 14:20:40 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <errno.h>
# include <stdbool.h>
# include <limits.h>
# include "../minilibx/mlx.h"
# include "../libs/libft/libft.h"
# include "../libs/gnl/get_next_line.h"

# define WIDTH      1000
# define HEIGHT     1000
# define FILE_ERROR     "The specified file cannot be opened."


typedef struct s_point3d
{
	double	x;
	double	y;
	double	z;
	int		mapcolor;
	int		zcolor;
}				t_point3d;

typedef struct s_point2d
{
	int		x;
	int		y;
	int		z;
	int		rgba;
}			t_point2d;

typedef struct s_map
{
	int				rows;
	int				cols;
	int				high;
	int				low;
	bool			use_zcolor;
	double			x_offset;
	double			y_offset;
	double			interval;
	double			alpha;
	double			beta;
	double			xrotate;
	double			yrotate;
	double			zrotate;
	double			zoom;
	double			zscale;
	t_point3d		**grid3d;
	t_point2d		**grid2d;
}					t_map;

typedef struct s_fdf
{
	mlx_t		*mlx;
	t_map		*map;
	mlx_image_t	*image;
}				t_fdf;




int     is_valid_filename(char *file);

#endif