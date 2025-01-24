/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:33:20 by atursun           #+#    #+#             */
/*   Updated: 2024/11/04 12:33:20 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_nbr(int num)
{
	char	digits[32];
	int		size;
	int		idx;

	idx = 0;
	size = 0;
	if (!num)
		return (ft_write_chr('0'));
	if (num == -2147483648)
		return (write(1, "-2147483648", 11));
	if (num < 0)
	{
		num *= -1;
		size += ft_write_chr('-');
	}
	while (num > 0)
	{
		digits[idx++] = (num % 10) + '0';
		num = num / 10;
	}
	return (ft_reverse_str(digits, idx) + size);
}

int	ft_write_nbr_u(unsigned int num)
{
	char	digits[32];
	int		idx;

	if (!num)
		return (ft_write_chr('0'));
	idx = 0;
	while (num > 0)
	{
		digits[idx++] = (num % 10) + '0';
		num = num / 10;
	}
	return (ft_reverse_str(digits, idx));
}
