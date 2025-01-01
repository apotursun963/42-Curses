# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
    int             data;
    struct s_list   *next;
}   t_list;


char	**ft_split(char const *str, char c);
int	ft_atoi(const char *str);


void    printnl(t_list *stack); 
void    free_all_blocks(t_list **stack_a, t_list **stack_b, char **arguments, int argc);

// acts
void    push_a(t_list **stack_b, t_list **stack_a);
void    push_b(t_list **stack_a, t_list **stack_b);

void    swap_a(t_list **stack_a);
void    swap_b(t_list **stack_b);
void    ss(t_list **stack_a, t_list **stack_b);

void    rotate_a(t_list **stack_a);
void    rotate_b(t_list **stack_b);
void    rr(t_list **stack_a, t_list **stack_b);

void    reverse_rotate_a(t_list **stack_a);
void    reverse_rotate_b(t_list **stack_b);
void    rrr(t_list **stack_a, t_list **stack_b);

void    sort_2(t_list **stack_a, t_list **stack_b);
void    sort_stack(t_list **stack_a, t_list **stack_b);


int     stack_size(t_list *stack);
void    error_handling(void);