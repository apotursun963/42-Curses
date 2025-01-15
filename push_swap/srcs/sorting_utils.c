

# include "../inc/push_swap.h"

int    sort_stack_if_size_3(t_stack **stack)
{
    int first;
    int second;
    int third;

    first = (*stack)->data;
    second = (*stack)->next->data;
    third = (*stack)->next->next->data;
    if (first > second && second > third && first > third)
    {
        swap_a(stack);
        reverse_rotate_a(stack);
    }
    else if (first < second && second > third && first < third)
    {
        swap_a(stack);
        rotate_a(stack);
    }
    else if (first > second && second < third && first > third)
        rotate_a(stack);
    else if (first < second && second > third && first > third)
        reverse_rotate_a(stack);
    else if (first > second && second < third && first < third)
        swap_a(stack);
    return (1);
}

/*bubble sort*/
void    tmp_sort(int *numbers, int size)
{
    int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers[i] > numbers[j])
			{
				tmp = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int median(t_stack **stack, int size)
{
    int *tmp_stack;
    int pivot;
    int i;

    tmp_stack = (int *)malloc(sizeof(int) * size);
    if (!tmp_stack)
        return (0);
    i = 0;
    t_stack *node = *stack;
    while (node)
    {
        tmp_stack[i++] = node->data;
        node = node->next;
    }
    tmp_sort(tmp_stack, size);
    pivot = tmp_stack[size / 2];
    return (free(tmp_stack), pivot);
}

// sil
// int	push_type(t_stack **stack_a, t_stack **stack_b, int len, int push)
// {
// 	if (push == 0)
// 		push_b(stack_a, stack_b);
// 	else
// 		push_a(stack_b, stack_a);
// 	len--;
// 	return (len);
// }
