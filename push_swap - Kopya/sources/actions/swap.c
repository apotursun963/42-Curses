/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:22:20 by atursun           #+#    #+#             */
/*   Updated: 2025/01/19 19:02:12 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (stack_size(*stack) < 2)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	swap_a(t_stack **stack_a, int write_action)
{
	swap(stack_a);
	if (write_action == true)
		ft_printf("sa\n");
}

void	swap_b(t_stack **stack_b, int write_action)
{
	swap(stack_b);
	if (write_action == true)
		ft_printf("sb\n");
}
