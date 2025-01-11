
# include <stdio.h>
# include <unistd.h>

/*
\r (carriage return), bir metin akışında imleci aynı satırın başına döndürmek için kullanılır. 
Yeni bir satıra geçmeden, mevcut satırın başından itibaren yazmaya devam etmeyi sağlar.
\r, "satırın başına dön ve oradan yazmaya başla" demektir.
*/

void    printchr(char chr)
{
    printf("%c", chr);
    printf("\033[1D");      // Move left X column;
    fflush(0);
    usleep(200000);

}

int main()
{
    printf("animation: ");
    while (1)
    {
        printchr('\\');
        printchr('-');
        printchr('/');
        printchr('|');
    }
}
