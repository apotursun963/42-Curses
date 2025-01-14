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

// ARG=$(shuf -i 1-2000000 -n 100); ./push_swap $ARG | wc -l

// void    sort_three_numbers_in_a(t_stack **stack_a, t_stack **stack_b, int len)
// {
//     (void)stack_b;
//     if (len == 2)
//     {
//         if ((*stack_a)->data > (*stack_a)->next->data)
//             swap_a(stack_a);
//     }
//     else if (len == 3)
//         sort_stack_if_size_3(stack_a);
// }

// int    sort_three_numbers_in_b(t_stack **stack_a, t_stack **stack_b, int len)
// {
//     if (len == 1)
//         push_a(stack_b, stack_a);
//     else if (len == 2)
//     {
//         if ((*stack_b)->data < (*stack_b)->next->data)
//             swap_b(stack_b);
//         while (len--)
//             push_a(stack_b, stack_a);
//     }
// 	else if (len == 3)
// 		sort_stack_if_size_3(stack_b);
// 	return (0);
// }


void    sort_three_numbers_in_a(t_stack **stack_a, t_stack **stack_b, int len)
{
    if (len == 3 && stack_size(*stack_a) == 3)
        sort_stack_if_size_3(stack_a);
    else if (len == 2)
    {
        if ((*stack_a)->data > (*stack_a)->next->data)
            swap_a(stack_a);
    }
    else if (len == 3)
    {
        while (len != 3 || !((*stack_a)->data < (*stack_a)->next->data && (*stack_a)->next->data < (*stack_a)->next->next->data))
        {
            if (len == 3 && (*stack_a)->data > (*stack_a)->next->data && (*stack_a)->next->next->data)
                swap_a(stack_a);
            else if (len == 3 && !((*stack_a)->next->next->data > (*stack_a)->data && (*stack_a)->next->next->data > (*stack_a)->next->data))
                len = push_type(stack_a, stack_b, len, 0);
            else if ((*stack_a)->data > (*stack_a)->next->data)
                swap_a(stack_a);
            else if (len++)
                push_a(stack_b, stack_a);
        }
    }
}

int    sort_three_numbers_in_b(t_stack **stack_a, t_stack **stack_b, int len)
{
    if (len == 1)
        push_a(stack_b, stack_a);
    else if (len == 2)
    {
        if ((*stack_b)->data < (*stack_b)->next->data)
            swap_b(stack_b);
        while (len--)
            push_a(stack_b, stack_a);
    }
	else if (len == 3)
	{
		while (len || !((*stack_a)->data < (*stack_a)->next->data && (*stack_a)->next->data < (*stack_a)->next->next->data))
		{
			if (len == 1 && (*stack_a)->data > (*stack_a)->next->data)
				swap_a(stack_a);
			else if (len == 1 || (len >= 2 && (*stack_b)->data > (*stack_b)->next->data)
				|| (len == 3 && (*stack_b)->data > (*stack_b)->next->next->data))
				len = push_type(stack_a, stack_b, len, 1);
			else
				swap_b(stack_b);
		}
	}
	return (0);
}

int quick_sort_b(t_stack **stack_a, t_stack **stack_b, int len)
{
    int pivot;
    int numbers;

    if (is_stack_sorted(*stack_b, 1))
    {
        while (len--)
            push_a(stack_b, stack_a);
    }
    if (len <= 3)
        return (sort_three_numbers_in_b(stack_a, stack_b, len), 1);
    numbers = len;
    pivot = median(stack_b, stack_size(*stack_b));
    while (len > numbers / 2)
    {
        if ((*stack_b)->data >= pivot && len--)
            push_a(stack_b, stack_a);
        else
            rotate_b(stack_b);
    }
    while (stack_size(*stack_b) < numbers / 2)
        reverse_rotate_b(stack_b);
    quick_sort_a(stack_a, stack_b, numbers / 2 + numbers % 2);
    quick_sort_b(stack_a, stack_b, numbers / 2);
    return 1;
}

int quick_sort_a(t_stack **stack_a, t_stack **stack_b, int len)
{
    int pivot;
    int numbers;
    int half_numbers;

    if (is_stack_sorted(*stack_a, 0))
        return 1;
    numbers  = len;
    half_numbers = numbers / 2 + numbers % 2;
    if (len <= 3)
        return (sort_three_numbers_in_a(stack_a, stack_b, len), 1);
    pivot = median(stack_a, stack_size(*stack_a));
    while (len > half_numbers)
    {
        if ((*stack_a)->data < pivot && len--)
            push_b(stack_a, stack_b);
        else
            rotate_a(stack_a);
    }
    while (stack_size(*stack_a) < half_numbers)
        reverse_rotate_a(stack_a);
    quick_sort_a(stack_a, stack_b, half_numbers);
    quick_sort_b(stack_a, stack_b, numbers / 2);
    return 1;
}

int sorting(t_stack **stack_a, t_stack **stack_b)
{
    int size = stack_size(*stack_a);
    
    if (size == 2)
        swap_a(stack_a);
    else if (size == 3)
        sort_stack_if_size_3(stack_a);
    else
        quick_sort_a(stack_a, stack_b, size);
    if (!is_stack_sorted(*stack_a, 0))
        last_sort(stack_a, stack_b);
    return (1);
}
