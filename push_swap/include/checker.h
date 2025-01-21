#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include "actions.h"

# define BUFFER_SIZE	1
# define FROM_TERMINAL  0

char	*read_line(int fd);
char	*merge_with_previous(char *str, char *buf);
int		pull_till_new_line(char **str, char **line);
void	take_actions(t_stack **stack_a, t_stack **stack_b, char **args);
int		apply_actions(t_stack **stack_a, t_stack **stack_b, char *command);

#endif