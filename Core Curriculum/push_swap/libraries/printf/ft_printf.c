/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:05:04 by atursun           #+#    #+#             */
/*   Updated: 2024/11/04 13:33:53 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		size;
	va_list	args;

	size = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
			size += ft_type(*++str, args);
		else
			size += ft_write_chr(*str);
		str++;
	}
	va_end(args);
	return (size);
}
