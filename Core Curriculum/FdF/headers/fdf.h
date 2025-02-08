/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:01:38 by atursun           #+#    #+#             */
/*   Updated: 2025/02/08 18:54:41 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include "keys.h"
# include "colors.h"
# include "../libs/mlx_linux/mlx.h"
# include "../libs/libft/libft.h"


/*
** Tek nokta yapısı: haritadaki her nokta için x, y, z ve renk değerleri.
*/
typedef struct s_point
{
	float	x;				// x eksenindeki konumunu belirtir. noktanın "yatay" düzlemdeki yerini temsil eder
	float	y;				// y eksenindeki konumunu belirtir. noktanın "dikey" düzlemdeki yerini ifade eder.
	float	z;				// z eksenindeki konumunu belirtir.  3D koordinat sisteminde noktanın "derinliğini" gösterir.
	int		color;			// noktanın görsel özelliğini ifade eder. Genellikle, renk değeri z noktasından sonra gelir
}	t_point;					// Bazı durumlarda, bazı noktalar renk içermez. Bu durumda, nokta için bir varsayılan renk ayarlamalısın.

/*
** Harita veri yapısı: ayrıştırılan harita hakkında bilgi tutar, örneğin bir matris ile 
** koordinatlarındaki noktası, toplam genişlik, derinlik ve yükseklik değerleri geçti. 
*/
typedef struct s_map
{
	t_point	**coordinates;
	int		max_x;
	int		max_y;
	int		max_z;
	int		min_z;
}	t_map;

/*
** Yazdırılmakta olan geçerli (şuanki) satır
*/
typedef struct s_line
{
	t_point	start;
	t_point	end;
	float	transform_z;
}	t_line;

/*
Renk yapısı (struct): çizgi için geçerlidir.
*/
typedef struct s_color
{
	int	start_color;
	int	start_r;
	int	start_g;
	int	start_b;
	int	end_color;
	int	end_r;
	int	end_g;
	int	end_b;
	int	delta_r;
	int	delta_g;
	int	delta_b;
}	t_color;

/*
Görüntü veri yapısı: MiniLibX tarafından sağlanan görüntü işaretçileri ile son 
görüntünün yazdırılacağı tampon işaretçisi ve tampon içine aktarılacak mevcut 
satır hakkında bilgi tutar.
*/
typedef struct s_image
{
	void	*image;
	int		pixel_bits;				// Her pikselin kaç bit olduğu (renk derinliği).
	int		line_bytes;				// Her satırın kaç byte uzunluğunda olduğu.
	int		endian;
	char	*buffer;
	t_line	*line;
}	t_image;

/*
Kamera veri yapısı: Görüntülenen görüntü hakkında, projeksiyon türü, ölçek, 
çeviri delta'sı ve üç eksende dönüş için açı değerleri gibi bilgileri tutar.
*/
typedef struct s_cam
{
	int		projection;
	int		color_pallet;
	float	scale_factor;
	float	scale_z;
	float	move_x;
	float	move_y;
	double	alpha;
	double	beta;
	double	gamma;
}	t_cam;

/*
FDF ana veri yapısı: FDF'nin çalışması için gerekli tüm bilgileri tutar,
*/
typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	int		win_x;
	int		win_y;
	t_map	*map;
	t_image	*image;
	t_cam	*cam;
}	t_fdf;

# define NAME	 		"FDF"
# define WIDTH			2000
# define HEIGHT			1500
# define MAX_PIXEL		1000
# define LINE_DEF		WHITE
# define BACK_DEF		BLACK
# define C_TEXT			WHITE
# define HEXADECM		"0123456789abcdef"
# define ANG_1			0.01745329
# define ANG_30			0.52359877
# define ANG_45			0.78539816

enum e_projection
{
	ISOMETRIC,
	PERSPECTIVE,
	TOP
};

enum e_bool
{
	FALSE,
	TRUE
};


t_map	*read_map(char *file_name);
int 	is_file_extension_valid(char *filename);
t_fdf	*init_fdf(char *file_name);
t_map	*init_map(void);
t_image	*init_image(void *mlx);
t_line	*init_line(t_point start, t_point end, t_fdf *fdf);
t_cam	*init_cam(t_map *map);
t_point	**init_coordinates(int width, int depth);
void	center_to_origin(t_map *map);
float	scale_to_fit(t_map *map);
void	reset(t_fdf *fdf);
int		free_all(t_fdf *fdf);
void	free_map(t_fdf *fdf);
t_color	*color_init(t_point start, t_point end);
t_color	*color_pallet_init(int min_color, int max_color);
float	absolute(float nbr);
float	max(float a, float b);
float	min(float a, float b);
int		render(t_fdf *fdf);
void	bresenham(t_fdf *fdf, t_point start, t_point end);
void	pixel_to_image(t_image *image, float x, float y, int color);
void	clear_image(t_image *image);
void	write_menu_bar(t_fdf *fdf);
int		get_color(t_color *color, int i_line, int line_size);
void	rotate(t_cam *cam, t_line *line);
void	rotate_x(t_line *line, double angle);
void	rotate_y(t_line *line, double angle);
void	rotate_z(t_line *line, double angle);
void	projection(t_cam *cam, t_line *line);
void	scale(t_line *line, int scale_factor);
void	translate(t_line *line, int move_x, int move_y);
int		key_handle(int keycode, t_fdf *fdf);

#endif