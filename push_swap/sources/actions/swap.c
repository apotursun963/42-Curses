/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:22:20 by atursun           #+#    #+#             */
/*   Updated: 2025/03/23 12:20:07 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/actions.h"

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

void	swap_a(t_stack **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	swap_b(t_stack **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}
