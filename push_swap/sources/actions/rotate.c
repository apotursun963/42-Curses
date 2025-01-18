/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:22:57 by atursun           #+#    #+#             */
/*   Updated: 2025/01/03 15:28:04 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/push_swap.h"

void    rotate(t_stack **stack)
{
    t_stack  *first;
    t_stack  *last;

    if (stack_size(*stack) == 0 || stack_size(*stack) == 1)
        return ;
    first = *stack;         // Stack'in ilk elemanını al
    last = *stack;          // Stack'in ilk elemanını al (son node için)
    
    while (last->next)
        last = last->next;
    
    last->next = first;     // Son elemanı ilk elemanla bağla
    *stack = first->next;   // Yeni baş (top) elemanını güncelle
    first->next = NULL;     // Eski baş elemanın son eleman olduğundan emin ol
}

/*
a stackinin bütün elemanlarını bir yukarı kaydırın.
İlk eleman artık son eleman olacaktır.
*/  
void    rotate_a(t_stack **stack_a)
{
    rotate(stack_a);
    ft_printf("ra\n");
}

/*
b stackinin bütün elemanlarını bir yukarı kaydırın.
İlk eleman artık son eleman olacaktır.
*/
void    rotate_b(t_stack **stack_b)
{
    rotate(stack_b);
    ft_printf("rb\n");
}

void    rr(t_stack **stack_a, t_stack **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    ft_printf("rr\n");
}
