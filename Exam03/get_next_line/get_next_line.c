
# include "get_next_line.h"

char    *ft_strdup(char *str)
{
    char *dst;
    int i = 0;

    while (str[i])
        i++;
    dst = malloc(i + 1);
    i = -1;
    while (str[++i])
        dst[i] = str[i];
    dst[i] = '\0';
    return (dst);
}

char    *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE];    // okunan veriyi eklenecek tampon
    static int  buffer_readed;          // read fonksiyonuyla okuduğu byte sayısını döndüryüor
    static int  buffer_pos;             // buffer içinde hangi konumda olduğumuzu takip eder.
    char        line[70000];            // Okunan satırı saklamak için bir dizi tanımlanır.

    int i = 0;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    while (1)
    {
        // Eğer tamponun tamamı işlendiyse yeni veri okunur.
        if (buffer_pos >= buffer_readed)
        {
            buffer_readed = read(fd, buffer, BUFFER_SIZE);
            buffer_pos = 0;
            if (buffer_readed <= 0)
                break ;
        }
        line[i++] = buffer[buffer_pos++];
        if (line[i - 1] == '\n')
            break;
    }
    line[i] = '\0';
    if (i == 0)     // yani hiç bir veri okunmamışsa
        return (NULL);
    return (ft_strdup(line));
}


// #include <fcntl.h>
// #include <stdio.h>
// int main(int argc, char const *argv[])
// {
//     int fd = open("test.txt", O_RDONLY, 0777);
//     char *line;

//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s", line);
//         free(line);
//     }
//     close(fd);
//     return 0;
// }
