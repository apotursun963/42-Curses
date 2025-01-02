
# include "push_swap.h"
#include <stdio.h>

/*
kullanmayada bilirsin çünkü son eklenen eleman top'ta olur ve sıralı bir şeklide olur
*/
// void    sort_2(t_list **stack_a, t_list **stack_b)
// {
//     if (stack_size(*stack_a) < 2)
//         return ;
    
//     printnl(*stack_a);
//     if ((*stack_a)->data > (*stack_a)->next->data)
//     {
//         swap_a(stack_a);
//     }
//     printf("sa\n");
//     printnl(*stack_a);
// }

void    Swap(t_list *first, t_list *second)
{
    int tmp = first->data;
    first->data = second->data;
    second->data = tmp;
}


void    selection_sort(t_list **stack_a, t_list **stack_b)
{
    t_list *first;
    t_list *second;
    int idx;

    idx = 0;
    first = *stack_a;
    while (first)
    {
        second = first->next;
        while (second)
        {
            if (first->data > second->data)
                Swap(first, second);      // ama bu swap fonksiyonu sadece ilk iki elemanı takas eder her zaan
            second = second->next;
        }
        first = first->next;
    }
}

void    sort_stack(t_list **stack_a, t_list **stack_b)
{

    printnl(*stack_a);

    selection_sort(stack_a, stack_b);

    printnl(*stack_a);
}
