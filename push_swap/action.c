
/*          tüm aksiyonların hata/hata durumlarını kontrol et */


# include "push_swap.h"
#include <stdio.h>

// void    printnl(t_list *stack)
// {
//     while (stack)
//     {
//         printf("%d\n", stack->data);
//         stack = stack->next;
//     }
//     // printf("\n");
// }

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

void    push(t_list **src_stack, t_list **dst_stack)
{
    t_list  *head;

    if (stack_size(*src_stack) == 0)
        return ;
    head = *src_stack;                // stack_b'nin ilk elemanını al
    *src_stack = head->next;          // stack_b'nin başını bir sonraki elemana kaydır
    head->next = *dst_stack;          // head_b'yi stack_a'nın başına ekle
    *dst_stack = head;                // stack_a'nın başını head_b olarak güncelle
}

void    push_a(t_list **stack_b, t_list **stack_a)
{
    push(stack_b, stack_a);
    printf("pa\n");
}

/*
a stackinin en üstündeki elemanı b stackinin en üstüne koyun.
Eğer a stacki boş ise bir şey yapmayın.
*/
void    push_b(t_list **stack_a, t_list **stack_b)
{
    push(stack_a, stack_b);
    printf("pb\n");
}


/* hata durumlarını kontrol et ör 2'den az yada NULL */
void    swap(t_list **stack)
{
    t_list  *first;
    t_list  *second;

    if (stack_size(*stack) < 2)     // ft_lstsize() kullan
        return ;                    // return ; yapıtğın her yerde hata fonksiyonu gönder.
    first = *stack;
    second = (*stack)->next;

    first->next = second->next;
    second->next = first;
    *stack = second;
}

void    swap_a(t_list **stack_a)
{
    swap(stack_a);
    printf("sa\n");
}

void    swap_b(t_list **stack_b)
{
    swap(stack_b);
    printf("sb\n");
}

void    ss(t_list **stack_a, t_list **stack_b)
{
    swap(stack_a);
    swap(stack_b);
    printf("ss\n");
}

/* rotate  */
void    rotate(t_list **stack)
{
    t_list  *first;
    t_list  *last;

    first = *stack;         // Listenin ilk elemanını al
    last = *stack;          // Listenin ilk elemanını al (son node için)
    
    while (last->next)
        last = last->next;
    
    last->next = first;     // Son elemanı ilk elemanla bağla
    *stack = first->next;   // Yeni baş (top) elemanını güncelle
    first->next = NULL;     // Eski baş elemanın son eleman olduğundan emin ol
}

/*
a stackinin bütün elemanlarını bir yukarı kaydırın.
İlk eleman artık son eleman olacaktır.
*/  
void    rotate_a(t_list **stack_a)
{
    rotate(stack_a);
    printf("ra\n");
}

/*
b stackinin bütün elemanlarını bir yukarı kaydırın.
İlk eleman artık son eleman olacaktır.
*/
void    rotate_b(t_list **stack_b)
{
    rotate(stack_b);
    printf("rb\n");
}

void    rr(t_list **stack_a, t_list **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    printf("rr\n");
}


/* reverse rotate  */
void    reverse_rotate(t_list **stack)
{
    t_list  *first;
    t_list  *last;
    t_list  *prev;

    first = *stack;
    last = *stack;
    prev = NULL;

    while (last->next)
    {
        prev = last;        // (sondan bir önceki elemanı işaret eder).
        last = last->next;
    }    
    last->next = first;
    prev->next = NULL;
    *stack = last;
}

/*
a stackinin bütün elemanlarını bir aşağı kaydırın.
Son eleman artık ilk eleman olacaktır.
*/
void    reverse_rotate_a(t_list **stack_a)
{
    reverse_rotate(stack_a);
    printf("rra\n");
}

/*
b stackinin bütün elemanlarını bir aşağı kaydırın.
Son eleman artık ilk eleman olacaktır.
*/
void    reverse_rotate_b(t_list **stack_b)
{
    reverse_rotate(stack_b);
    printf("rrb\n");
}

void    rrr(t_list **stack_a, t_list **stack_b)
{
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
    printf("rrr\n");
}

/*-----------------------------------------------*/


/*test push*/
// void    test_push(t_list **stack, int value)
// {
//     t_list  *new = (t_list *)malloc(sizeof(t_list));
//     if (!new) return ;

//     new->data = value;
//     new->next = *stack;
//     *stack = new;
// }

// // actions tester
// int main(int argc, char *argv[])
// {
//     t_list  *stack_a;
//     t_list  *stack_b;

//     // push to stack_a
//     test_push(&stack_a, 1);
//     test_push(&stack_a, 2);
//     test_push(&stack_a, 3);
//     test_push(&stack_a, 4);
//     test_push(&stack_a, 5);

//     // print stack_a
//     printf("stack_a: \n");
//     printnl(stack_a);

//     // sa
//     swap_a(&stack_a);
//     printnl(stack_a);

//     // pb
//     push_b(&stack_a, &stack_b);
//     push_b(&stack_a, &stack_b);
//     printnl(stack_a);
//     printf("stack_b: \n");
//     printnl(stack_b);

//     // ra | rb
//     printf("stack_a: \n");
//     rotate_a(&stack_a);
//     printnl(stack_a);

//     printf("stack_b: \n");
//     rotate_b(&stack_b);
//     printnl(stack_b);

//     // rra | rrb
//     printf("stack_a: \n");
//     reverse_rotate_a(&stack_a);
//     printnl(stack_a);

//     push_b(&stack_a, &stack_b);
//     printf("stack_b: \n");
//     reverse_rotate_b(&stack_a);
//     printnl(stack_b);
// }
