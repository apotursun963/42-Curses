/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:41:42 by atursun           #+#    #+#             */
/*   Updated: 2024/02/10 14:45:26 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*nums;
	int	index;

	if (min >= max)
		return (0);
	nums = (int *)malloc(sizeof(*nums) * (max - min));
	if (nums == NULL)
		return (0);
	index = 0;
	while (min < max)
	{
		nums[index] = min;
		index++;
		min++;
	}
	return (nums);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	*range = ft_range(min, max);
	if (*range == NULL)
		return (0);
	return (max - min);
}
