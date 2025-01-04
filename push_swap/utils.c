/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:53:56 by atursun           #+#    #+#             */
/*   Updated: 2025/01/03 20:04:11 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void    error_handling(void)
{
    ft_putendl_fd("Error", 2);
    exit(EXIT_FAILURE);
}

int is_digit(char **str)
{
    int i;
    int j;

    i = 0;
    while (str[i])
    {
        j = 0;
        while (str[i][j])
        {
            if (str[i][j] == '-')
                j++;
            if (str[i][j] < '0' || str[i][j] > '9')
                return (free_args(str), -1);
            j++;
        }
        i++;
    }
    return (0);
}

int max_limit(char **str)
{
    int i;
    long int num;

    i = 0;
    while (str[i])
    {
        num = ft_atol(str[i]);
        if (num < INT_MIN || num > INT_MAX)
            return (free_args(str), -1);
        i++;
    }
    return (0);
}

int is_twin(char **str)
{
    int i;
    int j;
    int len;
    int m, d;
    m = 0;
    d = 0;

    while (str[d])          // malloc için 
        m += ft_strlen(str[d++]);
    i = 0;
    int *nums = malloc(sizeof(int) * m);
    if (!nums)
        return (-1);
    len = 0;           
    while (str[i])          // libft'deki ft_memcpy veya benzeri fonksiyon kullanabilirsin.
    {
        nums[i] = ft_atol(str[i]);
        len++;
        i++;
    }
    i = 0;
    while (i < len)
    {
        j = i + 1;
        while (j < len + 1)
        {
            if (nums[i] == nums[j++])
                return (free_args(str), free(nums), -1);
        }
        i++;
    }
    return (free(nums), 0);
}

int     stack_size(t_stack *stack)
{
    int     counter;

    counter = 0;
    while (stack)
    {
        counter++;
        stack = stack->next;
    }
    return (counter);
}
