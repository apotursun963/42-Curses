/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:33:34 by atursun           #+#    #+#             */
/*   Updated: 2024/11/03 14:29:25 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_write_hexa(unsigned int num, char type)
{
	char	hex_digits[32];
	int	left;
	int	idx;

	if (!num)
		return (ft_write_chr('0'));
	idx = 0;
	left = 0;
	while (num > 0)
	{
		left = num % HEXDB;
		num = num / HEXDB;
		if (type == 'X')
			hex_digits[idx] = HEXADECIMAL_UP[left];
		else
			hex_digits[idx] = HEXADECIMAL_LOW[left];
		idx++;
	}
	return (ft_reverse_str(hex_digits, idx));
}

int	ft_base(unsigned long num)
{
	char	hex_digits[32];
	int	idx;

	if (!num)
		return (ft_write_chr('0'));
	idx = 0;
	while (num > 0)
	{
		hex_digits[idx++] = HEXADECIMAL_LOW[num % HEXDB];
		num /= HEXDB;
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
