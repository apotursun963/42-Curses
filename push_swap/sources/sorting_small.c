#include "../include/push_swap.h"
#include "../include/actions.h"

void	sort_stack_if_size_3(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->data;
	second = (*stack_a)->next->data;
	third = (*stack_a)->next->next->data;
	if (first > second && second > third && first > third)
	{
		action(stack_a, NULL, SWAP_A);
		action(stack_a, NULL, REVERSE_ROTATE_A);
	}
	else if (first < second && second > third && first < third)
	{
		action(stack_a, NULL, SWAP_A);
		action(stack_a, NULL, ROTATE_A);
	}
	else if (first > second && second < third && first > third)
		action(stack_a, NULL, ROTATE_A);
	else if (first < second && second > third && first > third)
		action(stack_a, NULL, REVERSE_ROTATE_A);
	else if (first > second && second < third && first < third)
		action(stack_a, NULL, SWAP_A);
}

void	sort_stack_if_size_4_or_5(t_stack **stack_a, t_stack **stack_b
	, int size)
{
	int	min_pos;
	int	i;

	i = -1;
	while (++i < size - 3)
	{
		min_pos = find_min_value(stack_a);
		rotate_min_to_head(stack_a, min_pos);
		action(stack_a, stack_b, PUSH_B);
	}
	sort_stack_if_size_3(stack_a);
	while (*stack_b)
		action(stack_a, stack_b, PUSH_A);
}
