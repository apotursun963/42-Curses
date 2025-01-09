


# include "../inc/push_swap.h"

long int	ft_atol(const char *str)
{
	long int		result;
	int		sign;

	sign = 1;
	result = 0;
	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = (result * 10) + (*str++ - '0');
	return (result * sign);
}

void    free_args(char **arguments)
{
    int  idx;

    idx = 0;
    while (arguments[idx])
        free(arguments[idx++]);
    free(arguments);
}

// Free kısmında güncellenecek stack_b içinde while ekliyceksin
void    free_all_stack(t_stack **stack_a, t_stack **stack_b)
{
    t_stack  *tmp_node;

    while (*stack_a)
    {
        tmp_node = *stack_a;        // eğer .data yaparsan sorun alırsın çünkü data "int" türünde ama tmp "t_stack *"
        *stack_a = (*stack_a)->next;
        free(tmp_node);
    }
    free(stack_a);
    free(stack_b);
}
