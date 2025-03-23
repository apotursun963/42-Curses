/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:36:37 by atursun           #+#    #+#             */
/*   Updated: 2025/01/17 12:36:37 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/actions.h"

void	action(t_stack **stack_a, t_stack **stack_b, t_action action_type)
{
	if (action_type == SWAP_A)
		swap_a(stack_a);
	else if (action_type == SWAP_B)
		swap_b(stack_b);
	else if (action_type == PUSH_A)
		push_a(stack_b, stack_a);
	else if (action_type == PUSH_B)
		push_b(stack_a, stack_b);
	else if (action_type == ROTATE_A)
		rotate_a(stack_a);
	else if (action_type == ROTATE_B)
		rotate_b(stack_b);
	else if (action_type == REVERSE_ROTATE_A)
		reverse_rotate_a(stack_a);
	else if (action_type == REVERSE_ROTATE_B)
		reverse_rotate_b(stack_b);
}
