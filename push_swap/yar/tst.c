

void    increase(int *number)
{
    *number = 10;
}

#include <stdio.h>
int main(int argc, char const *argv[])
{
    int num = 5;
    increase(&num);
    printf("%d\n", num);
    return 0;
}
    