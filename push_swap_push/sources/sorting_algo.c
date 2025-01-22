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

#include "../include/push_swap.h"
#include "../include/actions.h"

// void	quick_sort_b(t_stack **stack_a, t_stack **stack_b, int len)
// {
// 	int	pivot;
// 	int	total;
// 	int	rotations;

// 	if (len <= 1 || is_stack_sorted(*stack_b, DESCENDING))
// 	{
// 		while (len--)
// 			action(stack_a, stack_b, PUSH_A);
// 		return ;
// 	}
// 	total = len;
// 	rotations = 0;
// 	pivot = median(stack_b, len);
// 	while (len > (total / 2))
// 	{
// 		if ((*stack_b)->data >= pivot)
// 			push_type(stack_a, stack_b, &len, STACK_A);
// 		else if (++rotations)
// 			action(NULL, stack_b, ROTATE_B);
// 	}
// 	while (stack_size(*stack_b) > (total / 2) && rotations--)
// 		action(NULL, stack_b, REVERSE_ROTATE_B);
// 	quick_sort_a(stack_a, stack_b, (total / 2 + total % 2));
// 	quick_sort_b(stack_a, stack_b, (total / 2));
// }

// void	quick_sort_a(t_stack **stack_a, t_stack **stack_b, int len)
// {
// 	int	pivot;
// 	int	total;
// 	int	rotations;

// 	if (len <= 1 || is_stack_sorted(*stack_a, ASCENDING))
// 		return ;
// 	total = len;
// 	rotations = 0;
// 	pivot = median(stack_a, len);
// 	while (len > (total / 2 + total % 2))
// 	{
// 		if ((*stack_a)->data < pivot)
// 			push_type(stack_a, stack_b, &len, STACK_B);
// 		else if (++rotations)
// 			action(stack_a, NULL, ROTATE_A);
// 	}
// 	while (stack_size(*stack_a) > (total / 2 + total % 2) && rotations--)
// 		action(stack_a, NULL, REVERSE_ROTATE_A);
// 	quick_sort_a(stack_a, stack_b, (total / 2 + total % 2));
// 	quick_sort_b(stack_a, stack_b, (total / 2));
// }


void	quick_sort_b(t_stack **stack_a, t_stack **stack_b, int len)
{
	int pivot;
	int pushed;
	int	rotated;
	int	i;

	if (len <= 1 || is_stack_sorted(*stack_b, DESCENDING))
	{
		while (len--)
			action(stack_a, stack_b, PUSH_A);
		return ;
	}
	i = 0;
	pushed = 0;
	rotated = 0;
	pivot = median(stack_b, len);
	while (i++ < len)
	{
		if ((*stack_b)->data >= pivot && ++pushed)
			action(stack_a, stack_b, PUSH_A);
		else if (++rotated)
			action(NULL, stack_b, ROTATE_B);
	}
	while (stack_size(*stack_b) > len && rotated--)
		action(NULL, stack_b, REVERSE_ROTATE_B);
	quick_sort_a(stack_a, stack_b, pushed);
	quick_sort_b(stack_a, stack_b, len - pushed);
}

void quick_sort_a(t_stack **stack_a, t_stack **stack_b, int len)
{
	int pivot;
	int pushed;
	int	rotated;
	int i;

	if (len <= 1 || is_stack_sorted(*stack_a, ASCENDING))
		return ;
	i = 0;
	pushed = 0;
	rotated = 0;
	pivot = median(stack_a, len);
	while (i++ < len)
	{
		if ((*stack_a)->data < pivot && ++pushed)
			action(stack_a, stack_b, PUSH_B);
		else if (++rotated)
			action(stack_a, NULL, ROTATE_A);
	}
	while (stack_size(*stack_a) > len && rotated--)
		action(stack_a, NULL, REVERSE_ROTATE_A);
	quick_sort_a(stack_a, stack_b, len - pushed);
	quick_sort_b(stack_a, stack_b, pushed);
}
