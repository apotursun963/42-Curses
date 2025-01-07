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
        if (stack_a->data > stack_a->next->data)
            return (0);
        stack_a = stack_a->next;        
    }
    return (1);
}

char    **parse_args(int argc, char **argv, int idx)
{
    char    **args;
    char    *merge;
    char    *tmp;
    char    *tmp2;

    merge = NULL;
    while (idx < argc)
    {
        tmp = merge;
        if (merge == NULL)
            merge = ft_strdup(argv[idx]);               // ilk argümanı aldın
        else
        {
            merge = ft_strjoin(merge, " ");             // Argümanlar arasına boşluk ekle
            tmp2 = merge;
            merge = ft_strjoin(merge, argv[idx]);
            free(tmp2);
        }
        idx++;
        free(tmp);
    }
    args = ft_split(merge, ' ');
    free(merge);
    return (args);
}

void    push_to_stack(t_stack **stack_a, int value)
{
    t_stack *node;
    t_stack *tmp;

    node = (t_stack *)malloc(sizeof(t_stack));
    if (!node)
        return ;
    node->data = value;
    node->next = NULL;
    if (*stack_a == NULL)
        *stack_a = node;
    else
    {
        tmp = *stack_a;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = node;
    }
}

void fill_stack(t_stack  **stack_a, char **arguments)
{
    int idx;
    int val;

    idx = 0;
    while (arguments[idx])
    {
        val = ft_atoi(arguments[idx]);
        push_to_stack(stack_a, val);
        idx++;
    }
}

int main(int argc, char **argv)
{
    char        **arguments;
    t_stack     **stack_a;
    t_stack     **stack_b;

    if (argc < 2)
        return (0);
    arguments = parse_args(argc, argv, 1);
    if (max_limit(arguments) == -1 || is_digit(arguments) == -1 || is_twin(arguments) == -1)
        error_handling();
    stack_a = (t_stack **)malloc(sizeof(t_stack));
    stack_b = (t_stack **)malloc(sizeof(t_stack));
    if (!stack_a || !stack_b)
        return (free_all_stack(stack_a, stack_b), free_args(arguments), 0);
    *stack_a = NULL;
    *stack_b = NULL;
    fill_stack(stack_a, arguments);
    if (is_stack_sorted(*stack_a))
        return (free_all_stack(stack_a, stack_b), free_args(arguments), 0);
    sort_stack(stack_a, stack_b);
    return (free_all_stack(stack_a, stack_b), free_args(arguments), 0);
}
