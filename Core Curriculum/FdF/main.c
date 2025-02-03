/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:26:36 by atursun           #+#    #+#             */
/*   Updated: 2025/02/03 14:29:57 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "inc/fdf.h"


void read_file(int fd, t_map *map)
{
    char *line;
    int y = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        int x = 0;
        char *token = strtok(line, " ");
        while (token)
        {
            map->data[y][x] = atoi(token);
            x++;
            token = strtok(NULL, " ");
        }
        free(line);
        y++;
    }
}

t_map *parse_inputs(char *filename)
{
    int fd;
    t_map *map = malloc(sizeof(t_map));
    if (!map) {
        exit(1);
    }
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        free(map);
        exit(1);
    }
    map->height = 0;
    map->width = 0;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((line = get_next_line(fd)) != NULL)
    {
        map->height++;
        int current_width = 0;
        char *token = strtok(line, " ");
        while (token)
        {
            current_width++;
            token = strtok(NULL, " ");
        }
        if (current_width > map->width)
            map->width = current_width;
        free(line);
    }
    close(fd);
    fd = open(filename, O_RDONLY);
    map->data = malloc(sizeof(int *) * map->height);
    if (!map->data)
    {
        free(map);
        exit(1);
    }
    for (int i = 0; i < map->height; i++)
    {
        map->data[i] = malloc(sizeof(int) * map->width);
        if (!map->data[i])
        {
            free(map->data);
            free(map);
            exit(1);
        }
    }
    read_file(fd, map);
    close(fd);
    return (map);
}

void bresenham_line(int x0, int y0, int z0, int x1, int y1, int z1, t_fdf *fdf)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int dz = abs(z1 - z0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int sz = (z0 < z1) ? 1 : -1;
    int err = dx - dy - dz;

    while (1)
    {
        int color = 0x00FF00;
        mlx_pixel_put(fdf->mlx, fdf->mlx_win, x0, y0, color);

        if (x0 == x1 && y0 == y1)
            break;

        int e2 = err * 2;
        if (e2 > -dy) 
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) 
        {
            err += dx;
            y0 += sy;
        }
        if (e2 < dz) 
        {
            err += dz;
            z0 += sz;
        }
    }
}

void draw_map(t_fdf *fdf, t_map *map)
{
    for (int y = 0; y < map->height - 1; y++)
    {
        for (int x = 0; x < map->width - 1; x++)
        {
            int z0 = map->data[y][x];
            int z1 = map->data[y + 1][x];
            int z2 = map->data[y][x + 1];
            int z3 = map->data[y + 1][x + 1];
            bresenham_line(x * 10, y * 10, z0, x * 10, (y + 1) * 10, z1, fdf);
            bresenham_line(x * 10, y * 10, z0, (x + 1) * 10, y * 10, z2, fdf);
            bresenham_line((x + 1) * 10, y * 10, z2, (x + 1) * 10, (y + 1) * 10, z3, fdf);
            bresenham_line(x * 10, (y + 1) * 10, z1, (x + 1) * 10, (y + 1) * 10, z3, fdf);
        }
    }
}

int main(int argc, char **argv)
{
    t_fdf fdf;
    t_map *map;

    if (argc != 2 || !is_valid_filename(argv[1]))
        exit(1);
    map = parse_inputs(argv[1]);
    fdf.mlx = mlx_init();
    fdf.mlx_win = mlx_new_window(fdf.mlx, WIDTH, HEIGHT, "FDF");
    draw_map(&fdf, map);
    mlx_loop(fdf.mlx);
    for (int i = 0; i < map->height; i++)
        free(map->data[i]);
    free(map->data);
    free(map);
    return 0;
}


