/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:22:20 by atursun           #+#    #+#             */
/*   Updated: 2025/01/03 15:27:44 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/push_swap.h"

/* hata durumlarını kontrol et ör 2'den az yada NULL */
void    swap(t_stack **stack)
{
    t_stack  *first;
    t_stack  *second;

    if (stack_size(*stack) < 2)     // ft_lstsize() kullan
        return ;                    // return ; yapıtğın her yerde hata fonksiyonu gönder.
    first = *stack;
    second = (*stack)->next;

    first->next = second->next;
    second->next = first;
    *stack = second;
}

void    swap_a(t_stack **stack_a)
{
    swap(stack_a);
    ft_printf("sa\n");
}

void    swap_b(t_stack **stack_b)
{
    swap(stack_b);
    ft_printf("sb\n");
}

void    ss(t_stack **stack_a, t_stack **stack_b)
{
    swap(stack_a);
    swap(stack_b);
    ft_printf("ss\n");
}
