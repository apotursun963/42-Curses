


# include "../include/push_swap.h"

void    free_args(char **arguments)
{
    int  idx;

    idx = 0;
    while (arguments[idx])
        free(arguments[idx++]);
    free(arguments);
}

void    free_all_stack(t_stack **stack_a, t_stack **stack_b)
{
    t_stack  *tmp_node;

    while (*stack_a)
    {
        tmp_node = *stack_a;        // eğer .data yaparsan sorun alırsın çünkü data "int" türünde ama tmp "t_stack *"
        *stack_a = (*stack_a)->next;
        free(tmp_node);
    }
	while (*stack_b)
    {
        tmp_node = *stack_b;
        *stack_b = (*stack_b)->next;
        free(tmp_node);
    }
    free(stack_a);
    free(stack_b);
}
