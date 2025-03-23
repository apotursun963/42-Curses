/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:36:26 by atursun           #+#    #+#             */
/*   Updated: 2025/01/17 17:58:56 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/actions.h"

void	temp_sort(int *arr, int size)
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
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	median(t_stack **stack, int len)
{
	t_stack	*tmp;
	int		i;
	int		*arr;
	int		median;

	i = -1;
	tmp = *stack;
	arr = (int *)malloc(len * sizeof(int));
	while (++i < len)
	{
		arr[i] = tmp->data;
		tmp = tmp->next;
	}
	temp_sort(arr, len);
	median = arr[len / 2];
	return (free(arr), median);
}

int	find_min_value(t_stack **stack_a)
{
	int		min_value;
	int		min_pos;
	int		pos;
	t_stack	*node;

	pos = 0;
	min_pos = 0;
	node = *stack_a;
	min_value = node->data;
	while (node)
	{
		if (node->data < min_value)
		{
			min_value = node->data;
			min_pos = pos;
		}
		node = node->next;
		pos++;
	}
	return (min_pos);
}

void	rotate_min_to_head(t_stack **stack_a, int min_pos)
{
	int	size;

	size = stack_size(*stack_a);
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			action(stack_a, NULL, ROTATE_A);
	}
	else
	{
		min_pos = size - min_pos;
		while (min_pos-- > 0)
			action(stack_a, NULL, REVERSE_ROTATE_A);
	}
}
