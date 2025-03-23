/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:22:57 by atursun           #+#    #+#             */
/*   Updated: 2025/03/23 12:20:03 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/actions.h"

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (stack_size(*stack) < 2)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	*stack = first->next;
	first->next = NULL;
}

void	rotate_a(t_stack **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rotate_b(t_stack **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}
