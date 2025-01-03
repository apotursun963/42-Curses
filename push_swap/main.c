/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:04:34 by atursun           #+#    #+#             */
/*   Updated: 2025/01/03 12:04:34 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

/*
    1. İlk önce 'a' ve 'b' isimli iki tane stack tanımla ve başlangıç değerleri olarak 'NULL' ver - ok
    2. Terminalden gelen argümanları kontrol et (boş değerler, hatalı girişler) - ok
    3. Argümanları sayılara dönüştürüp ilk stack'e (`a` stack) yerleştir. -ok
    4. Stack'lerdeki Durumu Kontrol Et (Empty Check - Sorted Check - ok
    5. Stack a'daki değleri değerlendir işlemler yap . - ok
    6. push, swap, rotate, reverse_rotate aksiyonlarını ekle - ok
*/


void    printnl(t_stack *stack)
{
    while (stack)
    {
        ft_printf("%d ", stack->data);
        stack = stack->next;
    }
    ft_printf("\n");
}

int     is_stack_sorted(t_stack *stack_a)
{
    while (stack_a->next)
    {
        if (stack_a->data < stack_a->next->data)
            return (0);
        stack_a = stack_a->next;        
    }
    return (1);
}

char    **parse_args(int argc, char **argv)
{
    char **args;

    if (argc == 2)
        args = ft_split(argv[1], ' ');
    else
        args = argv;
    return (args);
}

void    push_stack_a(t_stack **stack_a, int value)
{
    t_stack  *node;

    node = (t_stack *)malloc(sizeof(t_stack));
    if (!node)
        return ;
    
    node->data = value;
    node->next = *stack_a;
    *stack_a = node;
}

void fill_stack(t_stack  **stack_a, char **arguments, int argc)
{
    int idx;
    long int val;

    if (argc == 2)
        idx = 0;
    else
        idx = 1;
    while (arguments[idx])
    {
        val = ft_atol(arguments[idx]);
        push_stack_a(stack_a, val);
        idx++;
    }
}
/*
argümanları kontrol et çoklu tırnak ("") 
*/
int main(int argc, char **argv)
{
    char        **arguments;
    t_stack     **stack_a;
    t_stack     **stack_b;

    if (argc < 2)
        return (0);
    arguments = parse_args(argc, argv);     // proje bittğinde check_args() ekleyebilirsin
    if (max_limit(arguments, argc) == -1 || is_digit(arguments, argc) == -1 || is_twin(arguments, argc) == -1)
        error_handling();
    stack_a = (t_stack **)malloc(sizeof(t_stack));
    stack_b = (t_stack **)malloc(sizeof(t_stack));
    if (!stack_a || !stack_b)       // dikkat et
        return (free_all_stack(stack_a, stack_b), free_args(arguments, argc), 0);
    *stack_a = NULL;
    *stack_b = NULL;
    fill_stack(stack_a, arguments, argc);
    if (is_stack_sorted(*stack_a))
        return (free_all_stack(stack_a, stack_b), free_args(arguments, argc), 0);

    // sort_stack(stack_a, stack_b);

    printnl(*stack_a);

    return (free_all_stack(stack_a, stack_b), free_args(arguments, argc), 0);
}
