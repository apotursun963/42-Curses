/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:06:27 by atursun           #+#    #+#             */
/*   Updated: 2025/01/13 14:54:14 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/push_swap.h"

/*
b stackinin en üstündeki elemanı a stackinin en üstüne koyun.
Eğer b stacki boş ise bir şey yapmayın. */

void    push(t_stack **src_stack, t_stack **dst_stack)
{
    t_stack  *head;

    if (stack_size(*src_stack) == 0)
        return ;
    head = *src_stack;                // stack_b'nin ilk elemanını al   
    *src_stack = head->next;          // stack_b'nin başını bir sonraki elemana kaydır
    head->next = *dst_stack;          // head_b'yi stack_a'nın başına ekle
    *dst_stack = head;                // stack_a'nın başını head_b olarak güncelle
}

void    push_a(t_stack **stack_b, t_stack **stack_a)
{
    push(stack_b, stack_a);
    ft_printf("pa\n");
}

/*
a stackinin en üstündeki elemanı b stackinin en üstüne koyun.
Eğer a stacki boş ise bir şey yapmayın.
*/
void    push_b(t_stack **stack_a, t_stack **stack_b)
{
    push(stack_a, stack_b);
    ft_printf("pb\n");
}
