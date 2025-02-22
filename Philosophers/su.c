

#include <unistd.h>
#include <pthread.h>
#include <stdio.h>


void *numbers(void *arg)
{
    for (int i=1; i <= 5; i++)
    {
        printf("%d\n", i);
        usleep(500);
    }
    return (NULL);
}

void *letters(void *arg)
{
    for (int i='A'; i <= 'E' ; i++)
    {
        printf("%c\n", i);
        usleep(500);
    }
    return (NULL);
}


/*
Biz burada eğer thread kullanmasaydık ilk önce bütün sayıları yazdıktan sonra harfleri yazardı 
yani bir fonksiynun işi bittikten sonra diğer fonkisyon çalışırdı 
ama biz fonksiyonları thread olarak çağırdığımızda her iki fonksiyon (thread)
paralel olarak çalışır yani bir fonksiyon diğer fonksiyonun bitmesini beklemez 
aynı anda çalışırlar. 

thread kullanmadan ve kullanarak
1           1
2           A
3           B
4           2
5           3
A           C
B           D
C           4
D           E
E           5

*/
int main(int argc, char const *argv[])
{
    pthread_t   t1, t2;

    pthread_create(&t1, NULL, numbers, NULL);
    pthread_create(&t2, NULL, letters, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}
