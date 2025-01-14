/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:23:46 by atursun           #+#    #+#             */
/*   Updated: 2025/01/03 15:24:06 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/push_swap.h"


/* reverse rotate  */
void    reverse_rotate(t_stack **stack)
{
    t_stack  *first;
    t_stack  *last;
    t_stack  *prev;
    
    if (stack_size(*stack) == 0 || stack_size(*stack) == 1)
        return ;
    first = *stack;
    last = *stack;
    prev = NULL;

    while (last->next)
    {
        prev = last;        // (sondan bir önceki elemanı işaret eder).
        last = last->next;
    }    
    last->next = first;
    prev->next = NULL;
    *stack = last;
}

/*
a stackinin bütün elemanlarını bir aşağı kaydırın.
Son eleman artık ilk eleman olacaktır.
*/
void    reverse_rotate_a(t_stack **stack_a)
{
    reverse_rotate(stack_a);
    ft_printf("rra\n");
}

/*
b stackinin bütün elemanlarını bir aşağı kaydırın.
Son eleman artık ilk eleman olacaktır.
*/
void    reverse_rotate_b(t_stack **stack_b)
{
    reverse_rotate(stack_b);
    ft_printf("rrb\n");
}

void    rrr(t_stack **stack_a, t_stack **stack_b)
{
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
    ft_printf("rrr\n");
}
