/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:22:57 by atursun           #+#    #+#             */
/*   Updated: 2025/01/19 19:01:33 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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

void	rotate_a(t_stack **stack_a, int write_action)
{
	rotate(stack_a);
	if (write_action == true)
		ft_printf("ra\n");
}

void	rotate_b(t_stack **stack_b, int write_action)
{
	rotate(stack_b);
	if (write_action == true)
		ft_printf("rb\n");
}
