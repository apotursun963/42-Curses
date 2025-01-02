
/*
    1. İlk önce 'a' ve 'b' isimli iki tane stack tanımla ve başlangıç değerleri olarak 'NULL' ver - ok
    2. Terminalden gelen argümanları kontrol et (boş değerler, hatalı girişler) - ok
    3. Argümanları sayılara dönüştürüp ilk stack'e (`a` stack) yerleştir. -ok
    4. Stack'lerdeki Durumu Kontrol Et (Empty Check - Sorted Check)
    5. Stack a'daki değleri değerlendir işlemler yap .
    6. push, swap, rotate, reverse_rotate aksiyonlarını ekle
    7. 
*/



# include "push_swap.h"
#include <stdio.h>


void    printnl(t_list *stack)
{
    while (stack)
    {
        printf("%d\n", stack->data);
        stack = stack->next;
    }
    printf("\n");
}

/* ek özelliklerde ekle */
char    **parse_args(int argc, char **argv)
{
    char **args;

    if (argc == 2)
        args = ft_split(argv[1], ' ');
    else
        args = argv;
    return (args);
}

void    push_stack_a(t_list **stack_a, int value)
{
    t_list  *node;

    node = (t_list *)malloc(sizeof(t_list));
    if (!node)
        return ;
    
    node->data = value;
    node->next = *stack_a;
    *stack_a = node;
}

void    error_handling(void)
{
    printf("Error\n");          // ft_putendl() -> kullan çünkü standart output'a olmalı
    exit(1);
}

int is_twin(char **str, int argc)
{
    int i;
    int j;
    int num;
    int len;
    int *nums = malloc(sizeof(int) * argc);

    if (argc == 2)
        i = 0;
    else
        i = 1;
    len = 0;           
    while (str[i])      // libft'deki ft_memcpy veya benzeri fonksiyon kullan
    {
        nums[i] = ft_atoi(str[i]);
        len++;
        i++;
    }
    i = 0;
    while (i < len)
    {
        j = i + 1;
        while (j < len + 1)
        {
            if (nums[i] == nums[j++])
                return (free_args(str, argc), free(nums), -1);
        }
        i++;
    }
    return (free(nums), 0);
}

void    free_args(char **arguments, int argc)
{
    int  idx;

    if (argc == 2)
    {
        idx = 0;
        while (arguments[idx])
            free(arguments[idx++]);
        free(arguments);
    }
}

int is_digit(char **str, int ac)
{
    int i;
    int j;

    if (ac == 2)
        i = 0;
    else
        i = 1;
    while (str[i])
    {
        j = 0;
        while (str[i][j])
        {
            if (str[i][j] < '0' || str[i][j] > '9')
            {
                free_args(str, ac);
                return (-1);
            }
            j++;
        }
        i++;
    }
    return (0);
}

int max_limit(char **str, int ac)
{
    int i;
    int j;
    int num;

    i = 0;
    while (str[i])
    {
        num = ft_atoi(str[i]);
        if (num < 0)
        {
            free_args(str, ac);
            return (-1);
        }
        i++;
    }
    return (0);
}

void fill_stack(t_list  **stack_a, char **arguments, int argc)
{
    int idx;
    int val;

    if (argc == 2)
        idx = 0;
    else
        idx = 1;
    while (arguments[idx])
    {
        val = ft_atoi(arguments[idx]);
        push_stack_a(stack_a, val);
        idx++;
    }
}

int     is_stack_sorted(t_list *stack_a)
{
    while (stack_a->next)
    {
        if (stack_a->data < stack_a->next->data)
            return (0);
        stack_a = stack_a->next;        
    }
    return (1);
}


// Free kısmında güncellenecek stack_b içinde while ekliyceksin
void    free_all_stack(t_list **stack_a, t_list **stack_b)
{
    t_list  *tmp_node;

    while (*stack_a)
    {
        tmp_node = *stack_a;        // eğer .data yaparsan sorun alırsın çünkü data "int" türünde ama tmp "t_list *"
        *stack_a = (*stack_a)->next;
        free(tmp_node);
    }
    free(stack_a);
    free(stack_b);
}

int main(int argc, char **argv)
{
    char    **arguments;
    t_list  **stack_a;
    t_list  **stack_b;

    if (argc < 2)
        return (0);
    arguments = parse_args(argc, argv);     // proje bittğinde check_args() ekle
    if (is_digit(arguments, argc) == -1 || max_limit(arguments, argc) == -1 || is_twin(arguments, argc) == -1)
        error_handling();
    stack_a = (t_list **)malloc(sizeof(t_list));
    stack_b = (t_list **)malloc(sizeof(t_list));
    *stack_a = NULL;
    *stack_b = NULL;
    fill_stack(stack_a, arguments, argc);
    if (is_stack_sorted(*stack_a))
        return (free_all_stack(stack_a, stack_b), free_args(arguments, argc), 0);

    printnl(*stack_a);

    // sort_stack(stack_a, stack_b);
    // sort_2(stack_a, stack_b);

    return (free_all_stack(stack_a, stack_b), free_args(arguments, argc), 0);
}
