
#include "../include/push_swap.h"
#include "../include/actions.h"
#include "../include/checker.h"

void    apply_actions(t_stack **stack_a, t_stack **stack_b, char *command)
{
    if (ft_strncmp(command, "sa", 2) == 0)
        action(stack_a, NULL, SWAP_A, false);
    else if (ft_strncmp(command, "sb", 2) == 0)
        action(NULL, stack_b, SWAP_B, false);
    else if (ft_strncmp(command, "pa", 2) == 0)
        action(stack_a, stack_b, PUSH_A, false);
    else if (ft_strncmp(command, "pb", 2) == 0)
        action(stack_a, stack_b, PUSH_B, false);
    else if (ft_strncmp(command, "ra", 2) == 0)
        action(stack_a, NULL, ROTATE_A, false);
    else if (ft_strncmp(command, "rb", 2) == 0)
        action(NULL, stack_b, ROTATE_B, false);
    else if (ft_strncmp(command, "rra", 3) == 0)
        action(stack_a, NULL, REVERSE_ROTATE_A, false);
    else if (ft_strncmp(command, "rrb", 3) == 0)
        action(NULL, stack_b, REVERSE_ROTATE_B, false);
    else
        error_handling();
}

# include <stdio.h>
#include <string.h>
char    *get_input(int fd)
{
    char *input = NULL;
    size_t len = 0;

    if (fd == FROM_TERMINAL)
    {
        if (getline(&input, &len, stdin) == -1)
        {
            free(input);
            return NULL;
        }

        input[strcspn(input, "\n")] = '\0';
    }
    return (input);
}

void    take_actions(t_stack **stack_a, t_stack **stack_b)
{
    char    *action;

    while (1)
    {
        action = get_input(FROM_TERMINAL);
        if (!action)
            break ;
        apply_actions(stack_a, stack_b, action);
    }
    if (is_stack_sorted(*stack_a, ASCENDING))
        ft_printf("\033[1;32mOK\n", 10);
    else
        ft_printf("\033[1;31mKO\n", 10);
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	char	**args;

	is_valid_args(argc, argv);
	args = parse_args(argc, argv);
	inspect_args(args, is_int_range, is_digit, is_twin);
	stack_a = (t_stack **)malloc(sizeof(t_stack));
	stack_b = (t_stack **)malloc(sizeof(t_stack));
	*stack_a = NULL;
	*stack_b = NULL;
	fill_stack(stack_a, args);
    take_actions(stack_a, stack_b);
	return (free_all_stack(stack_a, stack_b), free_args(args), 0);
}
