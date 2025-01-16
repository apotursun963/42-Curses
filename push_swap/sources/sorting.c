/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:09:26 by atursun           #+#    #+#             */
/*   Updated: 2025/01/03 12:09:26 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"
# include "../include/actions.h"

// ARG=$(shuf -i 1-2000000 -n 100); ./push_swap $ARG | wc -l

void    sort_stack_if_size_3(t_stack **stack_a)
{
    int first;
    int second;
    int third;

    first = (*stack_a)->data;
    second = (*stack_a)->next->data;
    third = (*stack_a)->next->next->data;
    if (first > second && second > third && first > third)
    {
        action(stack_a, NULL, SWAP_A);
        action(stack_a, NULL, REVERSE_ROTATE_A);
    }
    else if (first < second && second > third && first < third)
    {
        action(stack_a, NULL, SWAP_A);
        action(stack_a, NULL, ROTATE_A);
    }
    else if (first > second && second < third && first > third)
        action(stack_a, NULL, ROTATE_A);
    else if (first < second && second > third && first > third)
        action(stack_a, NULL, REVERSE_ROTATE_A);
    else if (first > second && second < third && first < third)
        action(stack_a, NULL, SWAP_A);
}

void    sort_under_three_in_a(t_stack **stack_a, t_stack **stack_b, int len)
{
    (void)stack_b;
    if (len == 3 && stack_size(*stack_a) == 3)
        sort_stack_if_size_3(stack_a);
    else if (len == 2)
    {
        if ((*stack_a)->data > (*stack_a)->next->data)
            action(stack_a, NULL, SWAP_A);
    }   // bu koşulu kaldırabilirsin
    // else if (len == 3)
    // {
    //     while (len != 3 || !((*stack_a)->data < (*stack_a)->next->data 
    //             && (*stack_a)->next->data < (*stack_a)->next->next->data))
    //     {
    //         if (len == 3 && (*stack_a)->data > (*stack_a)->next->data 
    //                 && (*stack_a)->next->next->data)
    //             action(stack_a, NULL, SWAP_A);
    //         else if (len == 3 && !((*stack_a)->next->next->data > (*stack_a)->data 
    //                 && (*stack_a)->next->next->data > (*stack_a)->next->data))
    //         {
    //             action(stack_a, stack_b, PUSH_B);
    //             len--;
    //         }
    //         else if ((*stack_a)->data > (*stack_a)->next->data)
    //             action(stack_a, NULL, SWAP_A);
    //         else if (len++)
    //             action(stack_a, stack_b, PUSH_A);
    //     }
    // }
}

void    sort_under_three_in_b(t_stack **stack_a, t_stack **stack_b, int len)
{
    if (len == 1)
        action(stack_a, stack_b, PUSH_A);
    else if (len == 2)
    {
        if ((*stack_b)->data < (*stack_b)->next->data)
            action(stack_a, stack_b, SWAP_B);
        while (len--)
            action(stack_a, stack_b, PUSH_A);
    }
	else if (len == 3)
	{
		while (len || !((*stack_a)->data < (*stack_a)->next->data 
                && (*stack_a)->next->data < (*stack_a)->next->next->data))
		{
			if (len == 1 && (*stack_a)->data > (*stack_a)->next->data)
				action(stack_a, NULL, SWAP_A);
			else if (len == 1 || (len >= 2 && (*stack_b)->data > (*stack_b)->next->data)
				    || (len == 3 && (*stack_b)->data > (*stack_b)->next->next->data))
            {
                action(stack_a, stack_b, PUSH_A);
                len--;
            }
			else
				action(NULL, stack_b, SWAP_B);
		}
	}
}


 /*en  gelişmiş */
int quick_sort_b(t_stack **stack_a, t_stack **stack_b, int len)
{
    int pivot;
    int total_elements = len;
    int rotations = 0;

    if (is_stack_sorted(*stack_b, DESCENDING))
    {
        while (len--)
            action(stack_a, stack_b, PUSH_A);
        return (1);
    }
    if (len <= 3)
        return (sort_under_three_in_b(stack_a, stack_b, len), 1);
    pivot = median(stack_b, len);
    while (len > total_elements / 2)
    {
        if ((*stack_b)->data >= pivot)
        {
            action(stack_a, stack_b, PUSH_A);
            len--;
        }
        else
        {
            if (!is_stack_sorted(*stack_b, DESCENDING))
            {
                action(NULL, stack_b, ROTATE_B);
                rotations++;
            }
        }
    }
    while (total_elements / 2 < stack_size(*stack_b) && rotations--)
        action(NULL, stack_b, REVERSE_ROTATE_B);
    quick_sort_a(stack_a, stack_b, total_elements / 2 + total_elements % 2);
    quick_sort_b(stack_a, stack_b, total_elements / 2);
    return (1);
}

