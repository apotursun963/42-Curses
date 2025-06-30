



#ifndef CUB3D_H
#define CUB3D_H 


#include "libft/libft.h"
#include <fcntl.h>
#include "mlx/mlx.h"


#include <stdio.h>  // sil

typedef struct s_texture
{
    char *north;
    char *south;
    char *west;
    char *east;
}   t_texture;

typedef struct s_rgb
{
    int r;
    int g;
    int b;
}   t_rgb;

typedef struct s_fc
{
    t_rgb floor_c;
    t_rgb ceiling_c;
}   t_fc;    


typedef struct s_map
{
    char **map;

}   t_map;

typedef struct s_cub
{
    int       len_of_file;
    int       is_player;
    int        map_index;
    t_texture texture;
    t_map      map;
    t_fc      fc;
    

}   t_cub;    

void read_texture(t_cub *cub, int fd);
int check_texture(t_cub *cub);
void open_file(t_cub *cub, char *file);
int check_extension(char *file, char *ext);
void	check_map(t_cub *cub);



#endif