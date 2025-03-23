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

#include "../includes/push_swap.h"
#include "../includes/actions.h"

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

t_stack	**fill_stack(t_stack **stack_a, char **args)
{
	int		idx;
	int		value;
	t_stack	*node;
	t_stack	*current_node;

	idx = 0;
	while (args[idx])
	{
		value = ft_atoi(args[idx]);
		node = create_node(value);
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
	return (stack_a);
}

void	initialize_stacks(t_stack ***stack_a, t_stack ***stack_b)
{
	*stack_a = (t_stack **)malloc(sizeof(t_stack *));
	*stack_b = (t_stack **)malloc(sizeof(t_stack *));
	if (!(*stack_a) || !(*stack_b))
		exit(1);
	**stack_a = NULL;
	**stack_b = NULL;
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

	if (argc < 2)
		return (0);
	is_argv_null(argv);
	args = parse_args(argc, argv);
	inspect_args(args, &is_int_range, &is_digit, &is_twin);
	initialize_stacks(&stack_a, &stack_b);
	stack_a = fill_stack(stack_a, args);
	if (!is_stack_sorted(*stack_a, ASCENDING))
		sort_stack(stack_a, stack_b);
	free_all_stack(stack_a, stack_b);
	free_args(args);
	return (0);
}