int quick_sort_a(t_stack **stack_a, t_stack **stack_b, int len)
{
    int pivot;
    int total_elements = len;
    int rotations = 0;

    if (is_stack_sorted(*stack_a, ASCENDING))
        return (1);
    if (len <= 3)
        return (sort_under_three_in_a(stack_a, stack_b, len), 1);
    pivot = median(stack_a, len);
    while (len > total_elements / 2 + total_elements % 2)
    {
        if ((*stack_a)->data < pivot)
        {
            action(stack_a, stack_b, PUSH_B);
            len--;
        }
        else
        {
            if (!is_stack_sorted(*stack_a, ASCENDING))
            {
                action(stack_a, NULL, ROTATE_A);
                rotations++;
            }
        }
    }
    while (total_elements / 2 + total_elements % 2 < stack_size(*stack_a) && rotations--)
        action(stack_a, NULL, REVERSE_ROTATE_A);
    quick_sort_a(stack_a, stack_b, total_elements / 2 + total_elements % 2);
    quick_sort_b(stack_a, stack_b, total_elements / 2);
    return (1);
}




// /*daha da gelişmiş */
// int quick_sort_b(t_stack **stack_a, t_stack **stack_b, int len)
// {
//     int pivot;
//     int total_elements = len;
//     int rotations = 0;

//     // Eğer stack_b sıralıysa tüm elemanları stack_a'ya taşı
//     if (is_stack_sorted(*stack_b, DESCENDING))
//     {
//         while (len--)
//             action(stack_a, stack_b, PUSH_A);
//         return (1);
//     }

//     // Küçük gruplar için farklı sıralama işlemi
//     if (len <= 3)
//     {
//         sort_under_three_in_b(stack_a, stack_b, len);
//         return (1);
//     }

//     // Pivot hesapla
//     pivot = median(stack_b, len);

//     // Elemanları pivot'a göre ayır
//     while (len > total_elements / 2)
//     {
//         if ((*stack_b)->data >= pivot)
//         {
//             action(stack_a, stack_b, PUSH_A);
//             len--;
//         }
//         else
//         {
//             action(NULL, stack_b, ROTATE_B);
//             rotations++;
//         }
//     }

//     // Döndürme işlemlerini geri al
//     while (total_elements / 2 < stack_size(*stack_b) && rotations--)
//         action(NULL, stack_b, REVERSE_ROTATE_B);

//     // Alt gruplar üzerinde rekürsif çağrılar
//     quick_sort_a(stack_a, stack_b, total_elements / 2 + total_elements % 2);
//     quick_sort_b(stack_a, stack_b, total_elements / 2);

//     return (1);
// }

// int quick_sort_a(t_stack **stack_a, t_stack **stack_b, int len)
// {
//     int pivot;
//     int total_elements = len;
//     int rotations = 0;

//     // Eğer stack_a sıralıysa işlem yapmadan dön
//     if (is_stack_sorted(*stack_a, ASCENDING))
//         return (1);

//     // Küçük gruplar için farklı sıralama işlemi
//     if (len <= 3)
//     {
//         sort_under_three_in_a(stack_a, stack_b, len);
//         return (1);
//     }

//     // Pivot hesapla
//     pivot = median(stack_a, len);

//     // Elemanları pivot'a göre ayır
//     while (len > total_elements / 2 + total_elements % 2)
//     {
//         if ((*stack_a)->data < pivot)
//         {
//             action(stack_a, stack_b, PUSH_B);
//             len--;
//         }
//         else
//         {
//             action(stack_a, NULL, ROTATE_A);
//             rotations++;
//         }
//     }

//     // Döndürme işlemlerini geri al
//     while (total_elements / 2 + total_elements % 2 < stack_size(*stack_a) && rotations--)
//         action(stack_a, NULL, REVERSE_ROTATE_A);

//     // Alt gruplar üzerinde rekürsif çağrılar
//     quick_sort_a(stack_a, stack_b, total_elements / 2 + total_elements % 2);
//     quick_sort_b(stack_a, stack_b, total_elements / 2);

//     return (1);
// }




