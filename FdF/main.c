

#include "minilibx/mlx.h"
#include <stdlib.h>

// gcc main.c libmlx.a -lX11 -lXext -lm -o fdf


int    dest_window(int keycode)
{
    if (keycode == 65307)
        exit(0);
    return (0);
}

int main(int argc, char const *argv[])
{
    void    *init_window = mlx_init();
    void    *create_window = mlx_new_window(init_window, 1500, 1500, "FdF");

    // "y" ekseninde pixel çizer
    for (int i=0; i < 1500; i++)
        mlx_pixel_put(init_window, create_window, 750, i, 0xff0000);

    // "x" ekseninde pixel çizer
    for (int i=0; i < 1500; i++)
        mlx_pixel_put(init_window, create_window, i, 750, 0x0000ff);
    
    // klavye tuşlarını ele almak için funcs
    mlx_key_hook(create_window, dest_window, NULL);
    
    // pencerenin süreki olarka açık kalması için
    mlx_loop(init_window);
}
