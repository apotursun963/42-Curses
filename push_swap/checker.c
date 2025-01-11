

# include "inc/push_swap.h"

int     read_actions(char *line);
int     apply_actions(t_stack **stack_a, t_stack **stack_b, char *line);
int     write_result(t_stack **stack_a, t_stack **stack_b);


int main(int argc, char **argv)
{
    char        **arguments;
    t_stack     **stack_a;
    t_stack     **stack_b;
    char        *take_line;

    if (argc < 2)
        return (0);
    arguments = parse_args(argc, argv, 1);
    if (max_limit(arguments) == -1 || is_digit(arguments) == -1 || is_twin(arguments) == -1)
        error_handling();
    stack_a = (t_stack **)malloc(sizeof(t_stack));
    stack_b = (t_stack **)malloc(sizeof(t_stack));
    if (!stack_a || !stack_b)
        return (free_all_stack(stack_a, stack_b), free_args(arguments), 0);
    *stack_a = NULL;
    *stack_b = NULL;
    fill_stack(stack_a, arguments);
    while (read_actions(&take_line))
    {
        if (!apply_actions(stack_a, stack_b, take_line))
            error_handling();
    }
    write_result(stack_a, stack_b);
    return (0);
}
