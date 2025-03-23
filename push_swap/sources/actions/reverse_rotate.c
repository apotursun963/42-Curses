/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:23:46 by atursun           #+#    #+#             */
/*   Updated: 2025/03/23 12:20:00 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/actions.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*prev;

	if (stack_size(*stack) < 2)
		return ;
	first = *stack;
	last = *stack;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	last->next = first;
	prev->next = NULL;
	*stack = last;
}

void	reverse_rotate_a(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}
