
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
char    **check_args(int argc, char **argv)
{
    char **args;

    if (argc == 2)
        args = ft_split(argv[1], ' ');
    else if (argc > 2)
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
    // is_twin(*stack_a);
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
void    free_all_blocks(t_list **stack_a, t_list **stack_b, char **arguments, int argc)
{
    t_list  *tmp_node;
    size_t  idx;

    while (*stack_a)
    {
        tmp_node = *stack_a;        // eğer .data yaparsan sorun alırsın çünkü data "int" türünde ama tmp "t_list *"
        *stack_a = (*stack_a)->next;
        free(tmp_node);
    }
    free(stack_a);
    free(stack_b);
    if (argc == 2)
    {
        idx = 0;
        while (arguments[idx])
            free(arguments[idx++]);
        free(arguments);
    }
}


int main(int argc, char **argv)
{
    char    **arguments;
    t_list  **stack_a;
    t_list  **stack_b;

    if (argc < 2)           // kaldır yada kaldırma iyice düşün
        return (0);
    arguments = check_args(argc, argv);
    stack_a = (t_list **)malloc(sizeof(t_list));
    stack_b = (t_list **)malloc(sizeof(t_list));
    *stack_a = NULL;
    *stack_b = NULL;
    fill_stack(stack_a, arguments, argc);
    if (is_stack_sorted(*stack_a))
        return (free_all_blocks(stack_a, stack_b, arguments, argc), 0);

    printnl(*stack_a);

    // sort_stack(stack_a, stack_b);
    // sort_2(stack_a, stack_b);

    free_all_blocks(stack_a, stack_b, arguments, argc);
    return (0);
}
