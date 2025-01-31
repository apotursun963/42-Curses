/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:33:11 by atursun           #+#    #+#             */
/*   Updated: 2024/11/04 12:33:11 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_chr(char chr)
{
	return (write(1, &chr, 1));
}

int	ft_write_str(char *str)
{
	int	size;

	if (!str)
		return (write(1, "(null)", 6));
	size = 0;
	while (*str)
		size += ft_write_chr(*str++);
	return (size);
}

int	ft_reverse_str(char *str_digit, int len_digit)
{
	int	size;

	size = 0;
	while (--len_digit >= 0)
		size += ft_write_chr(str_digit[len_digit]);
	return (size);
}
