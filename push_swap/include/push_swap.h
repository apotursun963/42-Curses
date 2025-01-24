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

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "../libraries/libft/libft.h"
# include "../libraries/printf/ft_printf.h"

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

int			sort_stack(t_stack **stack_a, t_stack **stack_b);
void		quick_sort_a(t_stack **stack_a, t_stack **stack_b, int len);
void		quick_sort_b(t_stack **stack_a, t_stack **stack_b, int len, int i);
void		sort_stack_if_size_3(t_stack **stack_a);

void		temp_sort(int *numbers, int size);
int			median(t_stack **stack, int len);

void		error_handling(void);
int			is_argv_null(char **str);
int			is_int_range(char **str);
int			is_digit(char **str);
int			is_twin(char **str);

t_stack		*create_node(int value);
long		ft_atol(const char *str);
int			is_stack_sorted(t_stack *stack_a, t_layout order);
int			stack_size(t_stack *stack);

void		free_args(char **arguments);
void		free_all_stack(t_stack **stack_a, t_stack **stack_b);

char		**parse_args(int argc, char **argv);
t_stack		**fill_stack(t_stack **stack_a, char **args);
void		initialize_stacks(t_stack ***stack_a, t_stack ***stack_b);
void		inspect_args(char **args, int (*is_int_range)(char **),
				int (*is_digit)(char **), int (*is_twin)(char **));

void		sort_stack_if_size_4_or_5(t_stack **stack_a, t_stack **stack_b,
				int size);
void		rotate_min_to_head(t_stack **stack_a, int min_pos);
int			find_min_value(t_stack **stack_a);

#endif
