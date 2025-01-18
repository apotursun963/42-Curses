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

#include "../include/push_swap.h"

void	bubble_sort(int *arr, int size)
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
	bubble_sort(arr, len);
	median = arr[len / 2];
	return (free(arr), median);
}
