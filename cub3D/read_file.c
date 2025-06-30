/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:35:00 by atursun           #+#    #+#             */
/*   Updated: 2025/06/30 16:38:19 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void read_fc_rgb(t_cub *cub, int fd)
{
    char *line = get_next_line(fd);
    char *tmp;
    char **double_tmp;
	int i = 0;
    while (line != NULL && i != 2)
    {
		cub->map_index++;
        if (line[0] == 'F' && line[1] == ' ')
        {
            tmp = ft_strdup(line + 2);
            double_tmp = ft_split(tmp, ',');
            if (double_tmp[0] && double_tmp[1] && double_tmp[2]) 
			{
                cub->fc.floor_c.r = ft_atoi(double_tmp[0]);
                cub->fc.floor_c.g = ft_atoi(double_tmp[1]);
                cub->fc.floor_c.b = ft_atoi(double_tmp[2]);
            }
            free(tmp);
            free(double_tmp[0]);
            free(double_tmp[1]);
            free(double_tmp[2]);
            free(double_tmp);
			i++;
        }
        if (line[0] == 'C' && line[1] == ' ')
        {
            tmp = ft_strdup(line + 2);
            double_tmp = ft_split(tmp, ',');
            if (double_tmp[0] && double_tmp[1] && double_tmp[2])
            {
                cub->fc.ceiling_c.r = ft_atoi(double_tmp[0]);
                cub->fc.ceiling_c.g = ft_atoi(double_tmp[1]);
                cub->fc.ceiling_c.b = ft_atoi(double_tmp[2]);
            }
            free(tmp);
            free(double_tmp[0]);
            free(double_tmp[1]);
            free(double_tmp[2]);
            free(double_tmp);
            i++;
        }
        if (line)
            free(line);
        line = get_next_line(fd);
    }
    // close(fd);
}

void validate_map_line(char *line)
{
    int has_content = 0;

    int i = 0;
    while (line[i])
    {
    
        if (!(line[i] == 'S' || line[i] == 'N' || line[i] == 'E' || line[i] == 'W'
            || line[i] == '0' || line[i] == '1' || line[i] == '\n' || line[i] == '\t' || line[i] == ' '))
        {
            ft_putendl_fd("Error: unknown character", 1);
            exit(EXIT_FAILURE);
        }
        i++;
    }
    if ((line[0] == ' ' || line[0] == '\t' || line[0] == '\n') && !ft_strchr(line, '1'))
            has_content = 1;
    if (has_content == 1)
    {
        ft_putendl_fd("Error: Empty or whitespace-only line in map", 1);
        exit(EXIT_FAILURE);
    }
}

void read_map(t_cub *cub, int fd)
{
    int i;
    char *tmp = get_next_line(fd);

    
    while (tmp)
    {
        if (!ft_strchr(tmp, '1'))
        {
            free(tmp);
            tmp = get_next_line(fd);
            continue;
        }
        break;
    }
    i = 0;
    int map_start_i = cub->len_of_file - cub->map_index;
    cub->map.map = malloc(sizeof(char *) * (map_start_i + 3));
    while (tmp != NULL && tmp[0] != '\0')
    {
        validate_map_line(tmp); // Validate each line of the map
        if (ft_strchr(tmp, 'N') || ft_strchr(tmp, 'S') ||
            ft_strchr(tmp, 'W') || ft_strchr(tmp, 'E'))
            cub->is_player++;
        if (ft_strchr(tmp, '1'))
            cub->map.map[i++] = ft_strdup(tmp);
        free(tmp);
        tmp = get_next_line(fd);
    }
    if (cub->is_player != 1)
    {
        ft_putendl_fd("Error: There are Multiplayer Or palyer number is 0", 1);
        exit(EXIT_FAILURE);
    }
    cub->map.map[i] = NULL;
    close(fd);
}

void read_file(t_cub *cub, char *file)
{
    int fd = open(file, O_RDONLY);
	read_texture(cub, fd);
    int fd2 = open(file, O_RDONLY);
	read_fc_rgb(cub, fd2);
	read_map(cub, fd);
}

void open_file(t_cub *cub, char *file)
{
	int counter = 0;
	int fd = open(file, O_RDONLY);
	if (fd == -1)
		return ;
	
	char *line = get_next_line(fd);
	while (line != NULL)
	{
		counter++;
		free(line);
		line = get_next_line(fd);
	}
	cub->len_of_file = counter;
	close(fd);
	read_file(cub, file);
	check_texture(cub);
    check_map(cub);
}