// /*orta gelişmiş*/
// int quick_sort_b(t_stack **stack_a, t_stack **stack_b, int len)
// {
//     int pivot;
//     int numbers;
//     int rotated = 0;

//     if (is_stack_sorted(*stack_b, DESCENDING))
//     {
//         while (len--)
//             action(stack_a, stack_b, PUSH_A);
//         return (1);
//     }
//     numbers = len;
//     if (len <= 3)
//         return (sort_under_three_in_b(stack_a, stack_b, len), 1);
//     pivot = median(stack_b, len);
//     while (len > numbers / 2)
//     {
//         if ((*stack_b)->data >= pivot)
//         {
//             action(stack_a, stack_b, PUSH_A);
//             len--;
//         }
//         else
//         {
//             action(NULL, stack_b, ROTATE_B);
//             rotated++;
//         }
//     }
//     while (numbers / 2 < stack_size(*stack_b) && rotated--)
//         action(NULL, stack_b, REVERSE_ROTATE_B);
//     quick_sort_a(stack_a, stack_b, numbers / 2 + numbers % 2);
//     quick_sort_b(stack_a, stack_b, numbers / 2);
//     return (1);
// }

// int quick_sort_a(t_stack **stack_a, t_stack **stack_b, int len)
// {
//     int pivot;
//     int numbers;
//     int rotated = 0;

//     if (is_stack_sorted(*stack_a, ASCENDING))
//         return (1);
//     numbers = len;
//     if (len <= 3)
//         return (sort_under_three_in_a(stack_a, stack_b, len), 1);
//     pivot = median(stack_a, len);
//     while (len > numbers / 2 + numbers % 2)
//     {
//         if ((*stack_a)->data < pivot)
//         {
//             action(stack_a, stack_b, PUSH_B);
//             len--;
//         }
//         else
//         {
//             action(stack_a, NULL, ROTATE_A);
//             rotated++;
//         }
//     }
//     while (numbers / 2 + numbers % 2 < stack_size(*stack_a) && rotated--)
//         action(stack_a, NULL, REVERSE_ROTATE_A);
//     quick_sort_a(stack_a, stack_b, numbers / 2 + numbers % 2);
//     quick_sort_b(stack_a, stack_b, numbers / 2);
//     return (1);
// }




/* biraz gelişmiş  */
//  
// int quick_sort_b(t_stack **stack_a, t_stack **stack_b, int len)
// {
//     int pivot;
//     int pushed;
//     int i;

//     if (is_stack_sorted(*stack_b, DESCENDING))
//     {
//         i = 0;
//         while (i++ < len)
//             action(stack_a, stack_b, PUSH_A);
//         return (0);
//     }
//     if (len <= 3)
//         return (sort_under_three_in_b(stack_a, stack_b, len), 0);
//     pushed = 0;
//     pivot = median(stack_b, len);
//     i = 0;
//     while (i < len)
//     {
//         if ((*stack_b)->data >= pivot)
//         {
//             action(stack_a, stack_b, PUSH_A);
//             pushed++;
//         }
//         else
//             action(NULL, stack_b, ROTATE_B);
//         i++;
//     }
//     i = 0;
//     while (i < len - pushed)
//     {
//         action(NULL, stack_b, REVERSE_ROTATE_B);
//         i++;
//     }
//     quick_sort_a(stack_a, stack_b, pushed);
//     quick_sort_b(stack_a, stack_b, len - pushed);
//     return (0);
// }

// int quick_sort_a(t_stack **stack_a, t_stack **stack_b, int len)
// {
//     int pivot;
//     int pushed;
//     int i;

//     if (is_stack_sorted(*stack_a, ASCENDING))
//         return (0);
//     if (len <= 3)
//         return (sort_under_three_in_a(stack_a, stack_b, len), 0);
//     pushed = 0;
//     pivot = median(stack_a, len);
//     i = 0;
//     while (i < len)
//     {
//         if ((*stack_a)->data < pivot)
//         {
//             action(stack_a, stack_b, PUSH_B);
//             pushed++;
//         }
//         else
//             action(stack_a, NULL, ROTATE_A);
//         i++;
//     }
//     i = 0;
//     while (i < len - pushed)
//     {
//         action(stack_a, NULL, REVERSE_ROTATE_A);
//         i++;
//     }
//     quick_sort_a(stack_a, stack_b, len - pushed);
//     quick_sort_b(stack_a, stack_b, pushed);
//     return (0);
// }
