/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:09:26 by atursun           #+#    #+#             */
/*   Updated: 2025/01/03 12:09:26 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/push_swap.h"

// int    find_min_value_pos(t_stack *node)
// {
//     int min_val;
//     int min_pos;
//     int pos;

//     pos = 0;
//     min_pos = 0;
//     min_val = node->data;
//     while (node)
//     {   
//         if (node->data < min_val)
//         {
//             min_val = node->data;
//             min_pos = pos;
//         }
//         node = node->next;
//         pos++;
//     }
//     return (min_pos);
// }

// void    rotate_min_pos_to_head(t_stack **stack_a, int min_pos)
// {
//     int size;

//     if (min_pos == 0)
//         return ;
//     size = stack_size(*stack_a);
//     if (min_pos <= size / 2)
//     {
//         while (min_pos-- > 0)
//             rotate_a(stack_a);
//     }
//     else
//     {
//         min_pos = size - min_pos;
//         while (min_pos-- > 0)
//             reverse_rotate_a(stack_a);
//     }
// }

// void    sort_stack_if_size_3(t_stack **stack_a)
// {
//     int first;
//     int second;
//     int third;

//     first = (*stack_a)->data;
//     second = (*stack_a)->next->data;
//     third = (*stack_a)->next->next->data;
//     if (first > second && second > third && first > third)
//     {
//         swap_a(stack_a);
//         reverse_rotate_a(stack_a);
//     }
//     else if (first < second && second > third && first < third)
//     {
//         swap_a(stack_a);
//         rotate_a(stack_a);
//     }
//     else if (first > second && second < third && first > third)
//         rotate_a(stack_a);
//     else if (first < second && second > third && first > third)
//         reverse_rotate_a(stack_a);
//     else if (first > second && second < third && first < third)
//         swap_a(stack_a);
// }

// void    transfer_all_from_b_to_a(t_stack **stack_a, t_stack **stack_b, int *pushed)
// {
//     while (*pushed > 0)
//     {
//         push_a(stack_b, stack_a);
//         (*pushed)--;
//     }
// }

// void sort_stacks(t_stack **stack_a, t_stack **stack_b)
// {
//     int min_pos;
//     int pushed;
//     int size;

//     pushed = 0;
//     size = stack_size(*stack_a);
//     while (size-- > 0)
//     {
//         if (size == 2 && (*stack_a)->data > (*stack_a)->next->data)
//             swap_a(stack_a);
//         else if (size == 3)
//             sort_stack_if_size_3(stack_a);
//         if (is_stack_sorted(*stack_a))
//             break;
//         min_pos = find_min_value_pos(*stack_a);
//         rotate_min_pos_to_head(stack_a, min_pos);
//         push_b(stack_a, stack_b);
//         pushed++;
//     }
//     transfer_all_from_b_to_a(stack_a, stack_b, &pushed);
// }

/*
test;
ARG=$(shuf -i 1-2000000 -n 100); ./push_swap $ARG | wc -l
*/

/*
Bubble sort algo
*/
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

int median(t_stack **stack_a, int size)
{
    int *tmp_stack;
    int pivot;
    int i;

    tmp_stack = (int *)malloc(sizeof(int) * size);
    if (!tmp_stack)
        return (0);
    i = 0;
    t_stack *node = *stack_a;
    while (node)
    {
        tmp_stack[i++] = node->data;
        node = node->next;
    }
    tmp_sort(tmp_stack, size);
    pivot = tmp_stack[size / 2];
    return (free(tmp_stack), pivot);
}

int sort_three_numbers(t_stack **stack_a)
{
    int first;
    int second;
    int third;

    first = (*stack_a)->data;
    second = (*stack_a)->next->data;
    third = (*stack_a)->next->next->data;
    if (first > second && second > third && first > third)
    {
        swap_a(stack_a);
        reverse_rotate_a(stack_a);
    }
    else if (first < second && second > third && first < third)
    {
        swap_a(stack_a);
        rotate_a(stack_a);
    }
    else if (first > second && second < third && first > third)
        rotate_a(stack_a);
    else if (first < second && second > third && first > third)
        reverse_rotate_a(stack_a);
    else if (first > second && second < third && first < third)
        swap_a(stack_a);
    return (0);
}

int quick_sort_b(t_stack **stack_a, t_stack **stack_b, int len, int rotated)
{
    int pivot;
    int numbers;

    if (len <= 1 || is_stack_sorted(*stack_b, 1))
    {
        while (len--)
            push_a(stack_b, stack_a);
        return 1;
    }
    numbers = len;
    pivot = median(stack_b, len);
    while (len > numbers / 2)
    {
        if ((*stack_b)->data >= pivot)
        {
            len--;
            push_a(stack_b, stack_a);
        }
        else
        {
            rotated++;
            rotate_b(stack_b);
        }
    }
    while (stack_size(*stack_b) < numbers / 2)      // yada len < 
    {
        rotated--;
        reverse_rotate_b(stack_b);
    }
    quick_sort_a(stack_a, stack_b, numbers / 2 + numbers % 2, 0);
    quick_sort_b(stack_a, stack_b, numbers / 2, 0);
    return 1;
}

int quick_sort_a(t_stack **stack_a, t_stack **stack_b, int len, int rotated)
{
    int pivot;
    int numbers;

    if (len <= 1 || is_stack_sorted(*stack_a, 0))
        return 1;
    numbers  = len;
    pivot = median(stack_a, len);
    while (len > numbers / 2 + numbers % 2)
    {
        if ((*stack_a)->data < pivot)
        {
            len--;
            push_b(stack_a, stack_b);
        }
        else
        {
            rotated++;
            rotate_a(stack_a);
        }
    }
    while (stack_size(*stack_a) < numbers / 2 + numbers % 2)
    {
        rotated--;
        reverse_rotate_a(stack_a);
    }
    quick_sort_a(stack_a, stack_b, numbers / 2 + numbers % 2, 0);
    quick_sort_b(stack_a, stack_b, numbers / 2, 0);
    return 1;
}

int sort(t_stack **stack_a, t_stack **stack_b)
{
    int size = stack_size(*stack_a);
    
    if (size == 2)
        swap_a(stack_a);
    else if (size == 3)
        sort_three_numbers(stack_a);
    else
        quick_sort_a(stack_a, stack_b, size, 0);
    return (1);
}
/*
./push_swap 4 1 6 54 79 55 22 5
*/