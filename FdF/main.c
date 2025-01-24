

#include "minilibx-linux/mlx.h"
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



// typedef struct s_data
// {
//     void    *init_window;
//     void    *create_window;
//     int     color1;
//     int     color2;
// }   t_data;


// int    dest_window(int keycode)
// {
//     if (keycode == 65307)
//         exit(0);
//     return (0);
// }

// int main(int argc, char const *argv[])
// {
//     t_data  data;

//     data.init_window = mlx_init();
//     data.create_window = mlx_new_window(data.init_window, 1500, 1500, "FDF");
//     data.color1 = 0xff0000;
//     data.color2 = 0x0000ff;

//     // "y" ekseninde pixel çizer
//     for (int i=0; i < 1500; i++)
//         mlx_pixel_put(data.init_window, data.create_window, 750, i, data.color1);

//     // "x" ekseninde pixel çizer
//     for (int i=0; i < 1500; i++)
//         mlx_pixel_put(data.init_window, data.create_window, i, 750, data.color2);
    
//     // klavye tuşlarını ele almak için funcs
//     mlx_key_hook(data.create_window, dest_window, NULL);
    
//     // pencerenin süreki olarka açık kalması için
//     mlx_loop(data.init_window);
// }


// #include <stdlib.h>  // rand() fonksiyonu için
// #include <math.h>    // Animasyon için

// #define WIDTH 1000   // Pencere genişliği
// #define HEIGHT 1000  // Pencere yüksekliği

// typedef struct s_data {
//     void *mlx_ptr;  // MiniLibX bağlantısı
//     void *win_ptr;  // Pencere
//     int color1;     // İlk çizginin rengi
//     int color2;     // İkinci çizginin rengi
//     int offset;     // Animasyon için ofset
// } t_data;

// // Klavye olayı: ESC tuşuna basıldığında çıkış
// int handle_keypress(int keycode, t_data *data) {
//     if (keycode == 65307) // ESC tuşu (macOS'ta 53, Linux'ta farklı olabilir)
//         exit(0);
//     return 0;
// }

// // Animasyon ve dinamik renkler
// int render_frame(t_data *data) {
//     // Pencereyi temizle
//     mlx_clear_window(data->mlx_ptr, data->win_ptr);

//     // Dinamik renkler
//     data->color1 = rand() % 0xFFFFFF;
//     data->color2 = rand() % 0xFFFFFF;

//     // Yatay çizgi (dinamik renk ve animasyon)
//     for (int x = 0; x < WIDTH; x++) {
//         int y = (HEIGHT / 2) + sin((x + data->offset) * 0.05) * 50; // Sinüs dalgası hareketi
//         mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color1);
//     }

//     // Dikey çizgi (dinamik renk ve animasyon)
//     for (int y = 0; y < HEIGHT; y++) {
//         int x = (WIDTH / 2) + cos((y + data->offset) * 0.05) * 50; // Kosinüs dalgası hareketi
//         mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color2);
//     }

//     // Ofseti artır (animasyonun ilerlemesi için)
//     data->offset += 5;

//     return 0;
// }

// int main() {
//     // Veri yapısı
//     t_data data;
//     data.mlx_ptr = mlx_init(); // Grafik bağlamını başlat
//     data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "MiniLibX Gelişmiş"); // Pencere oluştur
//     data.color1 = 0xff0000;  // İlk renk (kırmızı)
//     data.color2 = 0x0000ff;  // İkinci renk (mavi)
//     data.offset = 0;         // Animasyon başlangıcı

//     // Klavye olayı
//     mlx_key_hook(data.win_ptr, handle_keypress, &data);

//     // Animasyon ve çerçeve güncelleme
//     mlx_loop_hook(data.mlx_ptr, render_frame, &data);

//     // MiniLibX döngüsü
//     mlx_loop(data.mlx_ptr);

//     return 0;
// }
