/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:06:27 by atursun           #+#    #+#             */
/*   Updated: 2025/03/23 12:19:55 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/actions.h"

void	push(t_stack **src_stack, t_stack **dst_stack)
{
	t_stack	*head;

	if (stack_size(*src_stack) == 0)
		return ;
	head = *src_stack;
	*src_stack = head->next;
	head->next = *dst_stack;
	*dst_stack = head;
}

void	push_a(t_stack **stack_b, t_stack **stack_a)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}
