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

void	sort_a_under_three(t_stack **stack_a, t_stack **stack_b, int len)
{
	if (len == 2)
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
			action(stack_a, NULL, SWAP_A);
		return ;
	}
	else if (len == 3)
	{
		while (len != 3 || !is_stack_sorted(*stack_a, ASCENDING))
		{
			if ((len == 2 || len == 3)
				&& (*stack_a)->data > (*stack_a)->next->data)
				action(stack_a, NULL, SWAP_A);
			else if (!is_stack_sorted(*stack_a, ASCENDING))
				push_type(stack_a, stack_b, &len, STACK_B_DESCREMENT);
			else
				push_type(stack_a, stack_b, &len, STACK_A_INCREMENT);
		}
	}
}

void	sort_b_under_three(t_stack **stack_a, t_stack **stack_b, int len)
{
	if (len == 1)
		action(stack_a, stack_b, PUSH_A);
	else if (len == 2)
	{
		if ((*stack_b)->data < (*stack_b)->next->data)
			action(stack_a, stack_b, SWAP_B);
		action(stack_a, stack_b, PUSH_A);
		action(stack_a, stack_b, PUSH_A);
	}
	else if (len == 3)
	{
		while (len > 0)
		{
			if (len == 1)
			{
				if ((*stack_a)->data > (*stack_a)->next->data)
					action(stack_a, NULL, SWAP_A);
				push_type(stack_a, stack_b, &len, STACK_A_DESCREMENT);
			}
			else if ((*stack_b)->data < (*stack_b)->next->data)
				action(NULL, stack_b, SWAP_B);
			else
				push_type(stack_a, stack_b, &len, STACK_A_DESCREMENT);
		}
	}
}

void	quick_sort_b(t_stack **stack_a, t_stack **stack_b, int len)
{
	int	pivot;
	int	total;
	int	rotations;

	if (is_stack_sorted(*stack_b, DESCENDING))
	{
		while (len--)
			action(stack_a, stack_b, PUSH_A);
	}
	if (len <= 3)
		return (sort_b_under_three(stack_a, stack_b, len));
	total = len;
	rotations = 0;
	pivot = median(stack_b, len);
	while (len > (total / 2))
	{
		if ((*stack_b)->data >= pivot)
			push_type(stack_a, stack_b, &len, STACK_A_DESCREMENT);
		else if (++rotations)
			action(NULL, stack_b, ROTATE_B);
	}
	while (stack_size(*stack_b) > (total / 2) && rotations--)
		action(NULL, stack_b, REVERSE_ROTATE_B);
	quick_sort_a(stack_a, stack_b, (total / 2 + total % 2));
	quick_sort_b(stack_a, stack_b, (total / 2));
}

void	quick_sort_a(t_stack **stack_a, t_stack **stack_b, int len)
{
	int	pivot;
	int	total;
	int	rotations;

	if (is_stack_sorted(*stack_a, ASCENDING))
		return ;
	if (len <= 3)
		return (sort_a_under_three(stack_a, stack_b, len));
	total = len;
	rotations = 0;
	pivot = median(stack_a, len);
	while (len > (total / 2 + total % 2))
	{
		if ((*stack_a)->data < pivot)
			push_type(stack_a, stack_b, &len, STACK_B_DESCREMENT);
		else if (++rotations)
			action(stack_a, NULL, ROTATE_A);
	}
	while (stack_size(*stack_a) > (total / 2 + total % 2) && rotations--)
		action(stack_a, NULL, REVERSE_ROTATE_A);
	quick_sort_a(stack_a, stack_b, (total / 2 + total % 2));
	quick_sort_b(stack_a, stack_b, (total / 2));
}
