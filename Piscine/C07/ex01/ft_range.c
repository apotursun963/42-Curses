/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:57:54 by atursun           #+#    #+#             */
/*   Updated: 2024/02/10 15:22:57 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*nums;
	int	i;

	i = 0;
	if (min >= max)
		return (0);
	nums = (int *)malloc(sizeof(int) * (max - min));
	while (min < max)
	{
		nums[i] = min;
		min++;
		i++;
	}
	return (nums);
}
