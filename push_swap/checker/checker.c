
# include "include/push_swap.h"
# include "include/actions.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0' && i)
		i++;
	return (str1[i] - str2[i]);
}


static int	verify_new_line(char **stack, char **line)
{
	char		*tmp_stack;
	char		*strchr_stack;
	int			i;

	i = 0;
	strchr_stack = *stack;
	while (strchr_stack[i] != '\n')
	{
		if (!strchr_stack[i++])
			return (0);
	}
	tmp_stack = &strchr_stack[i];
	*tmp_stack = '\0';
	*line = *stack;
	*stack = ft_strdup(tmp_stack + 1);
	return (1);
}

static void	add_heap_to_static(char **s, char *buf)
{
	char		*tmp;

	tmp = *s;
	if (!tmp)
		*s = ft_strdup(buf);
	else
	{
		*s = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
	}
}

static	int	ft_exit(char **line)
{
	*line = NULL;
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	static char	*s[MAX_FD];
	char		heap[BUFF_SIZE + 1];
	int			ret;

	if (!line || fd < 0 || fd >= MAX_FD || (read(fd, s[fd], 0) < 0))
		return (-1);
	ret = read(fd, heap, BUFF_SIZE);
	while (ret > 0)
	{
		heap[ret] = '\0';
		add_heap_to_static(&s[fd], heap);
		if (verify_new_line(&s[fd], line))
			return (1);
		ret = read(fd, heap, BUFF_SIZE);
	}
	if (!s[fd] || s[fd][0] == '\0')
		return (ft_exit(line));
	if (s[fd])
		if (verify_new_line(&(s[fd]), line))
			return (1);
	*line = ft_strdup(s[fd]);
	free(s[fd]);
	s[fd] = NULL;
	return (1);
}

int	apply_actions(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (!(ft_strcmp(line, "sa")))
	{
		action(stack_a, NULL, SWAP_A);
		return (0);
	}
	if (!(ft_strcmp(line, "sb")))
	{
		action(NULL, stack_b, SWAP_B);
		return (0);
	}
	if (!(ft_strcmp(line, "pa")))
	{
		action(stack_a, stack_b, PUSH_A);
		return (0);
	}
	if (!(ft_strcmp(line, "pb")))
	{
		action(stack_a, stack_b, PUSH_B);
		return (0);
	}
	if (!(ft_strcmp(line, "ra")))
	{
		action(stack_a, NULL, ROTATE_A);
		return (0);
	}
	if (!(ft_strcmp(line, "rb")))
	{
		action(NULL, stack_b, ROTATE_B);
		return (0);
	}
	if (!(ft_strcmp(line, "rra")))
	{
		action(stack_a, NULL, REVERSE_ROTATE_A);
		return (0);
	}
	if (!(ft_strcmp(line, "rrb")))
	{
		action(NULL, stack_b, REVERSE_ROTATE_B);
		return (0);
	}
	return (1);
}

void	print_checker_res(t_stack **stack_a, t_stack **stack_b)
{
	if (is_stack_sorted(*stack_a, ASCENDING))
		ft_putendl_fd("OK\n", 1);
	else
		ft_putendl_fd("KO\n", 1);
	free_all_stack(stack_a, stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	char	**args;
	char    *line;

    if (argc < 2)
        return (0);
	is_valid_args(argc, argv);
	args = parse_args(argc, argv);
	inspect_args(args, is_int_range, is_digit, is_twin);
	stack_a = (t_stack **)malloc(sizeof(t_stack));
	stack_b = (t_stack **)malloc(sizeof(t_stack));
	*stack_a = NULL;
	*stack_b = NULL;
	fill_stack(stack_a, args);
	while (get_next_line(0, &line))
	{
		if (apply_actions(line, stack_a, stack_b))
		{
			error_handling();
			return (-1);
		}
		free(line);
	}
	print_checker_res(stack_a, stack_b);
	return (0);
}
