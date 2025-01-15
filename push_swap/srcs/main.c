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

# include "../inc/push_swap.h"

void    printnl(t_stack *stack)
{
    while (stack)
    {
        ft_printf("%d ", stack->data);
        stack = stack->next;
    }
    ft_printf("\n");
}

int     is_stack_sorted(t_stack *stack_a, int order)    // order makro olsun
{
    while (stack_a->next)
    {
        if ((order == 0 && stack_a->data > stack_a->next->data)
            || (order == 1 && stack_a->data < stack_a->next->data))
            return (0);
        stack_a = stack_a->next;
    }
    return (1);
}

char    **parse_args(int argc, char **argv)
{
    char    **args;
    char    *merge;
    char    *tmp;
    char    *tmp2;
    int     idx;

    idx = 1;
    merge = NULL;
    while (idx < argc)
    {
        tmp = merge;
        if (merge == NULL)
            merge = ft_strdup(argv[idx]);
        else
        {
            merge = ft_strjoin(merge, " ");
            tmp2 = merge;
            merge = ft_strjoin(merge, argv[idx]);
            free(tmp2);
        }
        idx++;
        free(tmp);
    }
    args = ft_split(merge, ' ');
    return (free(merge), args);
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

void inspect_args(char **args, int (*max_limit)(char **), int (*is_digit)(char **), int (*is_twin)(char **))
{
    if (max_limit(args) == -1 || is_digit(args) == -1 || is_twin(args) == -1)
        error_handling();
}

int main(int argc, char **argv)
{
    char        **args;
    t_stack     **stack_a;
    t_stack     **stack_b;

    if (argc < 2)
        return (0);
    args = parse_args(argc, argv);
    inspect_args(args, max_limit, is_digit, is_twin);
    stack_a = (t_stack **)malloc(sizeof(t_stack));
    stack_b = (t_stack **)malloc(sizeof(t_stack));
    if (!stack_a || !stack_b)
        return (free_all_stack(stack_a, stack_b), free_args(args), 0);
    *stack_a = NULL;
    *stack_b = NULL;
    fill_stack(stack_a, args);
    if (is_stack_sorted(*stack_a, 0))
        return (free_all_stack(stack_a, stack_b), free_args(args), 0);
    sorting(stack_a, stack_b);
    return (free_all_stack(stack_a, stack_b), free_args(args), 0);
}

/*
proje bittikten sonra github'a kodu düzelterek ekstra özellikler ekleyerek pushla
HANDLE_ERROR, makro...
*/
