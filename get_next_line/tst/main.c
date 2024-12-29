#include <stdio.h>
#include <fcntl.h>
#include "../src/get_next_line.h"

                        // "Reading line by line from file"
int main(void)
{
    int fd = open("rd_file", O_RDONLY);
    if (fd == -1)
    {
        perror("ERROR");
        return (1);
    }

    char    *one_line;
    while ((one_line = get_next_line(fd)) != NULL)
    {
        printf("%s", one_line);
        free(one_line);
    }
    close(fd);
    return (0);
}

                        // "Writing input data into file"
int main(void)          
{
    char buffer[1000];

    int bytes = read(0, buffer, 1000);
    (void)bytes;

    int fd = open("wr_file", O_WRONLY | O_APPEND, 0777);
    if (fd == -1)
    {
        perror("ERROR");
        return (1);
    }

    int idx = 0;
    while (buffer[idx])
        write(fd, &buffer[idx++], 1);
    close(fd);
    return (0);
}
                        // "Finding number of lines from file"
int main()              
{
    char buffer[1000];

    int fd = open("len_file", O_RDONLY);
    if (fd == -1)
    {
        perror("ERROR");
        return (1);
    }

    int bytes = 0;
    int index = 0;
    int len_of_lines = 0;
    while ((bytes = read(fd, buffer, 1)) > 0)
    {
        if (buffer[index] == '\n')
            len_of_lines++;
        continue ;
    }
    if (bytes == -1)
        perror("can't read");
    else
        printf("len of lines: %d\n", len_of_lines);
    close(fd);
    return (0);
}
