#include "minilibx/mlx.h"
#include <stdlib.h>

// Adımlar
// 1. ilk önce dosya uzantısı kontorl et .fdf
// 2. Verileri parse et. 2D haritaları nasıl ele alacağını belirle
// 3. sonra çizgi çizme algoritmasını yap noktaları birleştir. (Bresenham’s Line Drawing Algorithm)
// 4. basit bir kare çiz

// gcc main.c libmlx.a -lX11 -lXext -lm -o fdf

int    dst_win(int keycode)
{
    if (keycode == 65307)               // bunları makro olarak tanımla
        exit(0);
    return (0);
}

int main(int argc, char const *argv[])
{
    void    *mlx;
    void    *mlx_win;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1000, 1000, "FDF");

    mlx_pixel_put(mlx, mlx_win, 500, 500, 0x00FF0000);      // bu fonksiyon çok yavaş çalışıyor düzlet
    mlx_key_hook(mlx_win, dst_win, NULL);
    mlx_loop(mlx);
    return (0);
}
