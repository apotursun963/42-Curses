/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:33:34 by atursun           #+#    #+#             */
/*   Updated: 2024/11/04 13:32:48 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_hexa(unsigned int num, char type)
{
	char	*hexadecimal_low;
	char	*hexadecimal_up;
	char	hex_digits[32];
	int		left;
	int		idx;

	if (!num)
		return (ft_write_chr('0'));
	idx = 0;
	left = 0;
	hexadecimal_up = "0123456789ABCDEF";
	hexadecimal_low = "0123456789abcdef";
	while (num > 0)
	{
		left = num % 16;
		num = num / 16;
		if (type == 'X')
			hex_digits[idx] = hexadecimal_up[left];
		else
			hex_digits[idx] = hexadecimal_low[left];
		idx++;
	}
	return (ft_reverse_str(hex_digits, idx));
}

int	ft_base(unsigned long num)
{
	char	*hexadecimal_low;
	char	hex_digits[32];
	int		idx;

	if (!num)
		return (ft_write_chr('0'));
	idx = 0;
	hexadecimal_low = "0123456789abcdef";
	while (num > 0)
	{
		hex_digits[idx++] = hexadecimal_low[num % 16];
		num /= 16;
	}
	return (ft_reverse_str(hex_digits, idx));
}

int	ft_write_ptr(unsigned long num)
{
	int	size;

	size = 0;
	size += ft_write_str("0x");
	return (ft_base(num) + size);
}
