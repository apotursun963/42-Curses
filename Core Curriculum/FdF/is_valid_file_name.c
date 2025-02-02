
# include <stdio.h>
# include <string.h>


int main(int argc, char **argv)
{
    char *file_name = argv[1];
    char *res = ft_strrchr(file_name, '.');

    if (!ft_strcmp(res, ".fdf"))
        exit(1);
    return 0;
}
