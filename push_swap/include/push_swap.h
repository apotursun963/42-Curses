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

typedef enum e_type
{
	STACK_A_INCREMENT,
	STACK_A_DESCREMENT,
	STACK_B_INCREMENT,
	STACK_B_DESCREMENT,
}	t_type;

void		quick_sort_a(t_stack **stack_a, t_stack **stack_b, int len);
void		quick_sort_b(t_stack **stack_a, t_stack **stack_b, int len);
void		sort_a_under_three(t_stack **stack_a, t_stack **stack_b, int len);
void		sort_b_under_three(t_stack **stack_a, t_stack **stack_b, int len);
void		sort_stack_if_size_3(t_stack **stack_a);

void		bubble_sort(int *numbers, int size);
int			median(t_stack **stack, int len);

void		error_handling(void);
int			is_valid_args(int argc, char **str);
int			is_int_range(char **str);
int			is_digit(char **str);
int			is_twin(char **str);

t_stack		*create_node(int value);
long		ft_atol(const char *str);
int			is_stack_sorted(t_stack *stack_a, t_layout order);
int			stack_size(t_stack *stack);
void		push_type(t_stack **stack_a, t_stack **stack_b,
				int *len, t_type which);

void		free_args(char **arguments);
void		free_all_stack(t_stack **stack_a, t_stack **stack_b);

char		**parse_args(int argc, char **argv);
void		fill_stack(t_stack **stack_a, char **arguments);
void		inspect_args(char **args, int (*is_int_range)(char **),
				int (*is_digit)(char **), int (*is_twin)(char **));

#endif
