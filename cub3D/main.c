#include "cub3D.h"

int check_extension(char *file, char *ext)
{
	char *res;

	res = ft_strrchr(file, '.');
	if (!res || ft_strncmp(res, ext, 4) != 0 || ft_strlen(file) <= 4)
		return (1);
	return (0);
}

void print_map(t_cub *cub)
{
	printf("%s", cub->texture.north);
	printf("%s", cub->texture.east);
	printf("%s", cub->texture.south);
	printf("%s\n", cub->texture.west);

	printf("%d %d %d\n", cub->fc.ceiling_c.r, cub->fc.ceiling_c.g, cub->fc.ceiling_c.b);
	printf("%d %d %d\n", cub->fc.floor_c.r, cub->fc.floor_c.g, cub->fc.floor_c.b);

	int i = 0;
	while (cub->map.map[i])
		ft_putstr_fd(cub->map.map[i++],1);
}


int main(int argc, char **argv)
{
	t_cub *cub = malloc(sizeof(t_cub));
	cub->map_index = 0;
	if (argc != 2 || check_extension(argv[1], ".cub") == 1)
		return (0);

	open_file(cub, argv[1]);
	print_map(cub);
	void *ptr = mlx_init();
	void *win = mlx_new_window(ptr, 850, 850, "Cub3D");


	(void)win;
	mlx_loop(ptr);
}
