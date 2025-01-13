/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:51:01 by atursun           #+#    #+#             */
/*   Updated: 2025/01/03 11:51:01 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libs/libft/libft.h"
# include "../libs/ft_printf/ft_printf.h"

typedef struct s_stack
{
    int             data;
    struct s_stack   *next;
}   t_stack;


void    printnl(t_stack *stack);     // Bunu fonksiyonu push'larken siliceksin

// acts
void    push_a(t_stack **stack_b, t_stack **stack_a);
void    push_b(t_stack **stack_a, t_stack **stack_b);

void    swap_a(t_stack **stack_a);
void    swap_b(t_stack **stack_b);
void    ss(t_stack **stack_a, t_stack **stack_b);

void    rotate_a(t_stack **stack_a);
void    rotate_b(t_stack **stack_b);
void    rr(t_stack **stack_a, t_stack **stack_b);

void    reverse_rotate_a(t_stack **stack_a);
void    reverse_rotate_b(t_stack **stack_b);
void    rrr(t_stack **stack_a, t_stack **stack_b);

// sorting
void    sort_stacks(t_stack **stack_a, t_stack **stack_b);
int    find_min_value_pos(t_stack *node);
void    rotate_min_pos_to_head(t_stack **stack_a, int min_pos);
void    sort_stack_if_size_3(t_stack **stack_a);
void    transfer_all_from_b_to_a(t_stack **stack_a, t_stack **stack_b, int *pushed);


int     is_stack_sorted(t_stack *stack_a, int order);
int     stack_size(t_stack *stack);

// error funs
void    error_handling(void);
int     is_digit(char **str);
int     max_limit(char **str);
int     is_twin(char **str);


long int	ft_atol(const char *str);
void    free_args(char **arguments);
void    free_all_stack(t_stack **stack_a, t_stack **stack_b);

char    **parse_args(int argc, char **argv, int idx);
void    push_to_stack(t_stack **stack_a, int value);
void    fill_stack(t_stack  **stack_a, char **arguments);


int quick_sort_a(t_stack **stack_a, t_stack **stack_b, int len, int rotated);
int sort(t_stack **stack_a, t_stack **stack_b);