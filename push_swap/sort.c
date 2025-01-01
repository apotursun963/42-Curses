
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


void    sort_stack(t_list **stack_a, t_list **stack_b)
{
    t_list  *head_a;
    t_list  *head_b;

    head_a = *stack_a;
    head_b = *stack_b;

    printf("%d\n", (*stack_a)->data);
    printf("%d\n", (*stack_a)->next->data);
    printf("%d\n", (*stack_a)->next->next->data);

    



    // printnl(*stack_a);
}
