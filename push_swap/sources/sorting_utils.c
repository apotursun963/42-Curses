

# include "../include/push_swap.h"

/*bubble sort olarak ismini değiştir*/
void    bubble_sort(int *numbers, int size)
{
    int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers[i] > numbers[j])
			{
				tmp = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int median(t_stack **stack, int len)
{
    int i;
    int *arr;
    int median;
    t_stack *tmp;

    i = -1;
    tmp = *stack;
    arr = (int *)malloc(len * sizeof(int));
    while (++i < len)
    {
        arr[i] = tmp->data;
        tmp = tmp->next;
    }
    bubble_sort(arr, len);
    median = arr[len / 2];
    return (free(arr), median);
}
