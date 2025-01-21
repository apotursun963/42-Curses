#include "../include/checker.h"

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
	int		value;
	t_stack	*node;
	t_stack	*current_node;

	idx = 0;
	while (arguments[idx])
	{
		value = ft_atoi(arguments[idx]);
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
}

void	inspect_args(char **args, int (*is_int_range)(char **),
	int (*is_digit)(char **), int (*is_twin)(char **))
{
	if (is_int_range(args) == -1 || is_digit(args) == -1 || is_twin(args) == -1)
		error_handling();
}
