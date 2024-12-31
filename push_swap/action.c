
# include "push_swap.h"
#include <stdio.h>

void    printnl(t_list *stack)
{
    while (stack)
    {
        printf("%d\n", stack->data);
        stack = stack->next;
    }
    // printf("\n");
}

int     stack_size(t_list *stack)
{
    int     counter;

    counter = 0;
    while (stack)
    {
        counter++;
        stack = stack->next;
    }
    return (counter);
}
/*
                                actionss
*/

/*  
b stackinin en üstündeki elemanı a stackinin en üstüne koyun.
Eğer b stacki boş ise bir şey yapmayın. */
void    push_a(t_list **stack_b, t_list **stack_a)
{
    t_list  *head_b;

    if (stack_size(*stack_b) == 0)
        return ;
    head_b = *stack_b;           // stack_b'nin ilk elemanını al
    *stack_b = head_b->next;     // stack_b'nin başını bir sonraki elemana kaydır
    head_b->next = *stack_a;     // head_b'yi stack_a'nın başına ekle
    *stack_a = head_b;           // stack_a'nın başını head_b olarak güncelle
    printf("pa\n");
}

/*
a stackinin en üstündeki elemanı b stackinin en üstüne koyun.
Eğer a stacki boş ise bir şey yapmayın.
*/
void    push_b(t_list **stack_a, t_list **stack_b)
{
    t_list  *head_a;

    if (stack_size(*stack_a) == 0)
        return ;
    head_a = *stack_a;
    *stack_a = head_a->next;
    head_a->next = *stack_b;
    *stack_b = head_a;
    printf("pb\n");
}


/* hata durumlarını kontrol et ör 2'den az yada NULL */
void    swap_a(t_list **stack_a)
{
    t_list  *first;
    t_list  *second;

    if (stack_size(*stack_a) < 2)
        return ;                        // return ; yapıtğın her yerde hata fonksiyonu gönder.
    first = *stack_a;
    second = (*stack_a)->next;

    first->next = second->next;
    second->next = first;
    *stack_a = second;
    printf("sa\n");
}

void    swap_b(t_list **stack_b)
{
    t_list  *first;
    t_list  *second;

    if (stack_size(*stack_b) < 2)
        return ;
    first = *stack_b;
    second = (*stack_b)->next;

    first->next = second->next;
    second->next = first;
    *stack_b = second;
    printf("sb\n");
}

void    ss(t_list **stack_a, t_list **stack_b)
{
    swap_a(stack_a);
    swap_a(stack_b);
    printf("ss\n");
}

/*
a stackinin bütün elemanlarını bir yukarı kaydırın.
İlk eleman artık son eleman olacaktır.
*/  
void    rotate_a(t_list **stack_a)
{
    t_list  *first;
    t_list  *last;

    first = *stack_a;           // Listenin ilk elemanını al
    last = *stack_a;            // Listenin ilk elemanını al (son node için)

    while (last->next)
        last = last->next;

    last->next = first;         // Son elemanı ilk elemanla bağla
    *stack_a = first->next;     // Yeni baş (top) elemanını güncelle
    first->next = NULL;         // Eski baş elemanın son eleman olduğundan emin ol
    printf("ra\n");
}

/*
b stackinin bütün elemanlarını bir yukarı kaydırın.
İlk eleman artık son eleman olacaktır.
*/
void    rotate_b(t_list **stack_b)
{
    t_list  *first;
    t_list  *last;

    first = *stack_b;
    last = *stack_b;

    while (last->next)
        last = last->next;

    last->next = first;
    *stack_b = first->next;
    first->next = NULL;
    printf("rb\n");
}

void    rr(t_list **stack_a, t_list **stack_b)
{
    rotate_a(stack_a);
    rotate_b(stack_b);
    printf("rr\n");
}


/*
a stackinin bütün elemanlarını bir aşağı kaydırın.
Son eleman artık ilk eleman olacaktır.
*/
void    reverse_rotate_a(t_list **stack_a)
{
    t_list  *first;
    t_list  *last;
    t_list  *prev;

    first = *stack_a;
    last = *stack_a;
    prev = NULL;

    while (last->next)        // libft'deki ft_lstlast fonksiyonu kullan
    {
        prev = last;          // (sondan bir önceki elemanı işaret eder).
        last = last->next;
    }              
    last->next = first;
    prev->next = NULL;
    *stack_a = last;
    printf("rra\n");
}

/*
b stackinin bütün elemanlarını bir aşağı kaydırın.
Son eleman artık ilk eleman olacaktır.
*/
void    reverse_rotate_b(t_list **stack_b)
{
    t_list  *first;
    t_list  *last;
    t_list  *prev;

    first = *stack_b;
    last = *stack_b;
    prev = NULL;

    while (last->next)
    {
        prev = last;
        last = last->next;
    }              
    last->next = first;
    prev->next = NULL;
    *stack_b = last;
    printf("rrb\n");
}

void    rrr(t_list **stack_a, t_list **stack_b)
{
    reverse_rotate_a(stack_a);
    reverse_rotate_a(stack_b);
    printf("rrr\n");
}

/*-----------------------------------------------*/


/*test push*/
void    push(t_list **stack, int value)
{
    t_list  *new = (t_list *)malloc(sizeof(t_list));
    if (!new) return ;

    new->data = value;
    new->next = *stack;
    *stack = new;
}


// actions tester
int main(int argc, char *argv[])
{
    t_list  *stack_a;
    t_list  *stack_b;

    push(&stack_a, 3);
    push(&stack_a, 5);
    push(&stack_a, 2);
    push(&stack_a, 8);
    push(&stack_a, 4);

    //  (swap)
    // printf("stack_a:\n");
    // printnl(stack_a);
    // printf("\n");
    // swap_a(&stack_a);
    // printnl(stack_a);

    //  (push)
    // printf("\n");
    // push_b(&stack_a, &stack_b);
    // printnl(stack_a);
    // printf("\n");
    // printf("stack_b:\n");
    // printnl(stack_b);

    //  (rotate)
    printnl(stack_a);
    // rotate_a(&stack_a);
    // printnl(stack_a);

    reverse_rotate_a(&stack_a);
    printnl(stack_a);

}
