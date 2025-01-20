/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:04:34 by atursun           #+#    #+#             */
/*   Updated: 2025/01/17 17:50:15 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/actions.h"

char	**parse_args(int argc, char **argv)
{
	char	**args;
	char	*merge;
	char	*tmp;
	char	*tmp2;
	int		idx;

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

void	fill_stack(t_stack **stack_a, char **arguments)
{
	int		idx;
	t_stack	*node;
	t_stack	*current_node;

	idx = 0;
	while (arguments[idx])
	{
		node = create_node(ft_atoi(arguments[idx]));
		if (*stack_a == NULL)
			*stack_a = node;
		else
		{
			current_node = *stack_a;
			while (current_node->next)
				current_node = current_node->next;
			current_node->next = node;
		}
		idx++;
	}
}

void	inspect_args(char **args, int (*is_int_range)(char **),
	int (*is_digit)(char **), int (*is_twin)(char **))
{
	if (is_int_range(args) == -1 || is_digit(args) == -1 || is_twin(args) == -1)
		error_handling();
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	char	**args;
	int		size;

	is_valid_args(argc, argv);
	args = parse_args(argc, argv);
	inspect_args(args, is_int_range, is_digit, is_twin);
	stack_a = (t_stack **)malloc(sizeof(t_stack));
	stack_b = (t_stack **)malloc(sizeof(t_stack));
	*stack_a = NULL;
	*stack_b = NULL;
	fill_stack(stack_a, args);
	if (is_stack_sorted(*stack_a, ASCENDING))
		return (free_all_stack(stack_a, stack_b), free_args(args), 0);
	size = stack_size(*stack_a);
	if (size == 2)
		action(stack_a, NULL, SWAP_A);
	else if (size == 3)
		sort_stack_if_size_3(stack_a);
	else
		quick_sort_a(stack_a, stack_b, size);
	return (free_all_stack(stack_a, stack_b), free_args(args), 0);
}
