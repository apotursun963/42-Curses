

// /*-----------------------------------------------*/

// /*test push*/
// # include "../push_swap.h"

// void    test_push(t_stack **stack, int value)
// {
//     t_stack  *new = (t_stack *)malloc(sizeof(t_stack));
//     if (!new) return ;

//     new->data = value;
//     new->next = *stack;
//     *stack = new;
// }

// // actions tester
// int main(int argc, char *argv[])
// {
//     t_stack  *stack_a;
//     t_stack  *stack_b;

//     // push to stack_a
//     test_push(&stack_a, 1);
//     test_push(&stack_a, 2);
//     test_push(&stack_a, 3);
//     test_push(&stack_a, 4);
//     test_push(&stack_a, 5);

//     // print stack_a
//     ft_printf("stack_a: \n");
//     printnl(stack_a);

//     // sa
//     swap_a(&stack_a);
//     printnl(stack_a);

//     // pb
//     push_b(&stack_a, &stack_b);
//     push_b(&stack_a, &stack_b);
//     printnl(stack_a);
//     ft_printf("stack_b: \n");
//     printnl(stack_b);

//     // ra | rb
//     ft_printf("stack_a: \n");
//     rotate_a(&stack_a);
//     printnl(stack_a);

//     ft_printf("stack_b: \n");
//     rotate_b(&stack_b);
//     printnl(stack_b);

//     // rra | rrb
//     ft_printf("stack_a: \n");
//     reverse_rotate_a(&stack_a);
//     printnl(stack_a);

//     push_b(&stack_a, &stack_b);
//     ft_printf("stack_b: \n");
//     reverse_rotate_b(&stack_a);
//     printnl(stack_b);
// }

