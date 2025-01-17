/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:51:01 by atursun           #+#    #+#             */
/*   Updated: 2025/01/17 17:54:18 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "../libraries/libft/libft.h"
# include "../libraries/ft_printf/ft_printf.h"

# define STACK_A 1
# define STACK_B 0
# define INCREMENT 1
# define DESCREMENT 0

typedef struct s_stack
{
	int					data;
	struct s_stack		*next;
}	t_stack;

typedef enum e_layout
{
	ASCENDING,
	DESCENDING,
}	t_layout;

int			quick_sort_a(t_stack **stack_a, t_stack **stack_b, int len);
int			quick_sort_b(t_stack **stack_a, t_stack **stack_b, int len);
void		sort_under_three_in_a(t_stack **stack_a, t_stack **stack_b, int len);
void		sort_under_three_in_b(t_stack **stack_a, t_stack **stack_b, int len);
void		sort_stack_if_size_3(t_stack **stack_a);

void		bubble_sort(int *numbers, int size);
int			median(t_stack **stack, int len);

void		error_handling(void);
int			is_digit(char **str);
int			max_limit(char **str);
int			is_twin(char **str);

long		ft_atol(const char *str);
int			is_stack_sorted(t_stack *stack_a, t_layout order);
int			stack_size(t_stack *stack);
void    	push_type(t_stack **stack_a, t_stack **stack_b, int *len, int type, int sign);

void		free_args(char **arguments);
void		free_all_stack(t_stack **stack_a, t_stack **stack_b);

char		**parse_args(int argc, char **argv);
void		push_to_stack(t_stack **stack_a, int value);
void		fill_stack(t_stack **stack_a, char **arguments);

#endif
