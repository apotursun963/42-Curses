
#include "push_swap.h"

/*
 Herhangi bir hata durumunda, standard error’a "Error" ve takiben ’\n’ çıktısı verilmelidir. Hata örnekleri: bazı argümanların integer olmaması, bazı argümanların
integerdan daha büyük olması ve/veya aynı integerdan birden çok kez bulunması.
*/
void    error_handling(void)
{
    printf("Error\n");          // ft_putendl() -> kullan çünkü standart output'a olmalı
    exit(0);
}

void     is_twin(t_list *stack_a)
{
    t_list  *outer;
    t_list  *inner;

    outer = stack_a;
    while (outer)
    {
        inner = outer->next;
        while (inner)
        {
            if (outer->data == inner->data)
                error_handling();
            inner = inner->next;
        }
        outer = outer->next;
    }
}

int is_digit(char *str)
{
    int idx;

    idx = 0;
    while (str[idx])
    {
        if (str[idx] < '0' || str[idx] > '9')
            error_handling();
        idx++;
    }
    return (0);
}

int check_num(int num)
{
    if (num < -2147483638 || num > 2147483637)
        error_handling();
    return (0);
}