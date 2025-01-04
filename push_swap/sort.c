/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:09:26 by atursun           #+#    #+#             */
/*   Updated: 2025/01/03 12:09:26 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void    Swap(t_stack *first, t_stack *second)
{
    int tmp = first->data;
    first->data = second->data;
    second->data = tmp;
}

void    selection_sort(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *first;
    t_stack *second;

    first = *stack_a;
    while (first)
    {
        second = first->next;
        while (second)
        {
            if (first->data > second->data)
                Swap(first, second);        // ama bu swap fonksiyonu sadece ilk iki elemanı takas eder her zaan
            second = second->next;
        }
        first = first->next;
    }
}

void    sort_stack(t_stack **stack_a, t_stack **stack_b)
{
    // printnl(*stack_a);

    selection_sort(stack_a, stack_b);

    // printnl(*stack_a);
}
