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

# include "../inc/push_swap.h"

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
        if (str[i][j] == '-' || str[i][j] == '+')
            j++;
        while (str[i][j])
        {
            if (!ft_isdigit(str[i][j]))
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

    i = 0;
    while (str[i])
    {
        j = i + 1;
        while (str[j])
        {
            if (ft_atoi(str[i]) == ft_atoi(str[j]))
                return (free_args(str), -1);
            j++;
        }
        i++;
    }
    return (0);
}
