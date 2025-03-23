/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:39:29 by atursun           #+#    #+#             */
/*   Updated: 2025/01/17 17:32:53 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/actions.h"

void	free_args(char **arguments)
{
	int	idx;

	idx = 0;
	while (arguments[idx])
		free(arguments[idx++]);
	free(arguments);
}

void	free_all_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_node;

	while (*stack_a)
	{
		tmp_node = *stack_a;
		*stack_a = (*stack_a)->next;
		free(tmp_node);
	}
	while (*stack_b)
	{
		tmp_node = *stack_b;
		*stack_b = (*stack_b)->next;
		free(tmp_node);
	}
	free(stack_a);
	free(stack_b);
}
